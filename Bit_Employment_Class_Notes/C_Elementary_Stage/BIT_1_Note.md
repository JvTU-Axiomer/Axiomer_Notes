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

`printf()`输出函数，作用是将数据从内存打印（输出）到屏幕上.是一个库函数，是C语言提供的一个现成的函数，直接可以使用.

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

> `"%d"`:以十进制的形式打印一个整数.

* `sizeof()`是一个操作符，是计算类型/变量所占内存空间的大小.
    * `sizeof()`算出来的单位是字节.

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


* `char ch = 'w';`创建了一个char类型的变量，向内存申请了一块`char`大小的空间.

---

## 三、变量、常量

> 不变的值，C语言中用常量的概念来表示；变的值，C语言中用变量来表示。

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
  * `55.5f`这个时候就是float类型的.

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

* `scanf()`：输入函数，作用是将数据从键盘读取到内存中.（C语言的编译器提供的现成的函数，直接可以使用.）
* `%d`：输入的格式.
  * `%c`：字符.
  * `%d`：整型.
  * `%s`：字符串.
  * `%f`：float.
  * `%lf`：double.
  * `%p`：地址的打印.
* `&`：取地址操作符，表示数据存放到哪里.

#### 3.1.3 变量的作用域和生命周期

**作用域：**
    作用域（scope）是程序设计概念，通常来说，一段程序代码中所用到的名字并不总是有效/可用的；而限定这个名字的可用性的代码范围就是这个名字的作用域。

* 局部变量的作用域

> 局部变量的作用域是变量所在的局部范围.

``` C
    int main()
    {
        {
            int a = 100;
            printf("%d\n", a);
        }
        printf("%d\n", a);  //会报错！
        
        return 0;
    }
```

变量a的作用域为：

``` C
    {
        int a = 100;
        printf("%d\n", a);
    }
```

* 全局变量的作用域

> 全局变量的作用域是整个工程.
> 全局变量不安全，尽量避免工程中使用全局变量.

``` C
    int a = 2023;

    void test()
    {
        printf("2--->%d\n", a);
    }

    int main()
    {
        printf("1--->%d\n", a);
        return 0;
    }
```

    extern ：在整个工程中引用外部文件的全局变量时使用的关键字.

**生命周期：**

变量的*生命周期*指的是变量的创建到变量的销毁之间的一个时间段.

* 局部变量的生命和周期

``` C
    int main()
    {
        {
            int a = 3;
            int b = 5;
            int c = a + b;
            printf("%d\n", c);
        }
        //...

        return 0;
    }
```

    局部变量进入作用域生命周期开始，出作用域变量销毁，把空间还给操作系统.

> 变量创建的本质是在内存中开辟一块空间，存放数据.

* 全局变量的生命和周期
  * `main`函数的生命周期就是整个程序的生命周期.
  * 全局变量的生命周期是main函数的生命周期，所以全局变量的生命周期就是整个程序的生命周期.

### 3.2 常量

> C语言中的常量和变量的定义的形式有所差异.

#### 3.2.1 常量的分类

* 字面常量.
* `const`修饰的常变量.
* `#define`定义的标识符常量.
* 

##### 3.2.1.1 字面常量

* 3.14
* 3
* 'a'
* "aabcdef123"

##### 3.2.1.2 `const`修饰的常变量

``` C
    int main()
    {
        const int a = 3;
        printf("%d\n", a);
        a = 10; //会报错！
        return 0;
    }
```

这里的a是具有常属性的，不能改变，但是本质上还是变量.

例如：

``` C
int main()
{
    //数组的创建
    const int n = 10;   //会报错！
    int arr[n];
    return 0;
}
```

##### 3.2.1.3 `#define`定义的标识符常量

``` C
    #define SIZE 10
    #define MAX = 10000
    #define CH 'W'  //单引号不能去掉

    int main()
    {
        //10
        int a = SIZE;
        int arr[SIZE] = { 0 };
        printf("%c\n", CH);
        return 0;
    }
```

> `#define`定义的标识符常量名与变量名相同时也会产生冲突.

##### 3.2.1.4 枚举常量

枚举：一一列举.
生活中有些值是可以一一列举的，比如：性别（男、女），三原色（红、绿、蓝），血型（A、B、O）.

**关键字**：`enum`.

``` C
    enum SEX
    {
        //列出了枚举类型的可能取值
        //枚举常量
        MALE = 4,
        FEMALE, //5
        SECRET  //6
    };

    int main()
    {
        enum SEX s = FEMALE;

        MALE = 5;   //会报错！
        printf("%d\n", MALE);
        printf("%d\n", FEMALE);
        printf("%d\n", SECRET);

        return 0;
    }
```

* 不同的枚举常量，初始值（如果不进行赋值）从0开始，依次向下递增1：0，1，2，... .
* 两组枚举类型不预允许重名.

---

## 四、字符串、转义字符、注释

### 4.1 字符

`'c'`这种由单引号（Apostrophe）引起来的是C语言中的字符.

### 4.2 字符串

`"hello bit!\n"`这种由双引号（Double Quote）引起来的一串字符称为字符串字面值（String Literal），或者简称字符串（常量）.
字符串就是一串字符.

