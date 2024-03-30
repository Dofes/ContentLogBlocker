# ContentLogBlocker

一个简单的LeviLamina插件，用于屏蔽你想要屏蔽的ContentLog。

## 安装

### 使用Lip

```sh
lip install github.com/Dofes/ContentLogBlocker
```

### 手动安装

1. 从[发布页面](https://github.com/Dofes/ContentLogBlocker/releases)下载最新版本。
2. 解压`ContentLogBlocker-windows-x64.zip`文件。
3. 将`ContentLogBlocker`文件夹复制到BDS安装目录下的`plugins`文件夹中。

## 使用

首次运行后，ContentLogBlocker将在`plugin/ContentLogBlocker/config/`中生成配置文件。您可以修改这些文件以定制插件的行为。

### 配置文件

```jsonc
// .........
    "blocked": [
        [
            3,
            29
        ], // Error : Structure
        [
            3,
            26
        ], // Error : Script
        [
            3,
            9
        ] // Error : Component
    ]
// .........
```

这是默认的配置文件，你可以在你的config文件夹中找到这个文件。你可以在这里添加你想要屏蔽的ContentLog的Level:Area。

MIT © Dofes
