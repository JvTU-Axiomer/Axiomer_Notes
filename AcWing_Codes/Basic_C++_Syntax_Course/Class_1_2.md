# 第二讲：printf语句与C++中的判断语句

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

## 二、
