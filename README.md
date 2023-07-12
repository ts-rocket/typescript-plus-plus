# typescript-plus-plus

目标：支持ts全套语法，符合ES5.6相关规范，能跟C++相互调用，并生成wasm。

## TODO

## Build & Run

项目基于[xmake](https://xmake.io/#/)编译并输出可执行文件**ts2llvm**.

```zsh
# 可视化配置界面
xmake f --menu

# 构建项目
xmake
xmake build

# 运行并生成产物
xmake run
xmake run -d
```

## Dependency

项目通过[xmake.lua](xmake.lua)文件管理依赖的三方库

### Useage

使用xrepo管理三方库，例如：```xrepo search zlib```

使用xrepo安装三方库，例如：```xrepo install zlib```

xmake文件中使用 add_requires() 函数添加所需的依赖库，进入特定的包虚拟环境，例如：```add_requires("library_name")```

xmake文件中使用 add_packages() 函数引入所需的依赖库，例如：```add_packages("library_name")```

### List

- [antlr4](https://github.com/antlr/antlr4.git)
- [cli11](https://github.com/spicelang/CLI11/releases/download/v2.3.2-spice/CLI11.hpp)
- [googletest]( https://github.com/google/googletest.git)
- [json](https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp)
- [thread-pool](https://raw.githubusercontent.com/bshoshany/thread-pool/master/include/BS_thread_pool.hpp)

## FAQ

### 1. 如何安装xmake管理工具

 **MAC OS**: 建议直接直接通过homebrew安装 ```brew install xmake```
