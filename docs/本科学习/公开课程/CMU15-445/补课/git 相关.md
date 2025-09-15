
整理一下 git 相关的命令行用法

## 系统

这里并不算是 git 专用，而是类 unix 系统自带的一些命令。
### 当前目录

```bash
.
```

### 上一级目录

```bash
..
```

### 删除文件

顺带一提的是类 unix 系统里，`rm` 默认只能删除文件；如果想删文件夹，就得用 `-r` 的短选项。

### 系统可用的 CPU 核心数量

全称 number of processing units.

直接输入

```bash
nproc
```

会返回结果。

此外，还可以搭配着 `$()` 来使用，代表先执行括号里面的命令，然后把结果挪到这个位置。例如

```bash
make -j"$(nproc)"
```

### 创建文件夹

```bash
mkdir dirname
```



## 分支
### 查看本地分支

```bash
git branch
```

### 查看远程分支

```bash
git branch -r
```

这里的短选项应该是 remote 的缩写

### 同时查看本地和远程

```bash
git branch -a
```

## 回滚

```bash
git restore filename
```

这里可以把 `filename` 替换成 `.` 以及 `..`


