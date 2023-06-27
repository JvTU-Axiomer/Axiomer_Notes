# 第五讲：字符串

> 字符串是计算机与人类沟通的重要手段.
>           —— yxc

---

**目录：**

[TOC]

---

## 一、1.4 题目讲解

### 1.1 例题讲解

#### 1.1.1 例题1

> 解题思路：
> 寻找规律，查明绿色块处在矩阵中的哪些行中以及在每一行中的起点和终点分别是什么位置.
> * 行号为`0-5`的上半部分：
>   * 行号为`i`，起点为`0`，终点为`i-1`.
> * 行号为`6-10`的下半部分：
>   * 行号为`i`，起点为`0`，终点为`10-i`.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        double m[12][12];
        char t = '0';
        cin >> t;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                cin >> m[i][j];
            }
        }
        double sum = 0;
        int cnt = 0;
        for (int i = 0; i <= 5; i++)
        {
            for (int j = 0; j < i; j++)
            {
                sum += m[i][j];
                sum += m[11 - i][j];
                cnt += 2;
            }
        }
        if (t == 'S')
        {
            printf("%.1lf\n", sum);
        }
        else
        {
            printf("%.1lf\n", sum / cnt);
        }
        return 0;
    }
```

#### 1.1.2 例题2

==常规方法：==

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    #define M 100
    int main()
    {
        int cnt = 0;
        int n = 0;
        cin >> n;
        while (n != 0)
        {
            //将数组全部元素初始化为0.
            int arr[M][M] = { 0 };
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cnt = 0;
                    while (1)
                    {
                        if (i == cnt || i == n - cnt - 1 || j == cnt || j == n - cnt - 1)
                        {
                            arr[i][j] = cnt + 1;
                            break;
                        }
                        cnt++;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            cin >> n;
        }
        return 0;
    }

    /*
    1 1 1 1 1 1 1 1
    1 2 2 2 2 2 2 1
    1 2 3 3 3 3 2 1
    1 2 3 4 4 3 2 1
    1 2 3 4 4 3 2 1
    1 2 3 3 3 3 2 1
    1 2 2 2 2 2 2 1
    1 1 1 1 1 1 1 1
    */
```

==取巧方法：==

> 观察得到，每一个格子的值即为**该格位置到上下左右四条边距离的最小值**.
> 如果取一个`N`阶矩阵，则坐标为`(i, j)`的点到上下左右四条边距离的计算方法：
> * 到上边的距离：
>   * `up = i`.
> * 到下边的距离：
>   * `down = N - i + 1`.
> * 到左边的距离：
>   * `left = j`.
> * 到右边的距离：
>   * `right = N - j + 1`.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    #define M 100
    int main()
    {
        int n;
        while (cin >> n, n)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    int up = i, down = n - i + 1, left = j, right = n - j + 1;
                    cout << min(min(up, down), min(left, right)) << ' ';
                }
                cout << endl;
            }

            cout << endl;
        }
        return 0;
    }

    /*
    1 1 1 1 1 1 1 1
    1 2 2 2 2 2 2 1
    1 2 3 3 3 3 2 1
    1 2 3 4 4 3 2 1
    1 2 3 4 4 3 2 1
    1 2 3 3 3 3 2 1
    1 2 2 2 2 2 2 1
    1 1 1 1 1 1 1 1
    */
```

### 1.2 习题讲解

#### 1.2.1 习题1

==方法一：== 使用库函数`reverse()`对数组进行翻转.

``` C++
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    using namespace std;
    #define SIZE 20
    int main()
    {
        int arr[SIZE] = { 0 };
        for (int i = 0; i < SIZE; i++)
        {
            cin >> arr[i];
        }
        reverse(arr, arr + SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            printf("N[%d] = %d\n", i, arr[i]);
        }
        return 0;
    }
