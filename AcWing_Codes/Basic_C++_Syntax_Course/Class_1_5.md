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

每个常用字符都对应一个`0~127`的数字，二者之间可以**相互转化**：

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

> 注意：
> * 负数并没有与之对应的字符.

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
       * **在字符数组中：**
         * 使用`fgets()`函数读入一整行元素.
         * 使用`cin.getline()`函数读入一整行元素.
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
>           * 即标准读入，也就是把终端作为文件读入.
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
> * `cin.getline(str, Max_Nums)`：
>   * 位置：
>       * 包含在`<iostream>`头文件中，是`cin`的一个成员函数.
>   * 功能：
>       * 取一行字符串，读到换行符`\n`结束，并且抛弃换行符；如果需要读取字符，则接着下一行读取.
>   * 参数声明：
>       * `str`：将输入的字符读入到的目的字符串.
>       * `Max_Nums`：一行最多读入的字符数.
> * `getline(cin, str)`：
>   * 功能：
>       * 取一行字符串，读到换行符`\n`结束，并且抛弃换行符；如果需要读取字符，则接着下一行读取.
>   * 位置：
>       * 包含在`<cstring>`或者`<string>`头文件中.
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

### 3.3 字符数组的常用操作

> 注意：
> * 下面几个函数需要引入**头文件**：
>   * `#include <string.h>`.
> * 常用的库`<xxxx.h>`都可以用库`<cxxxx>`来代替.

#### 3.3.1 `strlen(str)`操作函数

函数原型：`size_t strlen ( const char * str )`.
* 功能：
  * 求字符串的==长度==.

> 注意：
> * `strlen()`函数计算字符串的元素时，`\0`元素不计入其中.

#### 3.3.2 `strcmp(a, b)`操作函数

函数原型：`int strcmp ( const char * str1, const char * str2 )`.
* 功能：
  * 比较两个字符串的==大小==.
    * `a < b`返回`-1`；`a == b`返回`0`；`a > b`返回`1`. 
  * 比较方式：
    * 字典序.
      * 按照字典中出现的先后顺序进行排序.
      * 两个字符串比较大小，是按照从左到右的顺序进行比较，如果第`1`位相等，就比较第`2`位，直至有一位可以比较出大小来，则不再继续比较.

> 注意：
> * 字典序通常与**贪心策略**相联系.

#### 3.3.3 `strcpy(a, b)`操作函数

函数原型：`char * strcpy ( char * destination, const char * source )`.
* 功能：
  * 将字符串`b`==复制==给从`a`开始的字符数组.

#### 3.3.4 示例代码

``` C++
    #include <iostream>
    #include <string.h>

    using namespace std;

    int main()
    {
        char a[100] = "hello world!", b[100];

        cout << strlen(a) << endl;

        strcpy(b, a);

        cout << strcmp(a, b) << endl;

        return 0;
    }
```

### 3.4 遍历字符数组中的字符

``` C++
    #include <iostream>
    #include <string.h>

    using namespace std;

    int main()
    {
        char a[100] = "hello world!";

        // 注意：下述for循环每次均会执行strlen(a)，运行效率较低，最好将strlen(a)用一个变量存下来
        for (int i = 0, len = strlen(a); i < len; i ++ )
            cout << a[i] << endl;

        return 0;
    }
```

**练习：**

* 练习一

题目：给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符.如果存在，则输出满足条件的字符中位置最靠前的那一个；如果没有，输出no.

==方法一：==

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cstring>
    using namespace std;

    int cnt[26];
    char str[1000010];

    int main()
    {
        cin >> str;
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            cnt[str[i] - 'a']++;
        }
        for (int i = 0; i < len; i++)
        {
            if (cnt[str[i] - 'a'] == 1)
            {
                cout << str[i] << endl;
                return 0;
            }
        }
        puts("no");
        return 0;
    }
```

==方法二：==

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cstring>
    using namespace std;

    int cnt[26];
    char str[1000010];

    int main()
    {
        cin >> str;
        int len = strlen(str);
        for (int i = 0; str[i]; i++)
        {
            cnt[str[i] - 'a']++;
        }
        for (int i = 0; str[i]; i++)
        {
            if (cnt[str[i] - 'a'] == 1)
            {
                cout << str[i] << endl;
                return 0;
            }
        }
        puts("no");
        return 0;
    }
```

