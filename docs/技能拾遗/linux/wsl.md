# wsl

曾经我想学 manim 的时候，看到建议是不使用 wsl。

如今我想学 tensorflow 的时候，看到建议是使用 wsl。

主要动机是，我需要使用显卡来加速 `tensorflow`。

在开始之前，在主机里尝试

```powershell
nvidia-smi
```

查看显卡状态。

## 安装

```powershell
wsl --install
```

接着安装 Ubuntu

```powershell
wsl --install -d Ubuntu
```

按提示设置一下用户名和密码。差不多就成功了

按套路 exit 就能从 wsl 里退回 powershell，以后想打开的时候 

```powershell
wsl -l -v
```

即可。

如果

```powershell
wsl -l -v
```

应该看到

```
Ubuntu    Running    2
```

## vscode 远程窗口

```
> remote: show remote menu
```

选择

```
wsl
```

会创建一个新窗口，左下角显示

```
WSL-Ubuntu
```

这时候在里面内建终端，就是在 wsl 系统上操作。

在 wsl 里

```bash
nvidia-smi
```

应该能看到显卡信息。

## 安装 miniconda

```bash
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
bash Miniconda3-latest-Linux-x86_64.sh
source ~/.bashrc
conda --version
```

剩余操作同理

## 新建文件夹

```
mkdir -p ~/projects/test
cd ~/projects/test
code .
```

这里路径自己想即可。

随后体验几乎就和 win 下的 vscode 体感一致了。

## ipykernel

疑似和 win 下体验不同的是 ipykernel 包

我们先检查一下

```bash
python - <<'EOF'
import sys, platform
print("executable:", sys.executable)
print("implementation:", platform.python_implementation())
EOF
```

结果 implementation 是 GraalVM。

这种情况就得重装环境了。

```bash
pip install jupyter notebook ipykernel
```

然后 reload window 即可。

