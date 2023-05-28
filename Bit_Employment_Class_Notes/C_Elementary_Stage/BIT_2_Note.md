# 第二讲：分支语句和循环语句

> 一群人的影响比一个人去努力价值更大.

---

**目录：**

[TOC]

---

* 分支语句：
  * `if`语句.
  * `switch`语句.

* 循环语句：
  * `while`语句.
  * `for`语句.
  * `do...while`语句.

* `goto`语句.

> C语言是一个结构化的程序设计语言.
> * 循序结构.
> * 选择结构（分支语句）.
> * 循环结构（循环语句）.

## 一、语句

C语句可分为以下五类：
* 表达式语句.

    ``` C
        3 + 5;
    ```

* 函数调用语句.

    ``` C
        printf("Hello world!");
    ```

* 控制语句.
  * 用于控制程序的执行流程，以实现程序的各种结构方式，它们由特定的语句定义符组成.
  * C语言有九种控制语句：
    * 条件判断语句（分支语句）：
      * `if`语句.
      * `switch`语句.
    * 循环执行语句：
      * `do...while`语句.
      * `while`语句.
      * `for`语句.
    * 转向语句：
      * `break`语句.
      * `goto`语句.
      * `continue`语句.
      * `return`语句.
* 复合语句.
* 空语句.

    ``` C
        ;
    ```

---

## 二、分支语句（选择结构）

### 2.1 `if`语句

基本语法结构：

==单分支语句==

``` C
if (表达式)
{
    语句体;
}
```

==双分支语句==

``` C
if (表达式)
{
    语句1;
}
else
{
    语句2;
}
```

==多分支语句==

``` C
if (表达式1)
{
    语句1;
}
else if (表达式2)
{
    语句2;
}
else
{
    语句3;
}
```

> 这里的一对`{ }`就是一个`代码块`.

示例代码：

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int age = 0;
        //输入.
        scanf("%d", &age);
        //只能进入一种情况.
        //如果判断一种情况符合条件，那么剩余的情况都不会进行判断.
        if (age < 18)
            printf("青少年\n");
        else if (age >= 18 && age < 30)
            printf("青年\n");
        else if (age >= 31 && age < 50)
            printf("中年\n");
        else if (age >= 80 && age < 100)
            printf("老年\n");
        else
            printf("老寿星\n");
        return 0;
    }
```

> `if`和`else`语句默认只能管理其后的一条语句.
> 因此一种好的编程习惯是不论何时都为`if`和`else`语句之后分配大括号.

> 在C语言中如何表示真假？
> * `0`表示假.
> * `非0`表示真.

#### 2.1.1 悬空`else`

**`else`的匹配：**`else`是和它离的最近的`if`匹配的.

==示例代码：==

``` C
    #include <stdio.h>
    int main()
    {
        int a = 0;
        int b = 2;
        if(a == 1)
            if(b == 2)
                printf("hehe\n");
        else
            printf("haha\n");
        return 0;
    }
```

==改正：==

``` C
    //适当的使用{}可以使代码的逻辑更加清楚.
    //代码风格很重要.
    #include <stdio.h>
    int main()
    {
        int a = 0;
        int b = 2;
        if(a == 1)
    {
            if(b == 2)
        {
                printf("hehe\n");
        }
    }
        else
    {
            printf("haha\n");
    }       
        return 0;
    }
```

> 养成好的代码风格：
> 未来找工作的时候，有笔试和面试，都需要书写代码.
> * 推荐书籍：
>   * *《高质量C++/C编程指南》    —— 林锐*

#### 2.1.2 `if`语句书写形式对比

**形式1：**

* 只要执行了`return`，子程序就会返回，`return`之后的语句都不会再被执行了.

``` C
//代码1：
    if (condition) {
        return x;
    }
    return y;
```

``` C
//代码2：
    if(condition)
    {
        return x;
    }
    else
    {
        return y;
    }
```

> 代码1和代码2的执行结果是一样的.

**形式2：**

* 当一个变量和一个常量比较相等的时候，良好的书写风格为把常量写在`==`的左边，可以在将`==`误写为`=`时编译器会检查并报错.

``` C
//代码3
    int num = 1;
    if(num == 5)
    {
        printf("hehe\n");
    }
