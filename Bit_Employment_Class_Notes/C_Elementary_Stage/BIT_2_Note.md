# 第二讲：分支语句和循环语句

> 一群人的影响比一个人去努力价值更大.

> C语言推荐一本书：《*明解C语言——入门篇*》.
>       ==图文并茂，通俗易懂==.

> 关于Gitee：
> * Gitee的仓库的名字起好一点.
>   * 名字要有意义.
> * Gitee的仓库是可以删除的.
> * Gitee的一个仓库中可以放很多代码.
>   * 不是每一个代码项目都需要创建一个仓库.
> * 鼠标要点在仓库路径下，才能看到`Add`.
>   * 先把远程仓库克隆到本地，然后在克隆到本地的仓库路径下进行`Add`.
> * 如果在远程仓库下进行了文件的更改和删除操作，那么在本地克隆仓库路径下需要先进行拉取（`Pull`）操作，再进行`Add`、`Commit`和`Push`操作.
> * 提交仓库后，本地的文件最好不要删除.

> Talk is cheap, show me the code!

> 人和人之间**最小的差距是智商，最大的差距是坚持**.

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

> 使用while循环在屏幕上打印1-10的数字.

``` C
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    int main()
    {
        int n = 1;  //循环变量的初始化.
        while (n <= 10) //循环变量的判断.
        {
            printf("%d ", n);
            n++;    //循环变量的调整.
        }
        return 0;
    }
```

> `stmt`:
> * `statement`：`语句`.

#### 3.1.1 `while`语句中的`break`和`continue`

**`break`语句：**

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

**`continue`语句：**

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

### 3.2 `for`循环

基本语法结构：

``` C
for(表达式1; 表达式2; 表达式3)
{
    循环体.
}
```

* `表达式1`：初始化部分.
  * 用于初始化循环变量.
* `表达式2`：判断部分.
  * 用于判断循环时候终止.
* `表达式3`：调整部分.
  * 用于循环条件的调整.

代码示例：

> 使用for循环在屏幕上打印1-10的数字.

``` C
    #include <stdio.h>
    int main()
    {
        int i = 0;
        for (i = 1; i <= 10; i++)
        {
            printf("%d ", i);
        }
        return 0;
    }
```

#### 3.2.1 `for`循环中的`break`和`continue`

**`break`语句：**

``` C
    #include <stdio.h>
    int main()
    {
        int i = 0;
        for (i = 1; i <= 10; i++)
        {
            if (i == 5)
                break;
            printf("%d ", i);
        }
        return 0;
    }
```

> 输出：
> * `1 2 3 4 `.

**`continue`语句：**

``` C
    #include <stdio.h>
    int main()
    {
        int i = 0;
        for (i = 1; i <= 10; i++)
        {
            if (i == 5)
                continue;
            printf("%d ", i);
        }
        return 0;
    }
```

> 输出：
> * `1 2 3 4 6 7 8 9 10 `.

> 注意：
> 因为调整部分没有放在循环体内，因此在该案例中，与`while循环`相比，`for循环`使用`continue`不会进入死循环.

==错误使用方法：==

``` C
    #include <stdio.h>
    int main()
    {
        int i = 0;
        for (i = 1; i <= 10; )
        {
            if (i == 5)
                continue;
            printf("%d ", i);
            i++;
        }
        return 0;
    }
```

> 输出：
> * `1 2 3 4 //死循环...`.

#### 3.2.2 `for`语句的循环控制变量

小建议：
* 不可在`for`循环体内修改循环变量，防止`for`循环失去控制.
    ``` C
        #include <stdio.h>
        int main()
        {
            int i = 0;
            for (i = 1; i <= 10; )
            {
                if (i = 5)
                    continue;
                printf("%d ", i);
                i++;
            }
            return 0;
        }
    ```
