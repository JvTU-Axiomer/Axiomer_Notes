# 第三讲：循环结构

> 人的时间应该花在创造程序上，而不是像程序一样去做重复性的工作.

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

### 2.1 while循环

`while`循环可以简单理解为循环版的`if`语句.`if`语句是判断一次，如果条件成立，则执行后面的语句；`while`是每次判断，如果成立，则执行循环体中的语句，否则停止.

#### 2.1.1 while循环的基本格式

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

#### 2.1.2 while循环的基本练习

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