``` C
    int main()
    {
        "abcdef";
        //char ch1 = 'a';
        //char ch2 = 'b';
        //char ch3 = 'c';
        char ch1[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
        char ch2[] = "abcdef";
        char ch3[] = {'\0', 'a', 'b', 'c', 'd', 'e', 'f' };

        printf("%s\n", ch1);
        printf("%s\n", ch2);
        printf("%s\n", ch3);
        return 0;
    }
```

调试结果：

![代码1调试结果](./assets/代码1调试结果.png)

运行结果：

![代码1运行结果](./assets/代码1运行结果.png)

> `printf()`以`%s`打印字符串的时候，就从给定的地址开始打印，一直打印到遇到`\0`时停止.

``` C
    int main()
    {
        char ch1[] = {'a', 'b', 'c'};   //[a][b][c]
        char ch2[] = "abc"; //[a][b][c][\0]
        int len1 = strlen(ch1);
        int len2 = strlen(ch2);
        printf("%d\n", len1);   //得到的会是一个随机值
        printf("%d\n", len2);
        return 0;
    }
```

调试结果：

![代码2调试结果](./assets/代码2调试结果.png)

运行结果：

![代码2运行结果](./assets/代码2运行结果.png)

> `strlen()`是库函数，用来求字符串长度，就是从给定的地址，向后数字符，直到遇到`\0`结束，`\0`不统计在内.

> 字符串的结束标志是一个`\0`的转义字符。在计算字符串长度的时候`\0`是结束标志，不算作字符串内容.

### 4.3 转义字符

转义字符：转变原来的意思.

``` C
int main()
{
    printf("(are you ok??)");
    //are you ok]
    //??) -> 三字母词 -> 代表 ]
    printf("(are you ok\?\?)");

    printf("ab\ndef");

    printf("C:\test\test.c");
    printf("C:\\test\\test.c");

    printf("%c\n", 'a');
    printf("%c\n", ''');    //出错！
    printf("%c\n", '\'');

    printf("%c\n", "abc");
    printf("%c\n", "a");
    printf("%c\n", "\"");

    printf("%c\n", "'");    //$
    printf("%s\n", "'");    //'

    printf("%c\n", "a\\tb");

    printf("%s\n", "abc\bdef");

    printf("%c\n", '\130'); //X
    //八进制的130转换成十进制的88后，把88作为ASCII值代码代表的字符
    printf("%c\n", '\133'); //[
    printf("%s\n", "\13045612"); //X45612

    printf("%d\n", strlen("c:\test\x11\328\test.c"));   //字符串长度为15
    // /32为一个转义字符，不含下一位的8，因为八进制数字不含有8

    return 0;
}
```

| 转义字符 | 释义 |
| ----  | ---- |
| \? | 在书写连续多个问号时使用，防止他们被解析成三字母词 |
| \' | 用于表示字符常量' |
| \" | 用于表示一个字符串内部的双引号 |
| \\ | 用于表示一个反斜杠，防止它被解释为一个转义序列符 |
| \a | 警告字符，蜂鸣 |
| \b | 退格符 |
| \f | 进纸符 |
| \n | 换行 |
| \r | 回车 |
| \t | 水平制表符 |
| \v | 垂直制表符 |
| \ddd | ddd表示1~3个八进制的数字。 如： `\130`表示字符`X` |
| \xdd | dd表示1~2个十六进制数字。 如： `\x31`表示字符`1` |

    不同的进制只是数据的表示形式而已（各个数位的底数权值不同）：
        例如，15的各个不同进制下的数据表示形式为：
          * 十进制：15
          * 八进制：17
          * 二进制：1111
          * 十六进制：F

> 键盘上的字符在计算机中是用字符的编号（二进制）表示和存储的，称为ASCII码（美国标准信息交换代码）值.
> `A`（65）与`a`（97）之间相差32.

### 4.4 注释

**注释：** 一些解释性的语句.

* 代码中有不需要的代码可以直接删除，也可以注释掉
* 代码中有些代码比较难懂，可以加一下注释文字

**注释的两种方式：**

* 以`//`开头的注释是属于C++的注释风格.
* /**/是属于C语言的注释风格，但是不支持嵌套.


``` C
/*
* C语言的注释风格.
*/

/*
    //...
    /*
        //...
    */
*/
//C语言的注释不支持嵌套注释.

//C++的注释风格.
```

---

## 五、选择语句

* if语句

``` C
    int main()
    {
        printf("加入比特就业课学习\n");
        printf("你愿意好好学习吗？(1/0)>:");
        int flag = 0;
        scanf("%d", &flag);

        if (flag == 1)
        {
            printf("好offer\n");
        }
        else if (flag == 0)
        {
            printf("卖红薯\n");
        }

        return 0;
    }
```

> C语言中的判断用判断符号`==`.

* switch语句

## 六、循环语句

* while 语句

``` C
    int main()
    {
        int line = 0;
        while (line < 50000)
        {
            if (...)
            {
                //...
            }
            printf("敲代码：%d\n", line);
            line++;
        }

        if (line == 50000)
            printf("好offer\n");
        else
            printf("差点意思\n");

        return 0;
    }
```

* for 语句
* do...while 语句


