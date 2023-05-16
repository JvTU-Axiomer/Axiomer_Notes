# 第三讲：循环结构

> 人的时间应该花在创造程序上，而不是像程序一样去做重复性的工作.
>                           ——yxc

**目录：**

[TOC]

---

## 一、1.2 题目讲解

### 1.1 例题讲解

#### 1.1.1 例题 1

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
        {
            printf("O JOGO DUROU %d HORA(S)\n", b - a);
        }
        else if (a > b)
        {
            printf("O JOGO DUROU %d HORA(S)\n", 24 - a + b);
        }
        else
        {
            printf("O JOGO DUROU 24 HORA(S)\n");
        }
        return 0;
    }
```

> C++只有一个标准，但是有很多种不同的版本.

#### 1.1.2 例题 2

``` C++

```

> `float`的有效数字位数只有6-7位，`double`的有效数字位数为15-16位.所以在比赛过程中，除非有空间限制，否则最好用`duble`.

> 保留0位小数的格式化输出：`%.0lf`.

> 转义字符：`\` + `要转移的字符`.
    > * 转义回车：`\n`.
    > * 转义百分号：`%%`.
    > * 转义反斜杠：`\\`.
    > * 转义单引号：`\'`.

#### 1.1.3 例题 3

``` C++
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <cstdio>
    #include <iostream>
    #include <string.h>
    using namespace std;
    int main()
    {
        char a1[100] = { 0 };
        char a2[100] = { 0 };
        char a3[100] = { 0 };
        scanf("%s", a1);
        getchar();
        scanf("%s", a2);
        getchar();
        scanf("%s", a3);
        getchar();
        if (strcmp(a1, "vertebrado") == 0)
        {
            if (strcmp(a2, "ave") == 0)
            {
                if (strcmp(a3, "carnivoro") == 0)
                {
                    cout << "aguia" << endl;
                }
                else if (strcmp(a3, "onivoro") == 0)
                {
                    cout << "pomba" << endl;
                }
            }
            else if (strcmp(a2, "mamifero") == 0)
            {
                if (strcmp(a3, "onivoro") == 0)
                {
                    cout << "homem" << endl;
                }
                else if (strcmp(a3, "herbivoro") == 0)
                {
                    cout << "vaca" << endl;
                }
            }
        }
        else if (strcmp(a1, "invertebrado") == 0)
        {
            if (strcmp(a2, "inseto") == 0)
            {
                if (strcmp(a3, "hematofago") == 0)
                {
                    cout << "pulga" << endl;
                }
                else if (strcmp(a3, "herbivoro") == 0)
                {
                    cout << "lagarta";
                }
            }
            else if (strcmp(a2, "anelideo") == 0)
            {
                if (strcmp(a3, "hematofago") == 0)
                {
                    cout << "sanguessuga" << endl;
                }
                else if (strcmp(a3, "onivoro") == 0)
                {
                    cout << "minhoca" << endl;
                }
            }
        }
        return 0;
    }
```

==判断字符串是否相等的方式：==

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        string a;
        if (a == "inseto")
        {
            cout << "lagarta" << endl;
        }
        return 0;
    }
```

> `puts()`只能输出字符串，遇到`\0`就结束了，而且不可以格式化输出字符串.

### 1.2 习题讲解

#### 1.2.1 习题1

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b > c && d > a && (c + d) > (a + b) && c > 0 && d > 0 && a % 2 == 0)
        {
            printf("Valores aceitos\n");
        }
        else
        {
            printf("Valores nao aceitos\n");
        }
        return 0;
    }
```

#### 1.2.2 习题2

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int x;
        cin >> x;
        if (x == 61) cout << "Brasilia";
        else if (x == 71) cout << "Salvador";
        else if (x == 11) cout << "Sao Paulo";
        else if (x == 21) cout << "Rio de Janeiro";
        else if (x == 32) cout << "Juiz de Fora";
        else if (x == 19) cout << "Campinas";
        else if (x == 27) cout << "Vitoria";
        else if (x == 31) cout << "Belo Horizonte";
        else cout << "DDD nao cadastrado";
        return 0;
    }
