# win 下修改大小写导致 git 未追踪

一、根因一句话版

你在 Windows 上“只改了大小写”，但 Windows 文件系统不区分大小写，Git 也默认不把这当作改动；
而 GitHub Pages 的构建环境是 Linux，严格区分大小写，最终导致仓库里实际记录的路径与 MkDocs 期望的路径不一致。

二、第一层：Windows 文件系统的行为（问题起点）
Windows（NTFS / exFAT）默认是：

大小写不敏感

但 大小写保留

也就是说：

git/
Git/
GIT/


在 Windows 看来是 同一个目录

你做了什么：

原来目录叫 Git

你在资源管理器 / VS Code 里改成 git

Windows 认为：

“没变啊，还是那个目录”

所以：

文件正常

程序正常

你完全感知不到异常

三、第二层：Git 的行为（真正的坑点）
Git 的一个关键配置：
core.ignorecase = true   # Windows / macOS 默认


含义是：

如果 Git 认为底层文件系统不区分大小写，就忽略“仅大小写变化”的文件名修改

结果就是：

你把 Git → git

Git 认为“没发生重命名”

仓库里仍然记录的是 旧路径

你可以验证：

git status


👉 通常 不会显示任何改动

四、第三层：GitHub Pages / CI（爆炸现场）
GitHub Pages 构建环境：

Linux

ext4 文件系统

大小写严格敏感

当 GitHub Actions / Pages：

git clone 你的仓库

拿到的是 Git 记录的路径，比如：

docs/技能拾遗/Git/规范.md


MkDocs 在构建时，根据你的 mkdocs.yml：

技能拾遗/git/规范.md


Linux 上：

Git ≠ git


👉 MkDocs 找不到文件
👉 页面不生成
👉 最终访问 /技能拾遗/git/ 或其子页面 404

五、为什么本地 mkdocs serve 仍然没问题？

因为本地发生的是：

MkDocs → Windows FS → “git == Git” → 找得到文件


而线上是：

MkDocs → Linux FS → “git ≠ Git” → 文件不存在


这就是你看到的 “本地正常，线上炸” 的根本原因。

六、为什么偏偏 git 最容易踩这个坑？

几个现实原因叠加：

git 往往是你最早建的目录

早期随手建成 Git

后来统一风格想全小写

Windows + Git 默默吃掉了这次改名

等你上 CI / GitHub Pages 才一次性爆雷

七、为什么必须用 git mv 改两次？

因为你必须 强迫 Git 记录一次“真实重命名”

正确姿势（你已经知道，但这里解释“为什么”）
git mv docs/技能拾遗/git docs/技能拾遗/git_tmp
git commit -m "temp rename"

git mv docs/技能拾遗/git_tmp docs/技能拾遗/git
git commit -m "final rename"


中间态 git_tmp：

不只是大小写变化

Git 必须承认这是一次路径变更

Linux / Windows / GitHub Pages 全部同步

八、你现在这个仓库里“实际发生了什么”（高度还原）

极大概率是：

Git 记录中： docs/技能拾遗/Git/规范.md
你以为的： docs/技能拾遗/git/规范.md


两者在：

Windows：等价

Linux：完全不同

九、如何一劳永逸防止再踩
1️⃣ 立刻检查一次仓库真实路径
git ls-tree -r HEAD --name-only | sort


看是否存在：

Git/

git/

同名不同大小写目录

2️⃣ 统一命名规范（强烈建议）

所有目录：全小写

中文目录：允许

不在 Windows 上做“只改大小写”的操作

3️⃣ （可选）Git 层面防御

在 Windows 上：

git config core.ignorecase false


⚠️ 高级选项，只建议你已经理解这个坑后使用。