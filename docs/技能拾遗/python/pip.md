# pip

## 查看已安装

```bash
pip list
```

或者

```bash
pip freeze
```

有时候也能拿来导出一下环境

```bash
pip freeze > requirements.txt
```

## 关掉镜像

```
pip config unset global.index-url
pip config unset global.extra-index-url
```

## 开启镜像

```
pip config set global.proxy http://127.0.0.1:7890
pip config set global.index-url https://pypi.org/simple
```