```

#### 1.2.3 习题3

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double x, y;
        cin >> x >> y;
        if (x > 0 && y > 0) cout << "Q1";
        else if (x > 0 && y < 0) cout << "Q4";
        else if (x < 0 && y > 0) cout << "Q2";
        else if (x < 0 && y < 0) cout << "Q3";
        else if (!x && y != 0) cout << "Eixo Y";
        else if (x != 0 && !y) cout << "Eixo X";
        else cout << "Origem";
        return 0;
    }
```

#### 1.2.4 习题4

``` C++
    int main()
    {
        //排序：
        if (b > a)
        {
            double t = a;
            a = b;
            b = t;
        }
        if (c > a)
        {
            double t = a;
            a = c;
            c = t;
        }
        if (c > b)
        {
            double t = b;
            b = c;
            c = t;
        }
        //分情况讨论：
        if (a >= b + c)
        {
            cout << "NAO FORMA TRIANGULO" << endl;
        }
        else {
            if (a * a == b * b + c * c)
            {
                cout << "TRIANGULO RETANGULO" << endl;
            }
            if (a * a > b * b + c * c)
            {
                cout << "TRIANGULO OBTUSANGULO" << endl;
            }
            if (a * a < b * b + c * c)
            {
                cout << "TRIANGULO ACUTANGULO" << endl;
            }
            if (a == b && b == c)
            {
                cout << "TRIANGULO EQUILATERO" << endl;
            }
            else if (a == b && a != c || a == c && a != b || b == c && a != b)
            {
                cout << "TRIANGULO ISOSCELES" << endl;
            }
        }

        return 0;
    }
```

> `swap()`和`sort()`函数也可以实现排序功能.

#### 1.2.5 习题5

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y;
        //开始时间：
        x = a * 60 + b;
        //结束时间：
        y = c * 60 + d;
        int ret;
        int h, m;
        if (x > y)
        {
            ret = 24 * 60 - x + y;
            h = ret / 60;
            m = ret % 60;
        }
        else if (x < y)
        {
            ret = y - x;
            h = ret / 60;
            m = ret % 60;
        }
        else
        {
            h = 24;
            m = 0;
        }
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, m);
        return 0;
    }
```

#### 1.2.6 习题6

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double salary;
        cin >> salary;
        double res = 0;
        double y = 0;
        if (salary > 2000)
        {
            y = 3000;
            if (salary <= 3000) y = salary;
            res += (y - 2000) * 0.08;
        }
        if (salary > 3000)
        {
            y = 4500;
            if (salary <= 4500) y = salary;
            res += (y - 3000) * 0.18;
        }
        if (salary > 4500)
            res += (salary - 4500) * 0.28;
        if (res == 0) printf("Isento\n");
        else printf("R$ %.2lf\n", res);
        return 0;
    }
```

#### 1.2.7 习题7

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a, b, c;
        int x, y, z;
        cin >> a >> b >> c;
        x = a;
        y = b;
        z = c;
        //排序：
        if (a > b)
        {
            int t = a;
            a = b;
            b = t;
        }
        if (a > c)
        {
            int t = a;
            a = c;
            c = t;
        }
        if (b > c)
        {
            int t = b;
            b = c;
            c = t;
        }
        //输出：
        cout << z << endl;
        cout << y << endl;
        cout << x << endl;
        cout << "" << endl;
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        return 0;
    }
```

==对三个数降序排列的方法：==

``` C++
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }
    if (a > c)
    {
        int t = a;
        a = c;
        c = t;
    }
    if (b > c)
    {
        int t = b;
        b = c;
        c = t;
    }
```

#### 1.2.8 习题8

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cmath>
    using namespace std;
    int main()
    {
        double a, b, c;
        double ret1, ret2;
        cin >> a >> b >> c;
        double mid = b * b - 4 * a * c;
        if (a == 0 || mid < 0)
        {
            cout << "Impossivel calcular" << endl;
        }
        else
        {
            ret1 = (-1 * b + sqrt(mid)) / (2 * a);
            ret2 = (-1 * b - sqrt(mid)) / (2 * a);
            printf("R1 = %.5lf\n", ret1);
            printf("R2 = %.5lf\n", ret2);
        }
        return 0;
    }
```

