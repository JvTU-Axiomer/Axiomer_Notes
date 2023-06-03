# 第二讲：printf语句与C++中的判断语句

---

**目录：**

[TOC]

---

## 一、1.1 题目讲解

### 1.1 例题讲解

#### 1.1.1 例题 1

``` C++
    #include <iostream>

    using namespace std;

    int main()
    {
        

        int a, b; //定义两个变量
        cin >> a >> b;	//输入
        cout << a + b << endl;	//输出

        return 0;
    }
```

> `cout` : cpp standard out.
> `cin` : cpp standard in.

> 万能头文件：`#include <bits/stdc++.h>`.

#### 1.1.2 例题 2

``` C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        cout << "DIFERENCA = " << (A * B - C * D) << endl;
    }
```

> `scanf()`函数可以把输入中的空格和回车全部过滤掉.
> 99%的评测器：会自动过滤掉最后一个回车和每一行结尾的空格.

> Presentation Error : 展示错误（程序输出中间多出空格或缺少空格）.

> 编译速度：`cstdio` > `iostream` > `bits/stdc++.h`.

#### 1.1.3 例题 3

``` C++
    #include <cstdio>
    #include <iostream>

    using namespace std;

    int main()
    {
        double R = 0;
        double S = 0;
        cin >> R;
        S = 3.14159 * R * R;
        printf("A=%.4lf\n", S);

        return 0;
    }
```

> *有效数字位数：*
    float：6-7位.
    double：15-16位.

> 99%的情况下，在算法题中选择double而不选择float，因为double的有效数字位数要多于float.

> C的所有头文件都可以被C++编译，但反之不一定可以.

> *头文件区别：*
    C++ : `cmath`     `cstdio`.
    C   : `math.h`    `stdio.h`.

#### 1.1.4 例题 4

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double A = 0;
        double B = 0;
        double ret = 0;
        cin >> A >> B;
        ret = 3.5 / 11 * A + 7.5 / 11 * B;
        printf("MEDIA = %.5lf", ret);
        
        return 0;
    }
```

#### 1.1.3 例题 5

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int name, hour;
        double money;
        double ret = 0;
        cin >> name >> hour >> money;
        ret = hour * money;
        cout << "NUMBER = " << name << endl;
        printf("SALARY = U$ %.2lf", ret);
        return 0;
    }
```

> 如果只用到了`scanf()`和`printf()`函数，则不需要加`using spacename std;`.

> 低精度数据和高精度数据做运算时，结果会自动转换为高精度数据类型.

#### 1.1.3 例题 6

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int X = 0;
        double Y = 0;
        double ret = 0;
        cin >> X >> Y;
        ret = 1.0 * X / Y;
        printf("%.3lf km/l", ret);
        
        return 0;
    }
```

> 可以把整数读到浮点数变量中，但是不能把浮点数读到整数变量中，否则可能导致精度损失.

#### 1.1.3 例题 7

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cmath>
    using namespace std;
    int main()
    {
        double x1, x2;
        double y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        double dis = 0;
        dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        printf("%.4lf", dis);
        
        return 0;
    }
```

> ^ 不表示乘方，表示位运算.

> `sqrt(x)`：包含于`cmath`库中，表示对x开根号.

#### 1.1.3 例题 8

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int N = 0;
        cin >> N;
        printf("%d\n", N);
        printf("%d nota(s) de R$ 100,00\n", N / 100);
        N %= 100;
        printf("%d nota(s) de R$ 50,00\n", N / 50);
        N %= 50;
        printf("%d nota(s) de R$ 20,00\n", N / 20);
        N %= 20;
        printf("%d nota(s) de R$ 10,00\n", N / 10);
        N %= 10;
        printf("%d nota(s) de R$ 5,00\n", N / 5);
        N %= 5;
        printf("%d nota(s) de R$ 2,00\n", N / 2);
        N %= 2;
        printf("%d nota(s) de R$ 1,00\n", N / 1);

        return 0;
    }
```

> 对整数除法而言，结果为下取整.

#### 1.1.3 例题 9

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int N = 0;
        cin >> N;
        int hour = 0;
        int minute = 0;
        int second = 0;
        hour = N / 3600;
        N = N % 3600;
        minute = N / 60;
        N = N % 60;
        second = N;
        printf("%d:%d:%d\n", hour, minute, second);
        
        return 0;
    }
```

