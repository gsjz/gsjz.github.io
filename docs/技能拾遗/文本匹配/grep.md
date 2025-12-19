# grep

## 基本语法

| 形式                         | 说明        |
| -------------------------- | --------- |
| `grep PATTERN file`        | 在文件中查找匹配行 |
| `grep PATTERN file1 file2` | 在多个文件中查找  |
| `grep PATTERN dir/*`       | 在目录下文件中查找 |
| `command \| grep PATTERN`  | 从管道输入中过滤  |

## 常用选项

| 选项          | 含义        | 示例                        |
| ----------- | --------- | ------------------------- |
| `-n`        | 显示行号      | `grep -n main a.cpp`      |
| `-i`        | 忽略大小写     | `grep -i error log.txt`   |
| `-v`        | 反向匹配（不包含） | `grep -v DEBUG log.txt`   |
| `-r` / `-R` | 递归搜索目录    | `grep -r TODO src/`       |
| `-l`        | 只输出匹配的文件名 | `grep -l class *.h`       |
| `-c`        | 统计匹配行数    | `grep -c fail log.txt`    |
| `-w`        | 整词匹配      | `grep -w int a.cpp`       |
| `-o`        | 只输出匹配内容   | `grep -o '[0-9]\+' a.txt` |


## 正则表达式相关

| 选项   | 含义                     | 示例                    |             |
| ---- | ---------------------- | --------------------- | ----------- |
| `-E` | 使用**扩展正则**（等价 `egrep`） | `grep -E 'foo         | bar' a.txt` |
| `-F` | 固定字符串（不解析正则，最快）        | `grep -F 'a+b' a.txt` |             |
| `-P` | PCRE 正则（并非所有系统支持）      | `grep -P '\d+' a.txt` |             |

## 输出控制

| 选项             | 含义      | 示例                            |
| -------------- | ------- | ----------------------------- |
| `--color=auto` | 高亮匹配内容  | `grep --color=auto foo a.txt` |
| `-H`           | 显示文件名   | `grep -H main *.c`            |
| `-h`           | 不显示文件名  | `grep -h main *.c`            |
| `-A N`         | 显示后 N 行 | `grep -A 3 error log.txt`     |
| `-B N`         | 显示前 N 行 | `grep -B 2 error log.txt`     |
| `-C N`         | 前后各 N 行 | `grep -C 3 error log.txt`     |


## 匹配规则控制

| 选项     | 含义        | 示例                        |
| ------ | --------- | ------------------------- |
| `-x`   | 整行匹配      | `grep -x 'return 0;' a.c` |
| `-m N` | 匹配 N 行后停止 | `grep -m 1 main a.cpp`    |
| `-s`   | 静默错误信息    | `grep -s foo /root/*`     |


## 文件与目录过滤

| 选项                  | 含义      | 示例                                 |
| ------------------- | ------- | ---------------------------------- |
| `--include=PAT`     | 只搜索匹配文件 | `grep -r foo . --include=*.cpp`    |
| `--exclude=PAT`     | 排除文件    | `grep -r foo . --exclude=*.o`      |
| `--exclude-dir=DIR` | 排除目录    | `grep -r foo . --exclude-dir=.git` |

## 常见正则速查


| 表达式      | 含义                 |
| -------- | ------------------ |
| `.`      | 任意字符               |
| `*`      | 前项 0 次或多次          |
| `+`      | 前项 1 次或多次（需 `-E`）  |
| `?`      | 前项 0 或 1 次（需 `-E`） |
| `^`      | 行首                 |
| `$`      | 行尾                 |
| `[abc]`  | a / b / c          |
| `[^abc]` | 非 a/b/c            |
| `\d`     | 数字（需 `-P`）         |
| `\w`     | 字母数字下划线（需 `-P`）    |