* 建议`for`语句的循环控制变量的取值采用“`前闭后开区间`”写法.
    ``` C
        int i = 0;
        //前闭后开的写法
        for(i=0; i<10; i++)
        {
            循环体.
        }

        //两边都是闭区间
        for(i=0; i<=9; i++)
        {
            循环体.
        }
    ```
    ``` C
        #include <stdio.h>
        int main()
        {
            int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            int i = 0;
            for (i = 0; i < 10; i++)
            {
                printf("%d ", arr[i]);
            }
            return 0;
        }
    ```

> 注意：
> * 在`for`循环的初始化部分进行变量的定义是C++的写法.
> * 但是在`C99`中，C语言**也可以**采用这一种方式进行变量的定义和初始化.
>   ``` C
>   //C语言的写法：
>   int i = 0;
>   for (i = 0; i < 10; i++)
>   {
>       循环体.
>   }
>   //C++的写法：
>   for (int j = 0; j < 10; j++)
>   {
>       循环体.
>   }
>   ```
> 以上即为`for`循环**初始化变量**的两种方式.

#### 3.2.3 一些`for`循环的变种

==变种一：==

* `for`循环中的初始化部分、判断部分、调整部分是可以省略的.
* 判断部分省略，意味着**判断是恒为真**的.
* 建议不要随便省略.

``` C
#include <stdio.h>
int main()
{
	for ( ; ; )
	{
		printf("Hello world!\n");
	}
	return 0;
}
```

易错代码：

``` C
    #include <stdio.h>
    int main()
    {
        int i = 0;
        int j = 0;
        int cnt = 1;
        for ( ; i < 4; i++)
        {
            for ( ; j < 4; j++)
            {
                printf("%d ", cnt);
                cnt++;
            }
        }
        return 0;
    }
```

> 输出：
> * `1 2 3 4 `.

==变种二：==

* 在`for`循环中，可以使用**多余一个变量**控制循环.

``` C
    #include <stdio.h>
    int main()
    {
        int x, y;
        for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
        {
            printf("Hello world!\n");
        }
        return 0;
    }
```

易错代码：

``` C
    //请问循环要循环多少次？
    #include <stdio.h>
    int main()
    {
    int i = 0;
    int k = 0;
    for(i =0,k=0; k=0; i++,k++)
            k++;
    return 0;
    }
```

> 在这个案例中，`for`循环一次都不执行.

> 注意：
> * 赋值表达式的执行顺序为**从右向左执行**.
>   ``` C
>   int a, b, c = 0;
>   a = b = c = 7;
>   printf("a = %d, b = %d, c = %d\n", a, b, c);
>   ```
>   以上代码输出结果为：
>   * `a = 7, b = 7, c = 7`.
> * 变量的左值和右值：
>   ``` C
>   int a = 10;
>   a = 20; //左值a代表了变量的空间.
>   int b = a;  //右值a代表了变量空间中的内容.
>   ```
>   左值即为**变量空间**，右值即为**变量空间中的内容**.

### 3.3 `do...while()`循环

基本语法结构：

``` C
do
{
    循环体.
}
while(表达式);
```

> 特点：
> * 循环**至少执行一次**.
> * 使用的场景有限，所以不是经常使用.

代码示例：

> 使用do...while()语句在屏幕上打印1-10的数字.

``` C
    #include <stdio.h>
    int main()
    {
        int i = 1;
        do
        {
            printf("%d ", i);
            i++;
        } while (i <= 10);
        return 0;
    }
```

#### 3.3.1 `do...while()`循环中的`break`和`continue`

**`break`语句：**

``` C
    #include <stdio.h>
    int main()
    {
        int i = 1;
        do
        {
            if (i == 5)
                break;
            printf("%d ", i);
            i++;
        } while (i <= 10);
        return 0;
    }
```

> 输出：
> * `1 2 3 4 `.

**`continue`语句：**

``` C
    #include <stdio.h>
    int main()
    {
        int i = 1;
        do
        {
            if (i == 5)
                continue;
            printf("%d ", i);
            i++;
        } while (i <= 10);
        return 0;
    }
```

> 输出：
> * `1 2 3 4 //死循环...`.

### 3.4 课堂练习