* 练习二：

题目：把一个字符串中特定的字符全部用给定的字符`#`替换，得到一个新的字符串.

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cstring>
    using namespace std;

    int main()
    {
        char str[31];
        scanf("%s", str);

        char c;
        //手动过滤掉缓冲区中的回车符.
        scanf("\n%c", &c);

        for (int i = 0; str[i]; i++)
        {
            if (str[i] == c)
            {
                str[i] = '#';
            }
        }
        return 0;
    }
```

---

## 四、标准库类型`string`

> `string`：
> * **可变长**的字符序列，比字符数组更加好用.
> * 需要引入**头文件**：
>   * `#include <string>`.
>       * 库`<cstring>`定义了很多字符串的类型及操作，而库`<string>`只定义了`string`这一个类型.

### 4.1 `string`的定义和初始化

``` C++
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string s1;              // 默认初始化，s1是一个空字符串
        string s2 = s1;         // s2是s1的副本，注意s2只是与s1的值相同，并不指向同一段地址
        string s3 = "hiya";     // s3是该字符串字面值的副本
        string s4(10, 'c');     // s4的内容是 "cccccccccc"

        return 0;
    }
```

### 4.2 `string`上的操作

#### 4.2.1 `string`的读写

``` C++
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string s1, s2;

        cin >> s1 >> s2;
        cout << s1 << s2 << endl;

        return 0;
    }
```

> 注意：
> * 不能用`printf()`直接输出`string`.
>   * 需要写成：`printf(“%s”, str.c_str())`.
> * `puts()`函数：
>   * 功能：
>       * `puts(arr)` 等价于 `printf("%s\n", arr)`.

#### 4.2.2 使用`getline()`读取一整行

``` C++
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string s;

        getline(cin, s);

        cout << s << endl;

        return 0;
    }
```

#### 4.2.3 `string`的`empty`和`size`操作

**`str.empty`操作：**
* 功能：
  * 判断一个`string`对象==是否为空==.
* 返回值类型：
  * 返回一个布尔类型：
    * 如果为空，则返回`true`.
    * 如果不为空，则返回`false`.

**`str.size`操作：**
* 功能：
  * 返回一个`string`对象的==长度==.
    * 返回值类型为无符号整数.
    * 返回的长度中==不包含==字符串结束标志`\0`.

> 注意：
> * `size`是无符号整数，因此 `s.size() <= -1` 一定成立.

**示例代码：**

``` C++
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string s1, s2 = "abc";

        cout << s1.empty() << endl;
        cout << s2.empty() << endl;

        cout << s2.size() << endl;

        return 0;
    }
```

#### 4.2.4 `string`的比较

`string`支持 `>`，`<`，`>=`，`<=`，`==`，`!=`等所有比较操作，按**字典序**进行比较.

#### 4.2.5 为`string`对象赋值

``` C++
    string s1(10, 'c'), s2;     // s1的内容是 cccccccccc；s2是一个空字符串
    s1 = s2;                    // 赋值：用s2的副本替换s1的副本
                                // 此时s1和s2都是空字符串
```

#### 4.2.6 `string`的相加操作

两个`string`对象的相加操作，实质是这两个`string`对象进行**拼接操作**.

``` C++
    string s1 = "hello,  "", s2 = "world\n";
    string s3 = s1 + s2;                    // s3的内容是 hello, world\n
    s1 += s2;                               // s1 = s1 + s2
```

> 注意：
> * `string`对象之间**不支持**进行相乘和相除的操作.

#### 4.2.7 字面值和`string`对象相加操作

做加法运算时，字面值和字符都会被转化成`string`对象，因此**直接相加就是将这些字面值串联起来**：

``` C++
    string s1 = "hello", s2 = "world";      // 在s1和s2中都没有标点符号
    string s3 = s1 + ", " + s2 + '\n';
```

当把`string`对象和字符字面值及字符串字面值混在一条语句中使用时，**必须确保每个加法运算符的两侧的运算对象至少有一个是`string`**：

``` C++
    string s4 = s1 + ", ";  // 正确：把一个string对象和有一个字面值相加
    string s5 = "hello" + ", "; // 错误：两个运算对象都不是string

    string s6 = s1 + ", " + "world";  // 正确，每个加法运算都有一个运算符是string
    string s7 = "hello" + ", " + s2;  // 错误：不能把字面值直接相加，运算是从左到右进行的
```

