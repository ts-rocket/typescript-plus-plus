# typescript-plus-plus

目标：支持ts全套语法，符合ES5.6相关规范，能跟C++相互调用，并生成wasm。

## TODO

## Brief

## Build & Run

项目基于[xmake](https://xmake.io/#/)编译并输出可执行文件**ts2llvm**.

```zsh
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

使用 add_requires() 函数添加所需的依赖库，例如：add_requires("library_name")

### List

- [antlr4](https://github.com/antlr/antlr4.git)
- [cli11](https://github.com/spicelang/CLI11/releases/download/v2.3.2-spice/CLI11.hpp)
- [googletest]( https://github.com/google/googletest.git)
- [json](https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp)
- [thread-pool](https://raw.githubusercontent.com/bshoshany/thread-pool/master/include/BS_thread_pool.hpp)