```

``` C
//代码4
    int num = 1;
    if(5 == num)
    {
        printf("hehe\n");
    }
```

> 代码4的书写形式更好，逻辑更加清晰，不容易出错.

#### 2.1.3 `if`语句练习

* 练习一：

题目：判断一个数是否为奇数.

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int n = 0;
        scanf("%d", &n);
        if (n % 2 != 0)
        {
            printf("这个数是奇数！\n");
        }
        else
        {
            printf("这个数不是奇数！\n");
        }
        return 0;
    }
```

* 练习二：

题目：输出1-100之间的奇数.

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        for (int i = 1; i <= 100; i++)
        {
            if (i % 2 != 0)
            {
                printf("%d是奇数！\n", i);
            }
        }
        return 0;
    }
```

### 2.2 switch语句

> `switch`语句也是一种分支语句.
> 常常用于多分支的情况.

**基本语法结构：**

``` C
switch(整型表达式)
{
//语句项：
case 整形常量表达式:
    语句1;
case 整型常量表达式:
    语句2;
//case...
    //语句...
default:
    default子句项;
}
```

**注意：**
* `char`也可以当作整型常量表达式.
* 标识符常量
* `const`修饰的常变量本质上是变量：
  * 在`.c文件`中当作变量表达式.
  * 在`.cpp文件`当作整型常量表达式.

> 语句项：
> * 是一些`case`语句.

#### 2.2.1 在`switch`语句中的`break`

`case`语句
* 决定`switch`语句中进入分支的入口.

`break`语句
* 实际效果是把语句列表划分为不同的分支部分.

**case穿透：**

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int day = 0;
        scanf("%d", &day);
        switch (day)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("weekday!\n");
        case 6:
        case 7:
            printf("weekend!\n");
            break;
        }
        return 0;
    }
```

#### 2.2.2 `default`子句

`default`子句：
* 功能：
  * 当`switch`表达式的值并不匹配所有`case`标签的值时，这个`default`子句后面的语句就会执行.
* 位置：
  * 可以写在任何一个`case`标签可以出现的位置.
* 注意：
  * 每个`switch`语句中只能出现一条`default`子句.
  * 语句流会像执行一个`case`标签一样执行`default`子句

> 编程好习惯：
> * 在每个`switch`语句中都放一条`default`子句.
> * 甚至可以在后边再加一个`break`.

#### 2.2.3 `switch`嵌套

* `switch`语句是可以嵌套的.
* `break`语句只能跳出一层`switch`.

代码示例：

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int n = 1;
        int m = 2;
        switch (n)
        {
        case 1:
            m++;
        case 2:
            n++;
        case 3:
            switch (n)
            {
                //switch允许嵌套使用
            case 1:
                n++;
            case 2:
                m++;
                n++;
                break;
            }
        case 4:
            m++;
            break;
        default:
            break;
        }
        printf("m = %d, n = %d\n", m, n);
        return 0;
    }
```

> 输出：
> * `m = 5, n = 3`.

---

## 三、循环语句

循环语句分类：
* `while`循环.
* `for`循环.
* `do...while`循环.

### 3.1 `while`循环

基本语法结构：

``` C
while(表达式)
{
    循环体;
}
```

代码示例：

> 在屏幕上打印1-10的数字.

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int n = 1;
        while (n <= 10)
        {
            printf("%d ", n);
            n++;
        }
        return 0;
    }
```

> `stmt`:
> * `statement`：`语句`.

#### 3.1.1 `while`语句中的`break`和`continue`

**break语句：**

`break`语句在`while`循环中的作用：
* 在循环中只要遇到`break`，就停止后期的所有的循环，直接终止循环.
* 所以，`while`中的`break`是用于`永久终止循环`的.

==注意：==`break`一次只能跳出一层循环.

代码示例：

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int n = 1;
        while (n <= 10)
        {
            if (5 == n)
                break;
            printf("%d ", n);
            n++;
        }
        return 0;
    }