> `b`的负数可以直接写为`-b`.

#### 1.2.9 习题9

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double a, b, c, d;
        double y;
        double x;
        cin >> a >> b >> c >> d;
        x = (a * 2 + b * 3 + c * 4 + d * 1) / 10;
        printf("Media: %.1lf", x);
        if (x >= 7)
        {
            cout << "Aluno aprovado." << endl;
        }
        else if (x < 5)
        {
            cout << "Aluno reprovado." << endl;
        }
        else
        {
            cout << "Aluno em exame." << endl;
            cin >> y;
            printf("Nota do exame: %.1lf\n", y);
            x = (x + y) / 2.0;
            if (x >= 5)
            {
                cout << "Aluno aprovado." << endl;
            }
            else
            {
                cout << "Aluno reprovado." << endl;
            }
            printf("Media final: %.1lf\n", x);
        }
        return 0;
    }
```

> `Ctrl` + `Alt` 可以创造多个光标并行输入.

---

## 二、循环结构

* 循环
  * `while`循环
    * `while`
    * `do...while`
  * `for`循环

### 2.1 `while`循环

`while`循环可以简单理解为循环版的`if`语句.`if`语句是判断一次，如果条件成立，则执行后面的语句；`while`是每次判断，如果成立，则执行循环体中的语句，否则停止.

**死循环**：循环永久执行，无法结束。我们要避免写出死循环.

#### 2.1.1 `while`循环的基本格式

``` C++
while (判断条件)
{
    循环体.
}
```

**代码示例：**

``` C++
    #include <iostream>

    using namespace std;

    int main()
    {
        int i = 0;

        //while循环语句：
        i = 0;
        while (i < 10)
        {
            cout << i << endl;
            i++;
        }
        return 0;
    }
```

#### 2.1.2 `while`循环的基本练习

* 练习一

题目：求1~100中所有数的立方和。

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int i = 0;
        int sum = 0;
        while (i <= 100)
        {
            sum = sum + i * i * i;
            i++;
        }
        cout << sum << endl;

        return 0;
    }
```

> 立方和公式：平方和公式的平方（利用杨辉三角递推推导）.  

* 练习二

题目：求斐波那契数列的第n项。f(1) = 1, f(2) = 1, f(3) = 2, f(n) = f(n-1) + f(n-2)。

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int a = 1;
        int b = 1;
        int n;
        cin >> n;

        int i = 0;
        while (i < n - 1)
        {
            int c = a + b;
            a = b;
            b = c;
            i++;
        }
        cout << a << endl;
        return 0;
    }
```

> * 斐波那契数列
>   * 需要两个变量，分别存当前所求项的前两项.
>       * `(a, b)-->(b, c)`：
>           * `c = a + b;`
>           * `a = b;`
>           * `b = c;`

> 递归效率是指数级别的，所以循环比递归运行更快.

### 2.2 `do...while`循环

`do while`循环不常用。`do while`语句与`while`语句非常相似，唯一的区别是：`do while`语句先执行循环体后检查条件，因此不管条件的值如何，`do...while`都要至少执行一次循环；而`while`循环可能一次都不执行循环；但是只要第一次循环的判断条件二者都成立，那么二者完全一样.

#### 2.2.1 `do...while`循环的基本格式

``` C++
do
{
    循环体.
} while (判断条件);
```

**代码示例：**

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int s = 0;
        int i = 1;
        do
        {
            s += i;
            i++;
        } while (i <= 10);
        cout << s << endl;
        return 0;
    }
```

### 2.3 `for`循环

基本思想：把控制循环次数的变量从循环体中剥离.

#### 2.3.1 `for`循环的基本格式

``` C++
for (init-statement; condition; expression)
{
    循环体.
}
```

* `init-statement`
  * 可以是声明语句、表达式、空语句，一般用来初始化循环变量.
  * 只能写一句话.
  * 可以定义多个变量，变量之间用逗号隔开.
* `condition`
  * 条件表达式，和`while`中的条件表达式作用一样；可以为空，空语句表示`true`.
* `expression`
  * 一般负责修改循环变量，可以为空.
  * 可以修改多个变量，表达式之间用逗号隔开.

