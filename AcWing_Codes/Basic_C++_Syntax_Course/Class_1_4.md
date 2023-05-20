# 第四讲：数组

> 一个人的心情不是心情函数的数值，而是函数的导数.
>           —— yxc

> 程序 = 逻辑 + 数据，数组是存储数据的强而有力的手段.
>           —— yxc

**目录：**

[TOC]

---

## 一、1.3 题目讲解

### 1.1 例题讲解

#### 1.1.1 例题1

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a = 0;
        cin >> a;
        int n = 0;
        cin >> n;
        while (cin >> n, n <= 0);   //从左到右执行
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + a + i;
        }
        cout << sum << endl;
        return 0;
    }
```

> 一般的逗号表达式是没有值的，只有当它被放在`if`分支、`while`循环、`for`循环的条件判断表达式中，它会从左到右执行，返回值才会是最后一个表达式的值.

#### 1.1.2 例题2

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int n = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << i << endl;
            }
        }
        return 0;
    }
```

#### 1.1.3 例题3

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int n, m;
        cin >> n >> m;
        int k = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++, k++)
            {
                if (j == m)
                {
                    cout << "PUM" << endl;
                }
                else
                {
                    cout << k << ' ';
                }
            }
        }
        return 0;
    }
```

### 1.2 习题讲解

#### 1.2.1 习题1

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int n = 0;
        cin >> n;
        for (int i = 2; i < 10000; i++)
        {
            if (i % n == 2)
            {
                cout << i << endl;
            }
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
        int x = 0;
        cin >> x;
        int cnt = 0;
        if (x % 2 != 0)
        {
            cout << x << endl;
            cnt++;
        }
        while (cnt < 6)
        {
            x++;
            if (x % 2 != 0)
            {
                cout << x << endl;
                cnt++;
            }
        }
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
        int n = 0;
        cin >> n;
        for (int i = 1; i <= 10; i++)
        {
            cout << i << " x " << n << " = " << (i * n) << endl;
        }
        return 0;
    }
```

#### 1.2.4 习题4

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int c_cnt = 0;
        int r_cnt = 0;
        int f_cnt = 0;
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a = 0;
            char ani;
            cin >> a;
            cin >> ani;
            if (ani == 'C')
            {
                c_cnt += a;
            }
            else if (ani == 'R')
            {
                r_cnt += a;
            }
            else
            {
                f_cnt += a;
            }
        }
        int sum = 0;
        sum = c_cnt + r_cnt + f_cnt;
        printf("Total: %d animals\n", sum);
        printf("Total coneys: %d\n", c_cnt);
        printf("Total rats: %d\n", r_cnt);
        printf("Total frogs: %d\n", f_cnt);
        printf("Percentage of coneys: %.2lf %%\n", 1.0 * 100 * c_cnt / sum);
        printf("Percentage of rats: %.2lf %%\n", 1.0 * 100 * r_cnt / sum);
        printf("Percentage of frogs: %.2lf %%\n", 1.0 * 100 * f_cnt / sum);
        return 0;
    }
```

> `scanf()`函数的注意事项：
> * `scanf()`读入一个字符的时候，是不会自动过滤掉空格、回车和制表符的，因此如果使用`scanf()`函数需要手动过滤：
>   * `scanf("%d %c", &k, &t);`
> * `scanf()`函数格式化输入：
>   * `scanf("A = %d, B = %d", &a, &b);`

#### 1.2.5 习题5

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int in_cnt = 0;
        int out_cnt = 0;
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a = 0;
            cin >> a;
            if (a >= 10 && a <= 20)
            {
                in_cnt++;
            }
            else
            {
                out_cnt++;
            }
        }
        cout << in_cnt << " in" << endl;
        cout << out_cnt << " out" << endl;
        return 0;
    }
```

> 循环`n`次的书写技巧：
>   ``` C++
>       while (n -- )
>       {
>           循环体.
>       }
>   ```
> 以上结构表示循环`n`次，`n`可以由输入给定.

#### 1.2.6 习题6

``` C++
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            int y = 0;
            cin >> x >> y;
            if (x > y)
            {
                swap(x, y);
            }
            int sum = 0;
            for (int j = x + 1; j < y; j++)
            {
                if (j % 2 != 0)
                {
                    sum = sum + j;
                }
            }	
            cout << sum << endl;
        }
        return 0;
    }
```

> `while()循环`在读入数据时经常使用.
> `for()循环`在表示逻辑结构时经常使用.

#### 1.2.7 习题7

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a = 0;
        int b = 1;
        int n = 0;
        cin >> n;
        if (n == 1)
        {
            cout << "0";
        }
        else if (n == 2)
        {
            cout << "0 1";
        }
        else
        {
            cout << "0 1 ";
            for (int i = 3; i <= n; i++)
            {
                int c = a + b;
                cout << c << ' ';
                a = b;
                b = c;
            }
        }
        
        return 0;
    }
```

> C++中取模运算注意事项：
> * 正数的模数为正数.
> * 负数的模数为负数.

> 黄金分割比通常与斐波那契数列相关.
> * 斐波那契数列相邻两项的比值在`n`趋向于无穷大时近似于黄金分割比`0.618`.

#### 1.2.8 习题8

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int m, n;
        cin >> m >> n;
        if (m > n)
        {
            int temp = m;
            m = n;
            n = temp;
        }
        while (true)
        {
            int sum = 0;
            if (m <= 0 || n <= 0)
            {
                break;
            }
            else
            {
                for (int i = m; i <= n; i++)
                {
                    sum = sum + i;
                    cout << i << ' ';
                }
                cout << "Sum=" << sum << endl;
            }
            cin >> m >> n;
            if (m > n)
            {
                int temp = m;
                m = n;
                n = temp;
            }
        }
        return 0;
    }
```

