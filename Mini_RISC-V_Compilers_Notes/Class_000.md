# 课程前导

**目录：**

[TOC]

---

## rvcc项目

* 基于`@rui314`的`chibicc`项目，将其由原来的`X86`架构改写为`RISC-V 64`架构.
* 同时加入了大量的中文注释，并且配有`316节`对应于每一个 `commit` 的课程，帮助读者可以层层推进、逐步深入的学习**编译器的构造**.

## RISC-V简介

* `RISC-V`是一个开源的精简指令集.
* 相较于常见的 `X86`、`ARM` 架构，其**简单易学**，并且**发展迅猛**.
* 现在已经出现了支持 `RISC-V` 的各类设备，未来还将出现`RISC-V`架构的笔记本电脑，可谓是**前景一片光明**.

## RISC-V常用指令集GC

`GC`包含以下几个指令集：

* `I`整形基础指令集（加减法、存数、取数等）.
* `M`乘除指令集.
* `A`原子操作指令集.
* `F`单精度浮点指令集（32位）.
* `D`双精度浮点指令集（64位）.
* `C`精简指令集（常见占领的缩写形式）.

## `chibicc`项目

* `GitHub`链接：
  * https://github.com/rui314/chibicc.
* 开发者：
  * `Rui 大师`.
* 项目内容：
  * `chibicc`是一个`X86`架构的**迷你编译器**.
  * `chibicc` 项目以 `Commit` 为阶段，借助于`316`个 `commits` 实现了一个能够编译 `Git` 等开源项目的**C编译器**.

## 课程资源

课程对应的代码仓库：
* https://github.com/sunshaoce/rvcc.
课程相关文件地址：
* https://github.com/plctlab/PLCT-Open-Reports.
`chibicc`代码仓库地址：
* https://github.com/rui314/chibicc.
课程对应的视频：
* 将会在**B站**更新，请留意后续**公众号推送**.
`chibicc`作者关于本项目的书刊：
* https://www.sigbus.info/compilerbook.

## 实验环境配置

需要有一个 **Linux 实验环境**，同时安装了 **RISC-V 模拟器**等工具.

`RISC-V` 实验环境配置教程：
* https://www.bilibili.com/video/BV1D54y1m78G.
* 构造出：
  * `riscv-gnu-toolchain`的`64位Linux库`.
  * `spike`和`pk 或者 qemu`.

## 课程预备知识

* 对于`Git`、`Make`、`clang`/`gcc`等工具的简单使用.
* 对于C基本语法，明白**指针**的用法.
* 了解基础的数据结构的知识，明白**链表**的用法.

## 鸣谢

* `PLCT实验室`诸位老师的大力支持.
* `Rui Ueyama（植山 類， Rui大师）`开源且强大的`chibicc仓库`.