* 练习一

题目：计算 n的阶乘。

``` C
    #include <stdio.h>
    int main()
    {
        int n = 0;
        scanf("%d", &n);
        int ret = 1;
        for (int i = 1; i <= n; i++)
        {
            ret = ret * i;
        }
        printf("%d\n", ret);
        return 0;
    }
```

> 注意：
> * 上述代码不考虑**溢出情况**.

* 练习二

题目：计算 1!+2!+3!+……+10!。

==方法一：==

``` C
    #include <stdio.h>
    int main()
    {
        int n = 0;
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int ret = 1;
            for (int j = 1; j <= i; j++)
            {
                ret = ret * j;
            }
            sum = sum + ret;
        }
        printf("%d\n", sum);
        return 0;
    }
```

==方法二：==

``` C
    #include <stdio.h>
    int main()
    {
        int n = 0;
        scanf("%d", &n);
        int ret = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            ret = ret * i;
            sum += ret;
        }
        printf("%d\n", sum);
        return 0;
    }
```

* 练习三

题目：在一个有序数组中查找具体的某个数字n。

> 二分查找：
> * 前提条件：
>   * 用于查找的内容逻辑上来说是需要有序的.
>   * 查找的数量只能是一个，而不是多个.
> * 区间范围和迭代方式：
>   * 左闭右闭`[left, right]`.
>       * 循环条件要使用`while (left <= right)`.
>       * `if (nums[middle] > target)`，`right`要赋值为`middle - 1`.
>   * 左闭右开`[left, right)`.
>       * 循环条件使用`while (left < right)`.
>       * `if (nums[middle] > target)`，`right`要赋值为`middle`.
> * 查找步骤：
>   1. 确定被查找的范围的左右下标`left`、`right`；
>   2. 根据`left`和`right`，确定中间元素的下标`mid`；
>   3. 根据`mid`锁定的元素，和查找的元素比较，确定新的查找范围的左右下标`left`和`right`.
>   4. 返回`第2步`，循环执行，直至查找到指定元素或循环条件不满足而退出循环.
> * 代码模板：
>   ``` C
>   int BinarySearch(int arr[], int len, int key)
>   {
>   	//确定左右下标.
>   	int left = 0;
>   	int right = len - 1;
>   	while (left <= right)
>   	{
>   		//确定中间元素的下标.
>   		int mid = (left + right) / 2;
>   		//根据中间元素的值与被查找的元素的值的大小比较，调整产生新的左右下标.
>   		if (arr[mid] == key)
>   		{
>   			//break跳出.
>   			return mid;
>   		}
>   		else if (arr[mid] < key)
>   		{
>   			left = mid + 1;
>   		}
>   		else
>   		{
>   			right = mid - 1;
>   		}
>   	}
>   	return -1;
>   }
>   ```
> * 算法的时间复杂度：
>   * `logn`.

``` C
    #include <stdio.h>
    int BinarySearch(int arr[], int len, int key);
    int main()
    {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int len = sizeof(arr) / sizeof(arr[0]);
        int index = BinarySearch(arr, len, 7);
        if (index == -1)
        {
            printf("找不到！");
        }
        else
        {
            printf("找到了，指定元素在数组中的下标为：%d\n", index);
        }
        return 0;
    }

    int BinarySearch(int arr[], int len, int key)
    {
        //确定左右下标.
        int left = 0;
        int right = len - 1;
        while (left <= right)
        {
            //确定中间元素的下标.
            int mid = (left + right) / 2;
            //根据中间元素的值与被查找的元素的值的大小比较，调整产生新的左右下标.
            if (arr[mid] == key)
            {
                //break跳出.
                return mid;
            }
            else if (arr[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
```

> 小技巧：
> * 计算**数组的长度**：
>   * `int len = sizeof(arr) / sizeof(arr[0]);`.
>       * 如果计算字符数组的长度，`sizeof()`计算的是**包含字符串结束标志`\0`的长度**.
>       * 因此计算字符数组长度最好使用`strlen()函数`.

