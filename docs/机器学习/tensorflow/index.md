# tensorflow

今天第一次在本地跑模型，寻思我 4080 的显卡跑 40 多分钟才跑了 6/20 个 epoch。

查了一下问题，发现是 tensorflow 在 `2.10` 之后居然不支持 windows 直接用 CUDA 了？？

然后尝试手动指定 tensorflow 的版本，发现 `import` 都不行。

又查了一下，发现我的 python 版本 `3.10` 刚好开始不兼容 `2.10` 的 tensorflow。

解决方案大概是要本地跑一个 linux 虚拟机。

todo: SSH