#### 1.2.8 习题8

``` C++
    #include <cstdio>
    #include <iostream>
    #include <math.h>
    using namespace std;
    int main()
    {
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            int sum = 1;
            for (int j = 2; j <= sqrt(x); j++)
            {
                if (x % j == 0)
                { 
                    sum = sum + j + x / j;
                }
            }
            if (x == 1)
            {
                cout << "1" << " is not perfect" << endl;
            }
            else if (sum == x)
            {
                cout << x << " is perfect" << endl;
            }
            else
            {
                cout << x << " is not perfect" << endl;
            }
        }
        return 0;
    }
```

> 约数问题优化：
> * 如果`d`为`x`的约数，那么`x / d`也是`x`的约数.
> * 每次枚举较小的约数.
>   * 因此`d <= (x / d)`.
>   * 最多计算`sqrt(n)`次.

> C++有运算速度上限，一秒钟之内最多可以计算`1亿`个数据.

#### 1.2.9 习题9

``` C++
    #include <cstdio>
    #include <iostream>
    #include <math.h>
    using namespace std;
    int main()
    {
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            int flag = 1;
            cin >> x;
            if (x == 1)
            {
                cout << "1 is not prime" << endl;
            }
            else
            {
                for (int j = 2; j <= sqrt(x); j++)
                {
                    if (x % j == 0)
                    {
                        cout << x << " is not prime" << endl;
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) cout << x << " is prime" << endl;
            }
        }
        return 0;
    }
```

> 质数判断问题优化：
> * 如果`d`为`p`的约数，那么`p / d`也是`p`的约数.
> * 每次枚举较小的约数.
>   * 因此`d <= (p / d)`.
>   * 最多枚举`sqrt(p)`次.

#### 1.2.10 习题10

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cmath>
    using namespace std;
    int main()
    {
        int n = 0;
        cin >> n;
        int cx = n / 2;
        int cy = n / 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((abs(i - cx) + abs(j - cy)) <= n / 2)
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

> 涉及知识点：
> * 曼哈顿距离.
> * 绝对值函数`abs()`.

## 二、数组

### 2.1 一维数组

#### 2.1.1 一维数组的定义

`int`类型数组

``` C++
    int a[100], b[10];
```

`double`类型数组

``` C++
    double d[100];
```

`char`类型数组

``` C++
    char c[5];
```

#### 2.1.2 一维数组的初始化方式

* 方式一

``` C++
    //定义一个长度为3的数组.
    int a[3] = {0, 1, 3};
```

* 方式二

``` C++
    //定义一个长度为3的数组.
    int b[] = {0, 1, 1};
```

* 方式三

``` C++
    //定义一个长度为5的数组.
    //后面没有给出的值默认为0.
    int c[5] = {0, 1, 1};
```

* 方式四

``` C++
    //将数组元素全部定义为0的写法.
    int f[10] = { 0 };
```

> 注意：
> * C++的默认栈空间为`1M`.
> * 数组定义位置区别：
>   * 函数内部定义数组：
>       * 未初始化的数组，其元素为随机值.
>       * 如果超出栈空间，会发生段错误.
>           * 解决办法：定义全局变量数组.
>   * 函数外部定义数组（全局变量数组）：
>       * 未初始化的数组，其元素全部为`0`.
>       * 不会发生段错误，因为全局变量数组会开在堆空间中.
>           * 堆空间中的申请位置不会立即开出来，会做一个标记，这个标记指向`0`；只有在使用时才会开辟一块堆空间，开辟的空间数据为`0`.

#### 2.1.3 一维数组的调用方式

``` C++
    #include <iostream>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int a[3] = {0, 1, 2};  // 数组下标从0开始

        cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;

        a[0] = 5;

        cout << a[0] << endl;

        return 0;
    }
```

注意：
* 数组下标一定从`0`开始.

#### 2.1.4 一维数组的练习

* 练习一

题目：使用数组实现求斐波那契数列的第N项。

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int f[100];
        f[0] = 0;
        f[1] = 1;
        int n = 0;
        cin >> n;
        for (int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        cout << f[n] << endl;
        return 0;
    }
```

* 练习二

题目：输入一个n，再输入n个整数，将这n个整数逆序输出。

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a[100];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
        return 0;
    }
```

* 练习三

题目：输入一个n，再输入n个整数。将这个数组顺时针旋转 k(k ≤ n)次，最后将结果输出。旋转一次是指：将最左边的数放到最右边。

==常规做法：==

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a[100];
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        while (k--)
        {
            int t = a[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                a[i + 1] = a[i];
            }
            a[0] = t;
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
        return 0;
    }
```

==技巧做法：==

步骤（分为三部分）：
1. 翻转`a[n]`.
2. 翻转前半部分（下标从`0`到`k - 1`）.
3. 翻转后半部分（下标从`k`到`n - 1`）.

``` C++
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int a[100];
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        reverse(a, a + n);
        reverse(a, a + k);
        reverse(a + k, a + n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
        return 0;
    }
```

> 翻转数组某一部分函数：
> * 函数声明：
>   * `reverse(起始位置, 终止位置的下一个位置)`.
> * 位置：
>   * 存放于库`<algorithm>`中.