* 练习四

题目： 编写代码，演示多个字符从两端移动，向中间汇聚。

``` C
    #include <stdio.h>
    #include <string.h>
    //Sleep()需要一个<windows.h>头文件：
    #include <windows.h>
    int main()
    {
        char arr1[] = "welcome to bit!!!!!";
        char arr2[] = "###################";
        int left = 0;
        int right = strlen(arr1) - 1;

        while (left <= right)
        {
            arr2[left] = arr1[left];
            arr2[right] = arr1[right];
            printf("%s\n", arr2);
            //休息一秒后唤醒：
            Sleep(1000);	//单位是毫秒.
            //执行系统命令：
            system("cls");	//清理屏幕.
            left++;
            right--;
        }
        printf("%s\n", arr2);
        return 0;
    }
```

> 注意：
> * `Sleep()函数`：
>   * 传参：
>       * 传入欲使程序休息的时间，单位是**毫秒**.
>   * 功能：
>       * 使程序休息指定时间后唤醒.
>   * 位置：
>       * 包含在库`<windows.h>`中.
> * `system()函数`：
>   * 传参：
>       * 传入欲执行的指令.
>   * 功能：
>       * 使程序执行`Windows OS`中的指令.
>   * 位置：
>       * 包含在库`<windows.h>`中.

* 练习五

题目： 编写代码实现，模拟用户登录情景，并且只能登录三次。（只允许输入三次密码，如果密码正确则提示登录成，如果三次均输入错误，则退出程序。

``` C
    #include <stdio.h>
    #include <string.h>
    int main()
    {
        int i = 0;
        char password[20] = { 0 };
        for (i = 0; i < 3; i++)
        {
            printf("请输入密码：>\n");
            scanf("%s", password);
            //判断密码是否正确：
            if (strcmp(password, "123456") == 0)
            {
                printf("登录成功！\n");
                break;
            }
            else
            {
                printf("密码错误！\n");
            }
        }
        if (i == 3)
            printf("退出程序！\n");
        return 0;
    }
```

> 注意：
> * 两个字符串比较相等是不能用 `==` 的.
> * 应该用库函数`strcmp()`.
>   * `strcmp()`返回`0`，表示两个字符串相等；
>   * `strcmp()`返回`大于0`的数字，表示第一个字符串大于第二个字符串.
>   * `strcmp()`返回`小于0`的数字，表示第一个字符串小于第二个字符串.
>       * 字符串比较大小的原则：比较对应位置上的字符的`ASCII码`值.

> 注意：
> * `scanf()`函数在读取从键盘输入程序的字符串到字符数组中时，会将用户输入的字符串的结束标志`\0`**一并读入字符数组中**.
>   ``` C
>   int main()
>   {
>       char arr[] = "xxxxxxxxxx";
>       scanf("%s", arr);
>       return 0;
>   }
>   ```
>   * 输入：`abc\n`.
>   * 输出：
>       * 字符数组`arr`中的字符元素为：
>           ![调试窗口中字符数组`arr`中的字符元素](./assets/20230605175025.png)
>
>   可见输入字符串的结束标志`\0`也被包括在字符数组`arr`中.

### 3.5 猜数字游戏实现

> 猜数字游戏：
> * 电脑会随机生成一个数字.
> * 用户对生成的数字进行猜测：
>   * 猜大了，提醒用户猜大了，继续猜.
>   * 猜小了，提醒用户猜小了，继续猜.
>   * 猜对了，提示“恭喜你，猜对了”，结束游戏.
> * 玩完一把之后不过瘾，可以继续玩而不需要退出程序.

