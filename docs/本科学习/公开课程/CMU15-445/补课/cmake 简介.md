proj0 的构建文档中有这样一段

Then run the following commands to build the system:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

这里 mkdir, cd，无非就是新建文件夹然后切到里面去。

后面两行呢？

cmake 是读取一个目录下的 `CMakeLists.txt`。对于项目的根文件夹，我们 cd 到它的一个子文件夹 `build` 里，这个时候再 `cmake ..`，无非就是 cmake 根文件夹。

cMake：生成构建规则（写出一个适合当前平台的 Makefile 或其他构建文件）。

make：根据这些规则实际执行编译。

