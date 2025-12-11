# md5

省流：md5 是通过神秘过程得到的哈希函数，共 128bit，通常用十六进制来表示，所以是 128/4 = 32 个字符。

## 介绍

MD5（Message-Digest Algorithm 5）是一种**不可逆的密码学哈希函数**，由 Ronald Rivest 在 1992 年设计。它将任意长度的输入映射为 **128 bit（16 字节）摘要**，通常表示为 **32 位十六进制字符串**。

MD5 主要特点：

- 速度快、实现简单  
- 不可逆  
- 已被证明存在碰撞漏洞，不再适用于安全场景  
- 常用于文件校验、非安全场景的一致性验证

=== "Linux CLI"

    ```bash
    echo -n "hello world" | md5sum
    ```

    这里 `-n` 选项是说取消默认换行符。`|` 将左边的输出当作右边的输入。

=== "PowerShell"

    ```powershell
    Get-FileHash hello.txt -Algorithm MD5    
    ```


## 原理

todo