``` C
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void menu()
    {
        printf("**********************************\n");
        printf("*********** 1.    play ***********\n");
        printf("*********** 0.    exit ***********\n");
        printf("**********************************\n");
    }
    void game()
    {
        //1. 生成随机数.
        int ret = rand() % 100 + 1;
        //2. 猜数字.
        int guess = 0;
        while (1)
        {
            printf("请猜数字：>\n");
            scanf("%d", &guess);
            if (guess > ret)
            {
                printf("猜大了！\n");
            }
            else if (guess < ret)
            {
                printf("猜小了！\n");
            }
            else
            {
                printf("恭喜你，猜对了！\n");
                break;
            }
        }
    }

    int main()
    {
        /* 打印游戏菜单. */
        //1. 玩游戏.
        //0. 退出游戏.
        int choice = 0;
        //对rand()函数进行设置随机起点，对其进行初始化处理.
        srand((unsigned int)time(NULL));

        do
        {
            menu();
            printf("请选择：>\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("猜数字游戏\n");
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误\n");
                break;
            }
        } while (choice);


        return 0;
    }
```

> `rand(void)`函数：
> * 函数声明：
>   * `int rand(void);`.
> * 函数所在位置：
>   * 包含于库`<stdlib.h>`中.
> * 功能：
>   * 生成随机数.
> * 返回值类型：
>   * 返回介于`0`到`RAND_MAX`之间的伪随机整数.
>       * `RAND_MAX`：`0x7fff`（即`32767`）.
> * 使用方法：
>   * 在调用`rand()`函数之前，需要先调用函数`srand()`对随机数进行随机化：要给`srand()`传递一个变化的值——**计算机上的时间**，即**时间戳**.
>   * `srand()`在一个工程文件中只需要调用一次对`rand()`函数进行初始化即可，不需要频繁大量地调用`srand()`函数，否则生成的随机数不够随机.
>   * `srand((unsigned int)time(NULL))`.
>       * 时间戳：`Unix`时间戳是指从`1970年1月1日`（`UTC/GMT`的午夜）开始所经过的秒数，不考虑闰秒.
>       * `time(NULL)`函数位于库`<time.h>`中，会返回一个时间戳，其返回值类型为`time_t`，即`long long int`类型的整型.

### 3.6 求最大公约数实现

==方法一：== 暴力枚举法.

``` C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main()
    {
        int m = 0;
        int n = 0;
        scanf("%d %d", &m, &n);
        //计算.
        int k = (m > n ? m : n);
        while (1)
        {
            if (m % k == 0 && n % k == 0)
            {
                break;
            }
            k--;
        }
        printf("%d和%d的最大公约数为：%d\n", m, n, k);
        return 0;
    }
```

==方法二：== 辗转相除法.

``` C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main()
    {
        int m = 0;
        int n = 0;
        scanf("%d %d", &m, &n);	//18 24.
        int m_pre = m;
        int n_pre = n;
        //计算.
        int k = 0;
        while (k = m % n)
        {
            m = n;
            n = k;
        }
        printf("%d和%d的最大公约数为：%d\n", m_pre, n_pre, n);
        return 0;
    }
```

### 3.7 素数求解实现

> 素数（质数）：
> * 定义：
>   * 只能被`1`和它本身整除的数是素数（质数）.
> * 判断方法（==试除法==）：
>   * `2 ~ i-1` 之间的数字去试除`i`，如果能整除则`i`不是素数.
>   * `2 ~ i-1` 之间的数字都不能整除`i`，则`i`是素数.

> 推荐博文：`《素数求解的N种境界》`.

==实现方式一：==

> 思路：
> 通过枚举从`2`到`i - 1`的所有因子并进行试除，从而找出素数（质数）.

``` C
    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        /* 打印 100 - 200 之间的素数实例. */
        int i = 0;
        int count = 0;
        for (i = 100; i <= 200; i++)
        {
            //判断i是否为素数：
            int j = 0;
            int flag = 1;	//假设i是素数.
            for (j = 2; j <= i - 1; j++)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                printf("%d ", i);
                count++;
            }
        }
        printf("\ncount = %d\n", count);

        return 0;
    }
```

==实现方式二：==

> 思路：
> 由于偶数不可能为素数（偶数一定包含组成因子`2`），因此可从`101`开始使用试除法判断是否为素数，并且设置枚举步长为`2`使得枚举到的待判断数据均为奇数.