> 小数（浮点数）没有取模的概念.

### 1.2 习题讲解

#### 1.2.1 习题 1

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;

    int main()
    {
        int x, y;
        int PROD = 0;
        cin >> x >> y;
        PROD = x * y;
        printf("PROD = %d", PROD);
        
        return 0;
    }
```

#### 1.2.1 习题 2

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;

    int main()
    {
        int x1, y1;
        int x2, y2;
        double m1 = 0;
        double m2 = 0;
        cin >> x1 >> y1 >> m1;
        cin >> x2 >> y2 >> m2;
        double x = 0;
        x = y1 * m1 + y2 * m2;
        printf("VALOR A PAGAR: R$ %.2lf", x);
        
        return 0;
    }
```

#### 1.2.1 习题 3

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int R = 0;
        double ret = 0;
        cin >> R;
        ret = 4 / 3.0 * 3.14159 * R * R * R;
        printf("VOLUME = %.3lf", ret);
        return 0;
    }
```

> 两个整数相除，结果为整除（即舍去小数位）.

#### 1.2.1 习题 4

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double a, b, c;
        double ret[5] = {0};
        cin >> a >> b >> c;
        ret[0] = a * c / 2.0;
        ret[1] = 3.14159 * c * c;
        ret[2] = (a + b) * c / 2.0;
        ret[3] = b * b;
        ret[4] = a * b;
        printf("TRIANGULO: %.3lf\n", ret[0]);
        printf("CIRCULO: %.3lf\n", ret[1]);
        printf("TRAPEZIO: %.3lf\n", ret[2]);
        printf("QUADRADO: %.3lf\n", ret[3]);
        printf("RETANGULO: %.3lf\n", ret[4]);
        return 0;
    }
```

#### 1.2.1 习题 5

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double a, b, c;
        double x;
        cin >> a >> b >> c;
        x = 2.0 / 10.0 * a + 3.0 / 10.0 * b + 1.0 / 2.0 * c;
        printf("MEDIA = %.1lf", x);
        return 0;
    }
```

#### 1.2.1 习题 6

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        char name[20];
        double a, b;
        double ret = 0;
        scanf("%s", name);
        cin >> a >> b;
        ret = a + 0.15 * b;
        printf("TOTAL = R$ %.2lf", ret);
        return 0;
    }
```

> 读字符串：
> * 字符串`string`包含在`iostream`库中.
> * 代码模板：
    > `string name;` `cin >> name;`

#### 1.2.1 习题 7

``` C++
    #include <cstdio>
    #include <iostream>
    #include <math.h>
    using namespace std;
    int main()
    {
        int a, b ,c;
        int max = 0;
        cin >> a >> b >> c;
        max = (a + b + abs(a - b)) / 2;
        max = (max + c + abs(max - c)) / 2;
        printf("%d eh o maior", max);
        return 0;
    }
```

> `abs(x)`:返回x的绝对值.

#### 1.2.1 习题 8

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int L = 0;
        int ret = 0;
        cin >> L;
        ret = (int)(L / 30.0 * 60.0);
        printf("%d minutos", ret);
        return 0;
    }
```

> `cout()`在输出数据时，如果数据太大，就会将数据转化为科学计数法保留小数，得到的不是准确的数值.

#### 1.2.1 习题 9

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cstring>
    using namespace std;
    int main()
    {
        double T, S;
        double ret = 0;
        cin >> T >> S;
        ret = T * S / 12.0;
        printf("%.3lf", ret);
        return 0;
    }
```

#### 1.2.1 习题 10

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double m;
        scanf("%lf", &m);
        int n = m * 100;
        
        printf("NOTAS:\n");
        printf("%d nota(s) de R$ 100.00\n", n / 10000);
        n %= 10000;
        printf("%d nota(s) de R$ 50.00\n", n / 5000);
        n %= 5000;
        printf("%d nota(s) de R$ 20.00\n", n / 2000);
        n %= 2000;
        printf("%d nota(s) de R$ 10.00\n", n / 1000);
        n %= 1000;
        printf("%d nota(s) de R$ 5.00\n", n / 500);
        n %= 500;
        printf("%d nota(s) de R$ 2.00\n", n / 200);
        n %= 200;
        printf("MOEDAS:\n");
        printf("%d moeda(s) de R$ 1.00\n", n / 100);
        n %= 100;
        printf("%d moeda(s) de R$ 0.50\n", n / 50);
        n %= 50;
        printf("%d moeda(s) de R$ 0.25\n", n / 25);
        n %= 25;
        printf("%d moeda(s) de R$ 0.10\n", n / 10);
        n %= 10;
        printf("%d moeda(s) de R$ 0.05\n", n / 5);
        n %= 5;
        printf("%d moeda(s) de R$ 0.01\n", n / 1);
        return 0;
    }
