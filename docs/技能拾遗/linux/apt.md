# apt


apt 负责：从软件仓库获取软件信息、下载软件、安装/升级/卸载软件，并自动处理依赖关系。

你可以把它理解成 Linux 里的 “官方应用商店 + 安装器”，但用的是命令行。


你可以用 apt 做的常见事

```bash
apt search python        # 搜索软件
apt show python3         # 查看详情
apt list --installed     # 列出已安装软件
apt remove python3       # 卸载
```