### 4.3 处理`string`对象中的字符

可以将`string`对象当成**字符数组**来处理：

``` C++
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string s = "hello world";

        for (int i = 0; i < s.size(); i ++ )
            cout << s[i] << endl;

        return 0;
    }
```

或者使用**基于范围**的`for`语句（**范围遍历**）：

``` C++
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string s = "hello world";

        //遍历字符串s中的每一个字符：
        for (char c: s) cout << c << endl;

        //遍历字符串s中的每一个字符并改变字符c的值：
        for (char &c: s) c = 'a';

        //auto：使编译器猜测修饰的变量的类型；如果无法猜出，则编译器会报错.
        for (auto &c: s) c = 'a';

        cout << s << endl;

        return 0;
    }
```

> `auto`的用法：
> * 功能：
>   * 使编译器**猜测修饰的变量的类型**；如果无法猜出，则编译器会**报错**.
> * 使用场景：
>   * 如果==变量的类型是确定的==，那么可以使用`auto`来代替一些定义起来非常复杂的数据类型.
>   * 如果==变量的类型有多种选择情况==，那么最好不要使用`auto`来代替数据类型的定义，而选择自己对数据类型进行定义.

**练习：**

* 练习一

题目：密码翻译，输入一个只包含小写字母的字符串，将其中的每个字母替换成它的后继字母.如果原字母是'`z`'，则替换成'`a`'.注意字符串中可能包含空格.

``` C++
    #include <cstdio>
    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string s;
        getline(cin, s);
        for (auto& c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                c = (c - 'a' + 1) % 26 + 'a';
            }
            else if (c >= 'A' && c <= 'Z')
            {
                c = (c - 'A' + 1) % 26 + 'A';
            }
        }
        return 0;
    }
```

> 注意：
> * 出现`未定义标识符"getline"`报错原因：
>   * 导入的是库`<cstring>`，而未导入包含`getline()`函数的库`<string>`.

---

## 五、1.5 题目讲解

### 5.1 例题讲解

#### 5.1.1 例题 1

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cstring>
    using namespace std;
    #define MAX 1000
    int main()
    {
        char arr[1000];
        fgets(arr, 101, stdin);
        int len = strlen(arr);
        cout << len << endl;

        return 0;
    }
```

> `Window操作系统`下的**回车包含两个符号**：`\r`和`\n`.

#### 5.1.2 例题 2

``` C++
    #include <cstdio>
    #include <iostream>
    #include <cstring>
    #include <string>
    using namespace std;

    int main()
    {
        char str[101];
        fgets(str, 101, stdin);
        int cnt = 0;
        for (int i = 0; str[i]; i++)
            if (str[i] >='0' && str[i] <= '9')
            {
                cnt++;
            }
        printf("%d\n", cnt);

        return 0;
    }
```

#### 5.1.3 例题 3

> 思路：
> * 首先将三种情况数字化：
>   * `猎人` -> `0`.
>   * `狗熊` -> `1`.
>   * `枪` -> `2`.
> * 给定P1和P2的出拳情况`(x, y)`，判断输赢方法：
>   * 如果`x == y`，则平局.
>   * 如果`x = (y + 1) % 3`，则P1赢.
>   * 如果`x != y` 且 `x != (y + 1) % 3`，则P2赢.

``` C++

```

#### 5.1.4 例题 4

``` C++
```

> `str.pop_back()`：
> * 功能：
>   * 删除字符串中最后一个字符.

#### 5.1.5 例题 5

``` C++
```

> `str.substr(i, len)`：
> * 功能：
>   * 截取一个字符串的指定的子字符串.
> * 参数声明（包左不包右）：
>   * `i`：起始位置.
>   * `len`：返回字符串段的长度，最多到最后一个字符截止.
>       * 如果`len`参数省略，此时函数形式为`str.substr(i)`，那么默认从当前位置截取到最后一个字符截止.
> * 返回值类型：
>   * 返回指定的子字符串.

### 5.2 习题讲解

#### 5.2.1 习题 1

``` C++
```

#### 5.2.2 习题 2

``` C++
```

#### 5.2.3 习题 3

``` C++
```

> 注意：
> * `C++`语言的库要比`C`语言的库多很多.