**`for`循环执行规则：**

先执行且只执行一次初始化语句，之后判断条件是否成立：
* 如果条件不成立，则跳出循环；
* 如果条件成立，则进入循环体执行，每次循环体结束时都会执行表达式来修改变量，之后再判断条件是否成立：
  * 如果条件不成立，则跳出循环；
  * 如果条件成立，则再次进入循环体执行，重复上述循环过程.
    * 直到条件不满足，则跳出循环.

**注意：** `for`循环的小括号之后不能加分号，否则认为是空语句执行循环！

**代码示例：**

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        for (int i = 1; i <= 10; i++)
        {
            cout << i << endl;
        }
        return 0;
    }
```

> `for`循环中创建的变量`i`只能在循环中使用，出了`for`循环则变量`i`不能再被使用.

#### 2.3.2 `for`循环的基本练习

* 练习一

题目：求1~100中所有数的立方和。

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int s = 0;
        for (int i = 1; i <= 100; i++)
        {
            s += i * i * i;
        }
        cout << s << endl;
        return 0;
    }
```

* 练习二

题目：求斐波那契数列的第n项。f(1) = 1, f(2) = 1, f(3) = 2, f(n) = f(n-1) + f(n-2)。

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int n = 0;
        int a = 1;
        int b = 1;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        cout << a << endl;
        return 0;
    }
```

### 2.4 跳转语句

* `break`语句
  * 跳出语句所在循环.
* `continue`语句
  * 跳过语句之后的循环体，直接执行下一次循环.

#### 2.4.1 `break`语句

可以提前从循环中退出，一般与`if`语句搭配.

**注意：** 只能`break`一层循环.

**代码示例：**

判断一个大于1的数是否是质数:

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int n;
        cin >> n;

        bool is_prime = true;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                is_prime = false;
                cout << i << endl;
                break;
            }
        }
        if (is_prime == true) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
```

#### 2.4.2 `cintinue`语句

可以直接跳到当前循环体的结尾，作用与`if`语句类似.

**代码示例：**

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int sum = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (i % 2 != 0) continue;
            sum += i;
        }
        cout << sum << endl;
        return 0;
    }
```

> 在`for`循环中，`break`会直接跳出循环，不执行最后的表达式；而`continue`会跳过当前循环体之后的语句，但是仍然会执行当前循环最后的表达式.

### 2.5 多重循环

* 示例一

题目：输出一个矩阵表。

``` C++
    #include <iostream>
    #include <cstdio>
    using namespace std;
    int main()
    {
        int n = 0;
        cin >> n;
        for (int i = 1, k = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++, k++)
            {
                printf("%-5d", k);
            }
            cout << endl;
        }
        return 0;
    }
```

* 示例二

题目：打印1~1000中的所有质数。

``` C++
    #include <iostream>
    #include <cstdio>
    using namespace std;
    int main()
    {
        for (int i = 2; i <= 1000; i++)
        {
            bool is_prime = true;
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime == true) cout << i << ' ';
        }
        return 0;
    }
```

> 函数`abs()`：取绝对值.

* 示例三

题目：输入一个n，打印n阶菱形，n是奇数。

> 巧技：曼哈顿距离.
> 每个格子距离中心点的横坐标之差的绝对值和纵坐标之差的绝对值之和（即只能横向和纵向走的话，能够到达中心点时所走的步数）如果小于等于`n / 2`，则输出`*`；否则输出`空格符`.

> 曼哈顿距离：
> `s = |x2 - x1| + |y2 - y1|`.

``` C++
    #include <iostream>
    #include <cstdio>
    using namespace std;
    int main()
    {
        int n;
        cin >> n;
        int cx = n / 2;
        int cy = n / 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(i - cx) + abs(j - cy) <= n / 2)
                {
                    cout << '*';
                }
                else
                {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        return 0;
    }
```

* 示例四

题目：输入一个n，打印n阶空心菱形，n是奇数。

``` C++
    #include <iostream>
    #include <cstdio>
    using namespace std;
    int main()
    {
        int n;
        cin >> n;
        int cx = n / 2;
        int cy = n / 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(i - cx) + abs(j - cy) == n / 2)
                {
                    cout << '*';
                }
                else
                {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        return 0;
    }