```

==方法二：== 使用双数组，将旧数组逆序输出到新数组中，实现数组的翻转.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int a[20], b[20];

        for (int i = 0; i < 20; i++)
        {
            cin >> a[i];
        }
        for (int i = 19, j = 0; i >= 0; i--, j++)
        {
            b[j] = a[i];
        }

        for (int i = 0; i < 20; i++)
        {
            printf("N[%d] = %d\n", i, b[i]);
        }
        
        return 0;
    }
```

==方法三：== 使用**双指针**对数组进行翻转.

#### 1.2.2 习题2

> 谨防整型溢出！

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int t = 0;
        int n = 0;
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            cin >> n;
            long int arr[60] = { -1 };
            arr[0] = 0;
            arr[1] = 1;
            if (n == 0)
            {
                printf("Fib(0) = 0\n");
            }
            else if (n == 1)
            {
                printf("Fib(1) = 1\n");
            }
            else
            {
                for (int i = 2; i <= n; i++)
                {
                    arr[i] = arr[i - 1] + arr[i - 2];
                }
                printf("Fib(%d) = %ld\n", n, arr[n]);
            }
        }
        return 0;
    }
```

> 注意：
> * **循环遍历n次**的技巧写法：
>   ``` C++
>       while (n --)
>       {
>           循环体.
>       }
>   ```
> * 整数（`int`型）数据的范围最大为`21亿`左右（约为`2的31次方`）.
>   * `long long int`型规格化输出：`%lld`.
>   * `long int`型数据规格化输出：`%ld`.

#### 1.2.3 习题3

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    #define MAX 1010
    int main()
    {
        int n = 0;
        cin >> n;
        int arr[MAX] = { 0 };
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int min = arr[0];
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                index = i;
            }
        }
        printf("Minimum value: %d\n", min);
        printf("Position: %d\n", index);
        return 0;
    }
```

> 技巧方法：
> *  寻找一个数组中最靠前的最小值及下标的方法：
>   ``` C++
>       if (a[i] < a[p])
>       {
>           p = i;
>       }
>   ```
>   在这种方式下，如果之后出现与当前最小值相同的元素，则不会覆盖掉当前的最小值.

#### 1.2.4 习题4

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        int c = 0;
        char ch = 0;
        //如果这里用scanf()读入，则应注意手动过滤掉第一次输入之后的空格.
        cin >> c >> ch;
        double arr[12][12];
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                cin >> arr[i][j];
            }
        }
        double sum = 0;
        for (int i = 0; i < 12; i++)
        {
            sum += arr[i][c];
        }
        if (ch == 'S')
        {
            printf("%.1lf\n", sum);
        }
        else
        {
            printf("%.1lf\n", sum / 12);
        }
        return 0;
    }
```

#### 1.2.5 习题5

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        char ch = 0;
        cin >> ch;
        double arr[12][12];
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                cin >> arr[i][j];
            }
        }
        double sum = 0;
        int cnt = 0;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 12 - i; j < 12; j++)
            {
                sum += arr[i][j];
                cnt++;
            }
        }
        if (ch == 'S')
        {
            printf("%.1lf\n", sum);
        }
        else
        {
            printf("%.1lf\n", sum / cnt);
        }
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
        char ch = 0;
        cin >> ch;
        double arr[12][12];
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                cin >> arr[i][j];
            }
        }
        double sum = 0;
        int cnt = 0;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < i; j++)
            {
                sum += arr[i][j];
                cnt++;
            }
        }
        if (ch == 'S')
        {
            printf("%.1lf\n", sum);
        }
        else
        {
            printf("%.1lf\n", sum / cnt);
        }
        return 0;
    }
```

> 注意：
> * 头文件`#include< >`的顺序是**任意的**.

#### 1.2.7 习题7

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        char ch;
        double m[12][12];
        cin >> ch;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                cin >> m[i][j];
            }
        }
        double sum = 0;
        int cnt = 0;
        for (int i = 7; i < 12; i++)
        {
            for (int j = 11 - i + 1; j < i; j++)
            {
                sum = sum + m[i][j];
                cnt++;
            }
        }
        if (ch == 'S')
        {
            printf("%.1lf\n", sum);
        }
        else
        {
            printf("%.1lf\n", sum / cnt);
        }
        return 0;
    }
