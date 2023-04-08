# 第一讲：初识C语言

> 基本了解C语言的基础知识，对C语言有一个大概的认识。
> 每个知识点就是简单认识，不做详细讲解，后期课程都会细讲。

---

**目录：**

[TOC]

---

## 一、第一个C语言程序

> C语言文件中，有两种文件：
> * `.h header`   头文件
> * `.c`         源文件

### 1.1 VS2022的相关操作

* ctrl + f5 ：   编译、链接、运行.
* f5        ：   调试.
* f10       ：   单步进入.

        注意：

            出现scanf_s报错：
            解决的办法：在源文件的第一行加上#define _CRT_SECURE_NO_WARNINGS 1

### 1.2 第一个C语言代码

``` C
    #include <stdio.h>

    int main()
    {
        printf("hello bit\n");
        return 0;
    }
```

> test.c -> C源程序 -> 编译 -> 链接 -> 可执行程序 -> test.exe

#### 1.2.1 `main`函数

代码一般是从`main`函数开始写.
C语言中`main`函数是程序的入口.
程序是从`main`函数的第一行开始执行的.
C语言的`main`函数有且仅有一个.

``` C
    int main()
    {
        return 0;
    }
```

* `int`与`return 0`相对应；
* `{   }`包含的是程序的函数体；

==不推荐这样写：==

``` C
void main()
{

}
```

==这样写也可以：==

*第一种：*

``` C
int main(void)
{
    return 0;
}
```

> `void`表示在这里`main`函数不接受任何形式的参数

*第二种：*

``` C
int main(int argc, char* argv[])
{
    return 0;
}
```

#### 1.2.2 printf()函数

``` C
printf("hehe");
```

> 注意：
    > * 双引号引起来的就是字符串
    > * `\n`表示换行

`printf()`是一个库函数，是C语言提供的一个现成的函数，直接可以使用.

* 功能：在屏幕上打印数据.
* 在使用之前要包含头文件`stdio.h`
  * `#include <stdio.h>`

---

## 二、数据类型

### 2.1 数据类型分类

> * 字符数据类型：char.
> * 短整型：short.
> * 整型：int.
> * 长整型：long.
> * 更长的整型：long long.
> * 单精度浮点型：float.
> * 双精度浮点型：double.
> * 更长的双精度浮点型：long double.(C99)
> * 布尔类型：_Bool.(C99)

### 2.2 每种数据类型的大小

``` C
    int main()
    {
        printf("%d\n%d\n", 20, 10);
        printf("%d\n", sizeof(char));
        printf("%d\n", sizeof(short));
        printf("%d\n", sizeof(int));
        printf("%d\n", sizeof(long));
        printf("%d\n", sizeof(long long));
        printf("%d\n", sizeof(float));
        printf("%d\n", sizeof(double));

        char ch = 'w';

        return 0;
    }
```

> `"%d"` :以十进制的形式打印一个整数.

* `sizeof()` 是一个操作符，是计算类型/变量所占内存空间的大小.
    * `sizeof()` 算出来的单位是字节.

        计算机中的单位：
            bit     比特位（存放一个二进制位）
            Byte    字节（8 bit）
            KB          （1024 Byte）
            MB          （1024 KB）
            GB          （1024 MB）
            TB          （1024 GB）
            PB          （1024 TB）
            ...
    * sizeof(long long) >= sizeof(long).
    * sizeof(long) >= sizeof(int).


* `char ch = 'w';` 创建了一个char类型的变量，向内存申请了一块 `char` 大小的空间.

---

## 三、变量、常量

> C语言中用常量的概念来表示，变得值C语言中用变量来表示.

### 3.1 变量

#### 3.1.1 变量的分类

* 类型 变量名;
* 类型 变量名 = 初始值;

``` C
    int main()
    {
        int age1;
        int age2 = 20;

        float weight1 = 55.5f;
        double weight2 = 80.5;

        int num = 10;
        printf("%d\n", num);
        num = 20;
        printf("%d\n", num);

        return 0;
    }
```

* 小数直接写出来，编译器默认是double类型的.
  * `55.5f` 这个时候就是float类型的.

            变量名只能由字母（包括大小写）、数字和下划线（_）组成.
            不能以数字开头.
            长度不能超过63个字符.
            变量名区分大小写.
            变量名不能使用关键字.
            变量名要起的有意义.

#### 3.1.2 变量的分类

* 局部变量
* 全局变量

``` C
    int a = 100; //全局变量

    int main()
    {
        int a = 10; //局部变量
        printf("a = %d\n", a);
        return 0;
    }
```

> 原则上变量名尽量不要冲突.
> 但是当全局变量和局部变量名字冲突的情况下，**局部变量优先**.

#### 3.1.2 变量的使用

写一个代码，求两个整数的和?

``` C
    int main()
    {
        //写一个代码，求两个整数的和
        int num1 = 0;
        int num2 = 0;
        int sum = 0;
        //输入两个整数的值
        scanf("%d %d", &num1, &num2);
        sum = num1 + num2;
        //打印
        printf("%d\n", sum);

        return 0;
    }
```

* `scanf()` ：输入函数.
* `&` ：取地址操作符
* 