```

### 2.6 课堂练习

* 练习一

题目：编写一个程序，输出1到100之间（包括1和100）的全部偶数。

``` C++
    #include <iostream>
    #include <cstdio>
    using namespace std;
    int main()
    {
        for (int i = 2; i <= 100; i += 2)
        {
            cout << i << endl;
        }
        return 0;
    }
```

* 练习二

题目：输入一个整数X，输出1到X之间（包括1和X）的全部奇数。

``` C++
    #include <iostream>
    #include <cstdio>
    using namespace std;
    int main()
    {
        int x;
        cin >> x;
        for (int i = 1; i <= x; i += 2)
        {
            cout << i << endl;
        }
        return 0;
    }
```

* 练习三

题目：输入6个实数，它们要么是正数，要么是负数，请统计并输出正数的个数。

``` C++
    #include <iostream>
    #include <cstdio>
    using namespace std;
    int main()
    {
        int count = 0;
        for (int i = 0; i < 6; i++)
        {
            double x;
            cin >> x;
            if (x > 0)
            {
                count++;
            }
        }
        cout << count << " positive numbers" << endl;
        return 0;
    }
```

* 练习四

题目：给定两个整数X和Y，输出在他们之间（不包括X和Y）的所有奇数的和。

``` C++
    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
        {
            swap(x, y);
        }
        int sum = 0;
        int i = x + 1;
        while (i < y)
        {
            if (i % 2 == 1)
            {
                sum++;
            }
            i++;
        }
        cout << sum << endl;
        return 0;
    }
```

> 函数`swap()`：
> * 功能：交换两个数.
> * 所属库：`<algorithm>`.

* 练习五

题目：给定100个整数，请你找出其中最大的数字，以及它的输入位置（位置从1开始）。

``` C++
    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int max_value = 0;
        int position = -1;
        for (int i = 1; i <= 100; i++)
        {
            int value;
            cin >> value;
            if (value > max_value)
            {
                max_value = value;
                position = i;
            }
        }
        cout << max_value << endl << position << endl;
        return 0;
    }
```

* 练习六

题目：读取一系列的整数X，对于每个X，输出一个1,2,…,X的序列。

==第一种输入方式：==

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int x = 0;
        while (true)
        {
            cin >> x;
            if (!x)
            {
                break;
            }
            for (int i = 1; i <= x; i++)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
        return 0;
    }
```

==第二种输入方式：==

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int x = 0;
        while (cin >> x && x)
        {
            for (int i = 1; i <= x; i++)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
        return 0;
    }
```

> `cin`函数本身有返回值：如果返回`逻辑0`（`false`），则读到了文件结束的位置（即`文件结束符EOF`，也即`文件结束-1标志`）.

==第三种输入方式：==

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int x = 0;
        while (cin >> x, x)
        {
            for (int i = 1; i <= x; i++)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
        return 0;
    }
```

> 逗号表达式：
> * 用逗号隔开的表达式叫做逗号表达式.
> * 逗号表达式的值等于最后一个表达式的值.
> * 逗号表达式只能用在逻辑表达式中.
>
> 示例用法：
>   ``` C++
>       if (x, y)   //这里条件判断y的值.
>       {
>           循环体.
>       }
>   ```
>
>   ``` C++
>       return x += 6, 0;   //可以正常结束程序.
>   ```
> 反例用法：
>   ``` C++
>       //这不是一个逻辑表达式，所以逗号表达式的规则在这里不适用.
>       x = a, b;   //这里x的值为a.
>   ```
> 注意区分使用逗号的场景是逻辑表达式还是算术表达式，只有逻辑表达式中使用的逗号才符合逗号表达式的规则.

==第四种输入方式：==

``` C++
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int x = 0;
        while (~scanf("%d", &x) && x)
        {
            for (int i = 1; i <= x; i++)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
        return 0;
    }
```

> `scanf()`函数本身有返回值，返回输入数据的个数；如果返回`-1`，则读到了`文件结束位置`.

> `~`：按位取反位运算符.