```

> 如果题目中有小数取余和取模运算，需要先将浮点数转化成整数，否则将会出现精度问题.

> 浮点数建议用`printf()`函数进行保留位数和输出.

> `%llf` : long double
> `%lf`  : double

#### 1.2.1 习题 11

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int N = 0;
        int yy, mm, dd;
        cin >> N;
        yy = N / 365;
        N = N % 365;
        mm = N / 30;
        N = N % 30;
        dd = N;
        printf("%d ano(s)\n", yy);
        printf("%d mes(es)\n", mm);
        printf("%d dia(s)\n", dd);
        return 0;
    }
```

---

## 二、printf()语句

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double f = 5.123456789;
        printf("%.10lf\n", f);

        int a = 1;
        int b = 23;
        int c = 456;
        double d = 12.45;

        printf("%5d!\n", a);
        printf("%5d!\n", b);
        printf("%5d!\n", c);
        printf("%5.1lf\n", f);
        printf("%05.1lf\n", f);
        printf("%5.1lf\n", f);
        printf("%-5.1lf\n", f);

        printf("%-5d!\n", a);
        printf("%-5d!\n", b);
        printf("%-5d!\n", c);

        printf("%05d!\n", a);
        printf("%05d!\n", a);
        printf("%05d!\n", a);

        return 0;
    }
```

`printf()`语句的格式化输出：

* `printf("%5d\n", a);`表示不足五个字符，在前面补上剩余的空格.
* `printf("%-5d\n", a);`表示不足五个字符，在后面补上剩余的空格.
* `printf("%05d\n", a);`表示不足五个字符，在前面补上剩余位数的0.
* `printf("%5.1lf\n", f);`表示格式化输出宽度为5，不足的位数在前面补上剩余位数的空格，并且保留1位小数的双精度浮点数.
* `printf("%05.1lf\n", f);`表示格式化输出宽度为5，不足的位数在前面补上剩余位数的0，并且保留1位小数的双精度浮点数.
* `printf("%-5.1lf\n", f);`表示格式化输出宽度为5，不足的位数在后面补上剩余位数的空格，并且保留1位小数的双进度浮点数.

> 用于高精度数据的压位应用.

> `wchar_t`   用于存中文

---

## 三、判断结构（if语句结构）

### 3.1 if语句结构的基本格式

`if`语句：当条件成立时，执行某些语句；否则执行另一些语句.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int score;
        cin >> score;
        if (score >= 60)
        {
            cout << "及格！";
            cout << "真棒！";
        }
        else
        {
            cout << "不及格！";
            cout << "别灰心，再接再厉！";
        }

        cout << "结束" << endl;

        return 0;
    }
```

基本结构：

``` C++
if (条件)
{
    //符合条件；
}
else
{
    //不符合条件；
}
```

> `;`表示空语句，因此在`if()`之后和`else`之后不可以加`;`.

> `else`总是与它最近的、还未被匹配的`if`相对应.

> 变量作用域：一个括号里边可以用括号外边的变量，但是一个括号外边不能用括号里边的变量.

### 3.2 if语句结构的变形格式

* 格式1：

``` C++
if (条件)
{
    //符合条件；
}
```

* 格式2：

当只有一条语句时，大括号可以省略：

``` C++
if (条件) 一句话语句;
else (条件) 一句话语句; 
```

``` C++
if (条件) 
    一句话语句;
else (条件)    
    一句话语句; 
```

* 格式3：

``` C++
if (条件)
{
    if (条件)
    {
        //嵌套判断结构；
    }
    else
    {
        //不符合条件；
    }
}
else
{
    //不符合条件；
}
```

* 格式4（if-else级联）：

