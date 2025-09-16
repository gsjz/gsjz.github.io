
整理一下 git 相关的命令行用法

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


