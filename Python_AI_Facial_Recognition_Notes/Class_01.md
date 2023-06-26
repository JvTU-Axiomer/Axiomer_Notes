# 第一讲：走进Python的大门

> 工欲善其事，必先利其器.

---

**目录：**

[TOC]

---

## 一、Python解释器

**Python解释器**

* 功能：
  * 用来翻译和运行`Python代码`.
* 分类：
  * `CPython`解释器.
  * `JPython`解释器 .
  * `IronPython`解释器.

**Python解释器的下载链接**

* 下载地址：https://www.python.org/downloads/release/python-3104/.

> `exe`：`Windows操作系统`中的`可执行文件`.

---

## 二、PyCharm（Python IDE）

**PyCharm IDE下载链接**

* 下载地址：https://www.jetbrains.com/pycharm/download/#section=windows.

**PyCharm的使用方式**

* 新建项目：
  * `New Project`.
    * 创建一个新项目.
  * `Open`.
    * 打开原有的项目.
  * `Get from VCS`.
    * 从代码托管平台上克隆项目.
* `PyCharm`中一键调整代码格式快捷键：
  * `Ctrl + Alt + L`.

> 注意：
> 在使用PyCharm关闭项目时，如果出现卡死在`Closing Project`关闭界面的情况，在不改变PyCharm版本的情况下，有两种解决方法：
> * 在PyCharm右上角菜单栏中通过路径`文件 - 清除缓存... - 清除并重启（R）`对PyChar的缓存进行清除，达到快速关闭项目的目的.
> * 在P有Charm右上角菜单栏中通过路径`文件 - 设置... - 工具 - 共享索引`，在`公开共享索引`下的`下载项目依赖项的预构建共享索引-Python软件包`的下拉栏中选择`不下载，使用本地索引选项`，也可以达到快速关闭项目的目的.

---

## 三、第一个Python项目

### 3.1 设置Python文件的模板

``` Python
# 人生哪能多如意，万事只求半称心.
# @Time : ${DATE} ${TIME}
# @Author : JvTU_Axiomer
# @Version : 
# @IDE : ${PRODUCT_NAME}
# @Project : ${PROJECT_NAME}

```

### 3.2 第一个Python项目（`Hello World!`）

``` Python
    # 人生哪能多如意，万事只求半称心.
    # @Time : 2023/5/23 19:55
    # @Author : JvTU_Axiomer
    # @Version : 
    # @IDE : PyCharm
    # @Project : python_project_01

    print('Hello World!')
```

==程序输出：==

`Hello World!`

---

## 四、课堂小结

学习`Python编程`，**最重要的**就是**多写代码**.