```

> 注意：
> * 在很多语言中，`double`类型的变量不支持自增（`++`）或自减（`--`）操作.
> * `C++`中支持`double`类型的变量的自增（`++`）或自减（`--`）操作.

#### 1.2.8 习题8

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        char ch;
        double m[12][12];
        cin >> ch;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                cin >> m[i][j];
            }
        }
        double sum = 0;
        int cnt = 0;
        for (int j = 7; j < 12; j++)
        {
            for (int i = 12 - j; i < j; i++)
            {
                sum = sum + m[i][j];
                cnt++;
            }
        }
        if (ch == 'S')
        {
            printf("%.1lf\n", sum);
        }
        else
        {
            printf("%.1lf\n", sum / cnt);
        }
        return 0;
    }
```

#### 1.2.9 习题9

> 解题思路——矩阵规律：
> * 规律一：
>   * 主对角线上的元素为`1`.
>   * 由中间的元素`1`向两边不断延伸.
> * 规律二：
>   * 坐标为`(i, j)`的点的数值为`|i - j| + 1`.

==方法一：== 利用每条类对角线上的元素相同的特点和排列的规律构建平方矩阵.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    #define M 100
    int main()
    {
        /*
        * 本题注意要点：
        * 在宏定义数组的维数M时，如果M的值太大，则会出现Stack Overflow（栈溢出）的错误.
        *	* 会报出警告（建议）：函数使用堆叠的“4000032”字节。请考虑将一些数据移动到堆。
        */
        int n = -1;
        cin >> n;
        while (1)
        {
            int m[M][M];
            if (n == 0)
            {
                break;
            }
            else
            {
                int cnt = 1;
                while (cnt <= n)
                {
                    for (int i = cnt - 1, j = 0; i < n; i++, j++)
                    {
                        m[i][j] = cnt;
                    }
                    for (int j = cnt - 1, i = 0; j < n; i++, j++)
                    {
                        m[i][j] = cnt;
                    }
                    cnt++;
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        printf("%d ", m[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            cin >> n;
        }
        return 0;
    }
```

==方法二：== 从主对角线向右方和下方延伸，直到不能继续延伸为止.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;

    //元素个数为10000的二维矩阵比较大，建议定义为全局变量，这样不会溢出.
    int q[100][100] = { 0 };
    int main()
    {
        int n;
        while (cin >> n, n)
        {
            for (int i = 0; i < n; i++)
            {
                //对角线上的元素均为1：
                q[i][i] = 1;
                //从对角线上的每一个元素向右和向下延伸：
                for (int j = i + 1, k = 2; j < n; j++, k++)
                {
                    //每一行的元素：
                    q[i][j] = k;
                }
                for (int j = i + 1, k = 2; j < n; j++, k++)
                {
                    //每一列的元素：
                    q[j][i] = k;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << q[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }

        return 0;
    }
```

#### 1.2.10 习题10

==方法一：== 使用库函数`pow()`对幂次进行计算.

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cmath>
    using namespace std;
    #define M 100
    int main()
    {
        int n = -1;
        cin >> n;
        while (n != 0)
        {
            int m[M][M];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    m[i][j] = (int)pow(2, i + j);
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", m[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            cin >> n;
        }
    }
```

==方法二：== 使用位运算对`2^(i + j)`进行计算.

#### 1.2.11 习题11（蛇形矩阵）

==题目：== 输入两个整数n和m，输出一个n行m列的矩阵，将数字1到n × m按照回字蛇形填充至矩阵中.

> 蛇形矩阵：
> * 网格题（相邻的格子、联通块）——偏移量（`dx`、`dy`）技巧：
>   * 向右（方向`0`）走：偏移量为`(0, 1)`.
>       * `dx[0] = 0`;
>       * `dy[0] = 1`;
>   * 向下（`1`）走：偏移量为`(1, 0)`.
>       * `dx[1] = 1`;
>       * `dy[1] = 0`;
>   * 向左（方向`2`）走：偏移量为`(0, -1)`.
>       * `dx[2] = 0`;
>       * `dy[2] = -1`;
>   * 向上（方向`3`）走：偏移量为`(-1, 0)`.
>       * `dx[3] = -1`;
>       * `dy[3] = 0`;
> * 撞墙的情况：
>   1. 出界.
>   2. 重复.

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;

    const int N = 110;
    int res[N][N];

    int main()
    {
        int n, m;
        cin >> n >> m;

        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { 1, 0, -1, 0 };

        for (int x = 0, y = 0, d = 0, k = 1; k <= n * m; k++)
        {
            res[x][y] = k;
            int a = x + dx[d], b = y + dy[d];
            //判断是否撞墙：
            if (a < 0 || a >= n || b < 0 || b >= m || res[a][b])
            {
                //如果碰壁或越界，则对偏移量进行调整：
                //顺时针旋转90°：
                d = (d + 1) % 4;
                a = x + dx[d];
                b = y + dy[d];
            }
            //下一次赋值的坐标：
            x = a;
            y = b;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << res[i][j] << ' ';
            }
            cout << endl;
        }

        return 0;
    }
```

---

## 二、字符与整数的联系——ASCII码

每个常用字符都对应一个`-128~127`的数字，二者之间可以**相互转化**：

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        char c = 'a';
        cout << (int)c << endl;

        int a = 97;
        cout << (char)a << endl;

        for (int i = 0; i < 128; i++)
        {
            printf("%d : %c\n", i, i);
        }
        return 0;
    }
```

> 注意：
> * 常用`ASCII`值：
>   * `A`-`Z` 是`65~90`，
>   * `a`-`z`是`97~122`，
>   * `0`-`9`是`48~57`.
>   * `10`是**回车符**.
>   * `32`是**空格符**.
> * 大写英文字母和小写英文字母的`ASCII码`差值是`32`.
> * 中文一般使用**变长字符**来表示，有自己独立的一套表示方式.

字符**可以参与运算**，运算时会将其**当做整数**：

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        printf("%d\n", 'z' - 'a');
        printf("%c\n", 'a' + 3);

        int a = 'B' - 'A';
        int b = 'A' * 'B';
        char c = 'A' + 2;
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        return 0;
    }
```

==练习：== 
* 题目：
  * 输入一行字符，统计出其中数字字符的个数，以及字母字符的个数.
* 题解：
    ``` C++
        #include <cstdio>
        #include <iostream>
        using namespace std;
        int main()
        {
            char c;
            int numbers = 0;
            int chars = 0;
            while (cin >> c)
            {
                if (c >= 48 && c <= 57)
                    numbers++;
                else if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
                    chars++;
            }
            printf("nums: %d, chars: %d\n", numbers, chars);
            return 0;
        }
    ```

---

## 三、字符数组

==字符串==就是字符数组加上结束符`\0`.

> 注意：
> * 在`C++`、`Java`等语言中，字符串是用双引号（`" "`）引起来的；而在`Python`、`JavaScript`等语言中，字符串可以用双引号（`" "`）引起来，也可以用单引号（`' '`）引起来.
> * 可以使用字符串来初始化字符数组，但此时要注意，每个字符串结尾会暗含一个`\0`字符，因此字符数组的长度至少要比字符串的长度多`1`！

### 3.1 字符数组的初始化

* 初始化方法一：

    `char a1[] = { 'C', '+', '+' };`.

> 列表初始化，没有空字符（`\0`），不是一个字符串.

* 初始化方法二：

    `char a2[4] = { 'C', '+', '+' };`.

> 列表初始化，最后一个字符是空字符（`\0`），是一个字符串.

* 初始化方法三：

    `char a3[] = { 'C', '+', '+', '\0' };`.

> 列表初始化，含有显示的空字符（`\0`），是一个字符串.

* 初始化方法四：

    `char a4[] = "C++";`.

> 自动添加表示字符串结尾的空字符（`\0`），是一个字符串.

==错误的初始化方法：==

`char a5[6] = "Daniel";`.

> 错误原因：没有空间可存放空字符（`\0`）！

> 字符数组初始化注意事项：
> * 在`C++`中，在函数内部开辟的数组位于栈中，会**按照顺序开辟**.
> * 在`C++`中`0`的用法：
>   * 在`int`型、`float`型、`double`型中，代表数字`0`.
>   * 在`char`字符型中，代表空字符`\0`.
>   * 在`bool`变量中，代表布尔变量`False`.
>   * 在指针变量中，代表空指针`nullptr`.

### 3.2 字符数组的输入输出

#### 3.2.1 利用`cin`和`cout`对字符数组进行输入和输出：

示例代码：

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        char arr[8];
        cin >> arr;
        cout << arr << endl;
        return 0;
    }
```

* ==特殊技巧：== 

  * 从字符数组指定位置开始输入和输出：
    * 输入：`cin >> arr + n`.
    * 输出：`cout << arr + n`.
  * 示例代码：
    ``` C++
        #include <cstdio>
        #include <iostream>
        using namespace std;
        int main()
        {
            char arr[8];
            cin >> arr;
            cout << "输出完整的字符数组：" << arr << endl;
            cout << "从字符数组第4个字符开始输出（假设开始的字符为第一个字符）：" << arr + 3 << endl;
            cout << "第4个字符（假设开始的字符为第一个字符）为：" << arr[3] << endl;

            return 0;
        }
    ```

> 注意：
> * 如果对字符数组从某一指定位置开始输入，则输出时也要**至少从该指定位置进行输出**；该指定位置前的字符由于未经初始化，因此输出指定位置前的字符时**可能会出现乱码的随机情况**.
> * 对于某些算法，**从`arr[1]`处开始输入输出**往往会带来很大的方便，例如**KMP算法**一般从字符数组下标为`1`处的字符开始输入输出.

#### 3.2.2 利用`scanf()`和`printf()`对字符数组进行输入和输出：

示例代码：

``` C++
    #include <cstdio>
    #include <iostream>
    using namespace std;
    int main()
    {
        char arr[8];
        scanf("%s", arr);	//这里不能写取地址符号&，因为字符数组名称arr已经是字符所在地址了.
        printf("%s\n", arr);

        return 0;
    }
```

> 注意：
> * 在字符数组中，**字符数组的名称本身就是一个指针**，即：`数组名字 = 首元素地址`.
> * 利用`scanf()`函数对字符数组进行读操作时，应写为`scanf("%s", arr)`，在`arr`前不能写取地址符号`&`，因为字符数组名称`arr`已经是**字符所在地址**了.

* ==特殊技巧：== 

  * 从字符数组指定位置开始输入和输出：
    * 输入：`scanf("%s", arr + n)`.
    * 输出：`printf("%s", arr + n)`.
  * 示例代码：
    ``` C++
        #include <cstdio>
        #include <iostream>
        using namespace std;
        int main()
        {
            char arr[8];
            scanf("%s", arr + 3);
            printf("从字符数组第4个字符开始输出（假设开始的字符为第一个字符）：%s\n", arr + 3);
            printf("字符数组第4个字符（假设开始的字符为第一个字符）为：%c\n", arr[3]);
            printf("输出完整的字符数组（可能会出现乱码）：%s", arr);

            return 0;
        }
    ```

#### 3.2.3 利用`cin`和`scanf()`函数读入字符数组的注意事项

1. 在利用`cin`和`scanf()`函数将输入的字符串读入字符数组中时，**并非将在控制台输入的字符串按行读入**，而是读入到`空格`、`回车`、`文件结束符`为止；但是在输出字符串时，遇到空格或者回车**不会停止**.
     * 读入一整行字符的方式：
       * **在字符数组中**，使用`fgets()`函数读入一整行元素.
       * **在字符串中**，使用`getline()`函数读入一整行元素.
     * 示例代码：
        ``` C++
            #define _CRT_SECURE_NO_WARNINGS 1
            #include <cstdio>
            #include <iostream>
            #include <cstring>
            using namespace std;
            int main()
            {
                //利用fgets()函数进行读入：
                char arr[10];
                fgets(arr, 8, stdin);
                cout << arr << endl;

                //清空缓冲区中的回车符号：
                getchar();

                //利用getline()函数进行读入：
                string str;
                getline(cin, str);
                cout << str << endl;

                return 0;
            }
        ```
2. `string`是一个**类**，只能用`cin`读，而不能用`scanf()`函数来读.
3. `scanf()`函数**只能读入代表字符串的字符数组，不能直接读入整数数组**；在利用`scanf()`函数读入整数数组时，只能通过循环遍历整个整数数组依次按顺序读入.

> 读入字符数组或字符串的函数介绍：
> * `fgets(arr, Max_Nums, stdin)`：
>   * 参数声明：
>       * `arr`：将输入的字符读入到的目的字符数组.
>       * `Max_Nums`：最多读入的字符.
>           * 由于字符串结尾为空字符（`\0`），因此`Max_Nums`一定要**大于**待读入的字符数（至少为`待读入的字符数 + 1`），否则最多只能读`Max_Nums - 1`个字符.
>       * `stdin`：读入字符的来源文件，是系统内已经定义好的变量.
>   * 在利用`fgets()`函数进行读取时，即使`Max_Nums`大于字符数组的初始化长度，读入时最多只能读`字符数组初始化长度 - 1`个字符，其余字符将会被截断，体现了`fgets()`函数的**安全性**.
>   * 使用时注意事项：
>       * `fgets()`函数会吸收缓冲区中的回车符（`\n`），并且会自动在输入流末尾添加空字符（`\0`）.
>       * `fgets()`函数的参数中的`Max_Nums`为整型数据，表示要复制到`arr`中的字符串的长度，**包含终止空字符**`NULL`（`\0`），因此最多能接收的字符数量为`Max_Nums - 1`，且当接收最多可接收字符数量时`arr[Max_Nums - 1] = \0`，即此时第`Max_Nums`个字符为`NULL`.
>       * 验证代码：
>           ``` Python
>               #include <cstdio>
>               #include <iostream>
>               #include <string>
>               using namespace std;
>               #define MAX 1000
>               int main()
>               {
>                   char arr[MAX];
>                   fgets(arr, 101, stdin);
>           
>                   /*在控制台输入字符串"abcd".*/
>           
>                   if (arr[4] == '\n')
>                   {
>                       cout << "arr[4] = '\\n'！" << endl;
>                   }
>                   if (arr[5] == '\0')
>                   {
>                       cout << "arr[5] = '\\0'";
>                   }
>           
>                   cout << "输入的字符串“abcd”的长度是：" << strlen(arr) << "！" << endl;
>                   return 0;
>               }
>           ```
> * `getline(cin, str)`：
>   * 位置：
>       * 包含在`<cstring>`头文件中.
>   * 参数声明：
>       * `cin`：系统内已经定义好的变量.
>       * `str`：将输入的字符读入到的目的字符串.
> * `gets(str)`：
>   * 最新的`C++`语法标准中已经淘汰掉`gets()`函数了，因为`gets()`函数的**不安全性**（可能会引发**数组越界**和**栈溢出**）.

#### 3.2.3 `string`字符串和字符数组的比较和注意事项

1. `string`字符串和字符数组在`IO`题中的权衡选取：
    * **题目没有超时**，用`string`字符串比较好；
    * 如果**输入量较大**，用字符数组比较好.
2. `C++`中`printf()`函数输出`string`字符串时，不能直接使用`printf("%s", str)`，否则会出现乱码.
3. `const char*` 是一种字符串形式.

> 注意：
> **计算机底层**知识性的东西比较多，现查现学也不会太慢；但是**算法**不一样，如果现查现学的话（例如最短路径问题），则会耽误太多时间.