``` C++
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int grade;
    cin >> grade;
    if (grade >= 85)
    {
        cout << 'A' << endl;
    }
    else    //蕴含着grade < 85
    {
        if (grade >= 70)
        {
            cout << 'B' << endl;
        }
        else    //蕴含着grade < 70
        {
            if (grade >= 60)
            {
                cout << 'C' << endl;
            }
            else    //蕴含着grade < 60
            {
                cout << 'D' << endl;
            }
        }
    }

    return 0;
}
```

> 单引号引起来的表示一个字符，双引号引起来的表示一个字符串.

``` C++
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int grade;
    cin >> grade;
    if (grade >= 85) cout << "A" << endl;
    else if (grade >= 70) cout << 'B' << endl;
    else if (grade >= 60) cout << 'C' << endl;
    else cout << 'D' << endl;
    
    return 0;
}
```

### 3.3 比较运算符（常用的判断方式）

| 比较运算符名称 | 表达式写法 |
| ---- | ---- |
| 大于 | > |
| 小于 | < |
| 大于等于 | >= |
| 小于等于 | <= |
| 等于 | == |
| 不等于 | != |

> 当两个运算符连在一起时（如>=、<=、==、!=），不可以在两个符号之间加空格.

### 3.4 条件表达式

| 条件表达式名称 | 表达式符号 |
| ---- | ---- |
| 与 | && 或 and |
| 或 | \|\| 或 or |
| 非 | ! 或 not |

``` C++
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b && c > b) cout << "" << endl;
    if (a > b || c > d) cout << "" << endl;
    if (!(a > b)) cout << "" << endl;
    if (a > b && (c > d || a > d)) cout << "" << endl;
    if (a > b || c > d && a > d) cout << "" << endl;
    if (a > b || !(c > d && a > d)) cout << "" << endl;

    return 0;
}
```

> `&&`短路原则：如果与表达式第一个条件不满足，后面的条件表达式就不会去执行了.

> 与运算的运算优先级比或运算高.

> 可以将与运算看成乘法运算，将或运算看成加法运算.

### 3.5 课堂练习

* 练习一

题目：输入一个数，输出它的绝对值.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int x;
        cin >> x;
        if (x >= 0)
        {
            cout << x << endl;
        }
        else
        {
            cout << -x << endl;
        }

        return 0;
    }
```

* 练习二

题目：输入一个数，输出两个数中的较大的那个.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            cout << a << endl;
        }
        else
        {
            cout << b << endl;
        }

        return 0;
    }
```

* 练习三

题目：输入三个整数，输出三个数中最大的那个.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a >= b)
        {
            if (a >= c)
            {
                cout << a << endl;
            }
            else
            {
                cout << c << endl;
            }
        }
        else
        {
            if (b >= c)
            {
                cout << b << endl;
            }
            else
            {
                cout << c << endl;
            }
        }

        return 0;
    }
```

或者：

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a >= b && a >= c) cout << a << endl;
        else if (b >= a && b >= c) cout << b << endl;
        else if (c >= a && c >= b) cout << c << endl;

        return 0;
    }
```

* 练习四

题目：简单计算器输入两个数，以及一个运算符+, -, *, /，输出这两个数运算后的结果.当运算符是/，且除数是0时，输出Divided by zero!; 当输入的字符不是+, -, *, /时，输出Invalid operator!.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a, b;
        char c;
        //scanf("%d%d %c", &a, &b, &c);
        cin >> a >> b >> c;
        if (c == '+') cout << a + b << endl;
        else if (c == '-') cout << a - b << endl;
        else if (c == '*') cout << a * b << endl;
        else if (c == '/')
        {
            if (b == 0) cout << "Divided by zero!" << endl;
            else cout << a / b << endl;
        }
        else cout << "Invalid operator!" << endl;

        return 0;
    }
```

* 练习五

题目：判断闰年。闰年有两种情况：
(1) 能被100整除时，必须能被400整除；
(2) 不能被100整除时，被4整除即可.
输入一个年份，如果是闰年输出yes，否则输出no.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int year;
        cin >> year;
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else
        {
            if (year % 4 == 0)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }

        return 0;
    }
```

或者：

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int year;
        cin >> year;
        if (year % 400 == 0 || year % 100 && year % 4 == 0) cout << "yes" << endl;
        else cout << "no" << endl;

        return 0;
    }
```

> 当我们判断一个数是否不等于0时，可以将`!=`去掉.