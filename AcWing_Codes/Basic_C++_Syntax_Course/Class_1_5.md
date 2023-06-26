# 第五讲：字符串

---

**目录：**

[TOC]

---

## 一、1.4 题目讲解

### 1.1 例题讲解

#### 1.1.1 例题1

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

> 观察得到，每一个格子的值即为该格位置到上下左右四条边的最小值.