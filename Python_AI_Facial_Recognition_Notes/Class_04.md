# 第四讲：Python的条件和循环

---

**目录：**

[TOC]

---

## 一、条件语句

### 1.1 条件语句基本语法格式

``` Python
if 条件1:
   条件1成立执⾏的代码一
   条件1成⽴执⾏的代码二
   ......
elif 条件2：
   条件2成立执⾏的代码三
   条件2成立执⾏的代码四
   ......
......
else:
   以上条件都不成⽴，执行的代码五
   以上条件都不成⽴，执行的代码六
   ......
```

### 1.2 条件表达式

**比较运算符（关系运算符）**

| 运算符 | 描述 |
| --- | --- |
| `==` | 判断相等 |
| `!=` | 不等于 |
| `>` | 大于 |
| `<` | 小于 |
| `>=` | 大于等于 |
| `<=` | 小于等于 |

> 注意：
> * 比较运算符作用的两个对象应该是同类型的对象.

**逻辑运算符**

| 运算符 | 逻辑表达式 |
| --- | --- |
| `and` | `x and y` |
| `or` | `x or y` |
| `not` | `not x` |

### 1.3 实操案例——年龄计算问题

``` Python
    """
    年龄判断案例：
    0 ~ 18 是 未成年
    18 ~ 60 是 打工人
    60以上 是 老年人
    """

    age = input('请输入您的年龄：')
    age = int(age)

    if age < 18:
        print(f"您的年龄是{age}, 您未成年！")
    elif 18 <= age < 60:
        print(f"您的年龄是{age}, 您是打工人！")
    else:
        print(f"您的年龄是{age}, 您是老年人！")
```

---

## 二、循环语句

### 2.1 `while`循环

基本语法格式：

``` Python
while 条件: 
    条件成⽴重复执行的代码1 
    条件成⽴重复执行的代码2 
    ......
```

代码示例：

> 计算从1 ~ 100的所有偶数的和.

``` Python
    i = 1
    result = 0
    while i <= 100:
        if i % 2 == 0:
            result += i
        i += 1

    print(result)
```

### 2.2 `for`循环

基本语法格式：

``` Python
for 临时变量 in 序列: 
    重复执行的代码1 
    重复执行的代码2 
    ......
```

> `range`：包头不包尾.

### 2.3 循环控制语句

Python支持以下两种循环控制语句：
* `break`：
  * 终止循环，并跳出整个循环.
* `continue`：
  * 终止当前循环，跳出该次循环，执行下一次循环.

### 2.4 代码示例——计算偶数之和

> 计算从1 ~ 100的所有偶数的和.

==方法一：采用while循环==

``` Python
    i = 1
    result = 0
    while i <= 100:
        if i % 2 == 0:
            result += i
        i += 1

    print(result)
```

==方法二：采用while循环 + break==

``` Python
    i = 1
    result = 0
    while True: # 死循环.
        if i > 100:
            break
        if i % 2 == 0:
            result += i
        i += 1

    print(result)
```

==方法三：采用while循环 + continue==

``` Python
    i = 0
    result = 0
    while i <= 100:
        i += 1
        if i % 2 == 1:
            continue
        result += i

    print(result)
```

==方法四：采用for循环==

``` Python
    result = 0
    for i in range(1, 101):
        if i % 2 == 0:
            result += i

    print(result)
```

---

## 三、实操案例——猜数游戏

``` Python
    import random # 专门产生随机数的模块.

    print("-" * 50)
    print("欢迎来到 Axiomer 的《猜数游戏》")
    print("规则一：系统每次会自动生成一个1~10之间的随机数")
    print("规则二：每次游戏最多只能猜三次")
    print("规则三：进入游戏或者继续玩，输入：yes或者y")
    print("规则三：离开游戏，输入：no或者n")
    print("-" * 50)

    i = 0 # 定义一个玩游戏的次数.
    while True:
        g_num = random.randint(1, 10) # 产生一个1 ~ 10之间的随机数.
        order = input('请输入是否开始游戏：')
        if order == 'yes' or order == 'y':
            i += 1
            for j in range(1, 4): # for循环中最多允许用户猜三次.
                my_num = int(input('请输入所猜的数字：'))
                if my_num == g_num:
                    print(f'恭喜你！猜中了！就是数字：{my_num}')
                    break
                elif my_num > g_num:
                    print(f'您猜的数字太大了，还剩下{3 - j}次！')
                else:
                    print(f'您猜的数字太小了，还剩下{3 - j}次！')
        elif order == 'no' or order == 'n':
            break

    print("谢谢！ GAME OVER")
```

---

## 四、课堂小结

==逻辑思路流程图：==
* 作用：
  * 体现**代码逻辑思路和分支走向**的流程图.
* 小建议：
  * 作为一个**Python初学者**，一定要画一画**逻辑思路流程图**.