```

> 输出：
> * `1 2 3 4 `.

**continue语句：**

`continue`语句在`while`循环中的作用：
* 本次循环中`continue`后边的代码不会再执行，而是直接跳转到`while`语句的判断部分，进行下一次循环的入口判断.
* 所以，`while`中的`continue`是用于`终止本次循环`的.

代码示例：

* 代码1：

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int n = 1;
        while (n <= 10)
        {
            if (5 == n)
                continue;
            printf("%d ", n);
            n++;
        }
        return 0;
    }
```

> 输出：
> * `1 2 3 4 //死循环...`.

* 代码2：

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int n = 1;
        while (n <= 10)
        {
            n++;
            if (5 == n)
                continue;
            printf("%d ", n);
        }
        return 0;
    }
```

> 输出：
> * `2 3 4 6 7 8 9 10 11`.



> 小贴士：
> * C语言标准规定了：
>   * `sizeof(long) >= sizeof(int)`.
> * 所以在某些编译器下：
>   * `sizeof(long) = sizeof(int)`；
>   * `sizeof(long double) = sizeof(double)`.

#### 3.1.2 `while`循环的特殊用法

**清理缓冲区：**

`getchar()`：
* 声明：
  * `int getchar ( void );`.
* 输入参数：
  * 空（`void`）.
* 输出返回值：
  * 如果读取成功：
    * 返回读取的字符的`ACSII码`值.
  * 如果读取失败：
    * 返回`文件结束标志EOF`（`-1`）.
      * `Ctrl + Z`：会让`getchar()`返回`EOF`.
* 功能：获取一个字符.

`putchar()`：
* 声明：
  * `int putchar ( int character );`.
* 输入参数：
  * 欲打印的字符.
* 输出返回值：
  * 如果读取成功：
    * 返回读取的字符的`ASCII码`值.
  * 如果读取失败：
    * 返回`文件结束标志EOF`（`-1`）.
* 功能：打印传入的字符.

输入缓冲区问题：

* 键盘上的输入符号会先存入输入缓冲区中.
* `scanf()`函数和`getchar()`函数在从键盘上读取输入字符时，会从输入缓冲区中读取字符.
  * `scanf()`在第一次读取时会将缓冲区中回车符或空格符之前的字符全部读入；
  * `scanf()`在第二次读取时会将缓冲区中的回车符或空格符读入.
* 因此在`scanf()`第二次读取前需要将缓冲区中的回车符读出，防止影响`scanf()`读取错误.

清空缓冲区操作：
``` C
    #include <stdio.h>
    int main()
    {
        int ch = 0;
        //Ctrl + Z：会让getchar返回EOF.
        while ((ch = getchar()) != EOF)
            //可以读入回车符.
            putchar(ch);
        return 0;
    }
```

> `fflush()`：
> * 功能：
>   * 清空缓冲区.
> * 注意：
>   * 在新版本编译器中，已经不支持`fflush()`函数操作了.

> `scanf()`正则表达式格式化输出：
> * `%[^\n]`.

==BUG代码：==

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        char password[20] = { 0 };
        char input = 0;
        printf("请输入密码：>\n");
        scanf("%s", password);
        printf("请确认密码：(Y/N)>\n");
        scanf("%c", &input);
        if ('Y' == input)
            printf("确认成功！\n");
        else
            printf("确认失败！\n");
        return 0;
    }
```

==改正：==

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        char password[20] = { 0 };
        char input = 0;
        printf("请输入密码：>\n");
        scanf("%s", password);
        //清理掉缓冲区剩余数据：
        while (getchar() != '\n')
        {
            ;
        }
        printf("请确认密码：(Y/N)>\n");
        scanf("%c", &input);
        if ('Y' == input)
            printf("确认成功！\n");
        else
            printf("确认失败！\n");
        return 0;
    }
```

**选择性打印字符：**

> 只打印数字字符，而跳过其他字符.

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        char ch = '\0';
        while ((ch = getchar()) != EOF)
        {
            if (ch < '0' || ch > '9')
                continue;
            putchar(ch);
        }
        return 0;
    }
```