``` C
    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        int i = 0;
        int count = 0;
        for (i = 101; i <= 200; i += 2)
        {
            //判断i是否为素数：
            int j = 0;
            int flag = 1;	//假设i是素数.
            for (j = 2; j <= i - 1; j++)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                printf("%d ", i);
                count++;
            }
        }
        printf("\ncount = %d\n", count);

        return 0;
    }
```

==实现方式三：==

> 思路：
> 对于某一数据`k`的组成因子`m`和`n`（即`k = m * n`），在以上实现方式中，`m`和`n`总会出现以不同的顺序被重复枚举的情况（即`k = m * n`和`k = n * m`均被枚举）；因此可以设置被枚举因子的范围为`[2, sqrt(k)]`，即可省去无用的重复枚举.

``` C
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    int main()
    {
        int i = 0;
        int count = 0;
        for (i = 101; i <= 200; i += 2)
        {
            //判断i是否为素数：
            int j = 0;
            int flag = 1;	//假设i是素数.
            for (j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                printf("%d ", i);
                count++;
            }
        }
        printf("\ncount = %d\n", count);

        return 0;
    }
```

> `sqrt(num)`函数：
> * 功能：
>   * 对`num`进行开平方运算并返回计算结果.
> * 位置：
>   * `sqrt()`是库函数，被包含在头文件`<math.h>`中.

---

## 四、`goto`语句

C语言中提供了可以随意滥用的`goto`语句和标记跳转的标号.

从理论上讲，`goto`语句是没有必要的，实践中没有`goto`语句也可以很容易的写出代码.

但是某些场合下`goto`语句还是用得着的，最常见的用法就是终止程序在某些深度嵌套的结构的处理过程.
* 例如：一次跳出两层或多层循环.

多层循环这种情况使用`break`是达不到目的的，它只能从最内层循环退出到上一层的循环.

`goto`语言真正适合的场景如下：

``` C
    for(...)
        for(...)
    {
            for(...)
        {
                if(disaster)
                    goto error;
        }
    }

        ...

    error:
    if(disaster)
            // 处理错误情况
```

> 注意：
> * `goto`语句只能在同一函数内部跳转，不可以跨函数使用！

下面是使用`goto`语句的一个例子，然后使用循环的实现方式替换`goto`语句：

``` C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /* 关机程序. */
        //1. 程序运行起来后，1分钟内电脑关机.
        //2. 如果输入“我是猪”，就取消关机.

    int main()
    {
        char input[20] = { 0 };
        /* 关机程序. */
        //1. 程序运行起来后，1分钟内电脑关机.
        //2. 如果输入“我是猪”，就取消关机.
        //程序倒计时关机.
        system("shutdown -s -t 60");

    again:
        printf("请注意，你的电脑在1分钟内关机；如果输入“我是猪”，就取消关机！\n");
        scanf("%s", input);	//输入.
        if (strcmp(input, "我是猪") == 0)
        {
            system("shutdown -a");
        }
        else
        {
            goto again;
        }
        return 0;
    }
```

而如果不适用`goto`语句，则可以使用循环：

``` C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /* 关机程序. */
        //1. 程序运行起来后，1分钟内电脑关机.
        //2. 如果输入“我是猪”，就取消关机.

    int main()
    {
        char input[20] = { 0 };
        /* 关机程序. */
        //1. 程序运行起来后，1分钟内电脑关机.
        //2. 如果输入“我是猪”，就取消关机.
        //程序倒计时关机.
        system("shutdown -s -t 60");

        while (1)
        {
            printf("请注意，你的电脑在1分钟内关机；如果输入“我是猪”，就取消关机！\n");
            scanf("%s", input);	//输入.
            if (strcmp(input, "我是猪") == 0)
            {
                system("shutdown -a");
                break;
            }
        }
        
        return 0;
    }
```

> 注意：
> * char是字符类型.字符的本质是字符的ASCII码值，而ASCII码值是整型；所以字符类型在归类的时候，是可以划分到整型家族的.