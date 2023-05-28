# 第五讲：Python的数据集合

**目录：**

[TOC]

---

## 一、容器技术

> 容器：
> Python程序运行过程中可以包含其他对象的对象，叫做容器.

Python中常用的**容器**有四类：
* 列表（`List`）.
* 元组（`Tuple`）.
* 字典（`Dict`）.
* `set`集合（`Set`）.

### 1.1 列表

**列表介绍：**

* 用中括号来包裹.
* 所有元素都是有顺序的.

> 索引：
> * 从`0`开始，由左向右排序.
>   * `0   1   2   3   4   ...`.
> 反向索引：
> * 从`-1`开始，由右向左排序.
>   * `-5   -4   -3   -2   -1   ...`.

**列表基本操作：**

==创建列表：==

``` Python
lst = ['abc', 12, [10, 20]]
nums = [10, 20, 30, 40, 50, 60]
my_emt = [] # 空列表，没有任何元素.
```

> 列表中的任意一个元素都不限定数据类型.

==查询列表：==

``` Python
# 使用下标来查找单个元素.
nums = [10, 20, 30, 40, 50, 60]
print(nums[3])

# 切片技术：使用下标来查找多个元素.
# 注意：索引序列包头不包尾.
#   正向索引：
print(nums[2:6]) # [30, 40, 50, 60]
#   反向索引：
print(nums[-4:]) # [30, 40, 50, 60]
print(nums[:-2]) # [10, 20, 30, 40]
```

* 返回单个元素所对应的下标

``` Python
nums = [10, 20, 30, 40, 50, 60]
print(nums.index(50))
```

* 返回列表的长度

``` Python
nums = [10, 20, 30, 40, 50, 60]
print(len(nums))
```

* 判断某一个元素是否存在

``` Python
nums = [10, 20, 30, 40, 50, 60]
if 30 in nums:
    print('存在列表中！')
else:
    print('不存在列表中！')
```

* 循环遍历

``` Python
nums = [10, 20, 30, 40, 50, 60]
for i in nums:
    print(i)
```

==新增操作：==

`append函数`：

``` Python
nums = [10, 20, 30, 40, 50, 60]
nums.append(70)
print(nums)
```

`insert函数`：

``` Python
# 把80添加到下标为0的位置.
nums = [10, 20, 30, 40, 50, 60]
nums.insert(0, 80)
print(nums)
```
> `append`只能把新增的元素添加到列表的最后位置.

==删除操作：==

`pop函数`：

``` Python
nums = [5, 10, 20, 30, 40, 50, 60]
nums.pop()  # 无参数默认删除最后一个元素.
nums.pop(0) # 删除下标为0的指定元素.
```

`remove函数`：

``` Python
nums = [5, 10, 20, 30, 40, 50, 60]
nums.remove(10) # 删除指定元素的值.
print(nums)
```

==修改操作：==

``` Python
nums = [5, 10, 20, 30, 40, 50, 60]
nums[4] = 400
print(nums)
```

**代码示例：**

``` Python
    """ 一、列表（List） """

    # 创建列表.
    lst = ['abc', 12, 'def', 3.14]
    nums = [10, 20, 30, 40, 50, 60]
    my_emt = [] # 空列表，不存放任何对象.

    # 查询列表
    #   1.使用下标来查找单个元素.
    print(nums[2])
    print(nums[-3])
    #   2.切片技术：使用下表来查找多个元素.
    print(nums[1:5])
    print(nums[:-2])
    #   3.返回单个元素所对应的下标.
    print(nums.index(20))
    #   4.返回列表的长度.
    print(len(nums))
    #   5.判断某一个元素是否存在.
    if 30 in nums:
        print('存在列表中！')
    else:
        print('不存在列表中！')
    #   6.循环遍历.
    for i in nums:
        print(i)

    # 新增操作
    #   1.append函数.
    nums.append(90)
    print(nums)
    #   2.insert函数
    nums.insert(1, 100)
    print(nums)

    # 删除操作
    #   1.pop函数.
    nums.pop()
    print(nums)
    nums.pop(1)
    print(nums)
    #   2.remove函数：
    nums.remove(30)
    print(nums)

    # 修改操作
    nums[2] = 400
    print(nums)
```

### 1.2 元组

**元组介绍：**

* 使用小括号，且逗号隔开各个数据.
* 元组可以包含不同的数据类型，所有数据都是有顺序的.
* 元组不支持修改，只支持查找.

**元组基本操作类型：**

==创建元组：==

``` Python
# 非单一元素元组的创建.
nums = (10, 20, 30, 40, 50, 60)

# 如果元组中只有一个值，必须在后面加逗号.
tub = (100,)
```

==查询元组：==

``` Python
# 使用下标来查找单个元素.
nums = (10, 20, 30, 40, 50, 60)
print(nums[4])

# 切片技术：使用下标来查找多个数据.
print(nums[1:5])
```

* 返回单个元素的下标

``` Python
nums = (10, 20, 30, 40, 50, 60)
print(nums.index(40))
```

* 判断某一元素是否存在

``` Python
nums = (10, 20, 30, 40, 50, 60)
if 20 in nums:
    print('存在')
```

* 循环遍历

``` Python
# 防止下标越界.
nums = (10, 20, 30, 40, 50, 60)
i = 0
while i < len(nums):
    print(nums[i])
    i += 1
```

**代码示例：**

``` Python
    """ 二、元组（Tuple） """

    # 创建元组
    nums = (10, 20, 30, 40, 50, 60)
    print(nums)
    tub = (90,)
    print(tub)

    # 查询元组
    #   1.使用下标来查找单个元素.
    print(nums[1])
    #   2.切片技术：使用下标来查找多个数据.
    print(nums[1:5])
    #   3.返回单个元素的下标.
    print(nums.index(40))
    #   4.判断某一元素是否存在.
    if 30 in nums:
        print('存在元组中！')
    else:
        print('不存在元组中！')

    # 循环遍历
    i = 0
    while i < len(nums):
        print(nums[i])
        i += 1
```

### 1.3 字典

**字典介绍：**

* 字典是一种可变类型的容器.
* 字典中的数据元素没有顺序.
* 操作：
  * 支持增删改查操作.
* 基本格式：
  * 符号为：
    * 大括号：`{}`.
  * 数据为：
    * 以`键值对`形式出现.
    * 键和值之间用`冒号`（`:`）隔开.
      * `key`必须是唯一的，而`value`没有要求.

> 注意：一般称冒号前面的为键(`key`)，简称`k`；冒号后面的为值(`value`)，简称`v`.

**字典基本操作类型：**

==创建字典：==

``` Python
dict1 = {'a': 10, 'b': 20, 'c': 50}
dict2 = {} # 创建一个空的字典.
print(dict1)
print(dict2)
```

==查询操作：==

* 根据一个指定的`key`来返回对应的`value`

``` Python
dict1 = {'a': 10, 'b': 20, 'c': 50}
# 第一种方式：
print(dict1['a'])

# 第二种方式：
print(dict1.get('a'))
```

> 区别：
> * 如果`key`不存在，`dict1[key]`会报错.
> * 如果`key`不存在，`get`函数不会报错，会返回一个`None`.

* 循环遍历

``` Python
dict1 = {'a': 10, 'b': 20, 'c': 50}

# 遍历字典中所有的key.
dict1.keys()
for k in dict1.keys():
    print(k)

# 遍历字典中所有的value
for v in dict1.values():
    print(v)

# 遍历字典中的所有元素（包括key和value）
for k, v in dict1.items():
    print(f'元素的key是：{k}，对应的value是：{v}')
```

==新增操作：==

``` Python
dict1 = {'a': 10,'b' : 20,'c' : 50}
dict1['d'] = 100
print(dict1)
```

==修改操作==

``` Python
dict1 = {'a': 10, 'b': 20, 'c': 50}
dict1['a'] = 500
print(dict1)
```

==删除操作：==

``` Python
dict1 = {'a': 10, 'b': 20, 'c': 50}
del(dict1['b'])
print(dict1)
```

**代码示例：**

``` Python
    """ 三、字典（Dict） """

    # 创建字典
    dict1 = {'a': 10, 'b': 20, 'c': 30}
    dict2 = {} # 空字典.
    print(dict1)

    # 查询操作
    #   1.根据一个指定的key来返回对应的value
    #       (1)第一种方式.
    print(dict1['a'])
    #       (2)第二种方式.
    print(dict1.get('f'))
    #   2.循环遍历.
    #       (1)遍历字典中所有的key.
    for k in dict1.keys():
        print(k)
    #       (2)遍历字典中所有的value.
    for v in dict1.values():
        print(v)
    #       (3)遍历字典中的所有元素（包括key和value）
    for k, v in dict1.items():
        print(f'元素的key是：{k}，对应的value是：{v}')

    # 新增操作
    dict1['d'] = 100
    print(dict1)

    # 修改操作
    dict1['a'] = 500
    print(dict1)

    # 删除操作
    del(dict1['a'])
    print(dict1)
```

### 1.4 `set`集合

**`set`集合介绍：**

* 集合中不能出现重复的元素，自动去掉重复元素.
* 集合数据是无序的，故不支持下标.

**`set`集合基本操作类型：**

==创建集合：==

``` Python
# 创建非空集合.
set1 = {10, 20, 30, 40}
set2 = set(['abc', 'efg'])

# 创建空集合.
set3 = set()
```

> 如果要创建空集合只能使用`set()`，因为`{}`用来创建空字典.

==查询操作：==

* 查询某一元素是否在集合中

``` Python
set1 = {10, 20, 30, 40}
if 20 in set1:
    print('存在集合中！')
else:
    print('不存在集合中！')
```

* 循环遍历

``` Python
set1 = {10, 20, 30, 40}
for i in set1:
    print(i)
```

==新增操作：==

``` Python
set1 = {10, 20, 30, 40}

# 新增单个元素.
set1.add(50)
set1.add(50)
print(set1)

# 新增多个元素，参数是列表.
set1 = {10, 20, 30, 40}
set1.update([80, 90])
print(set1)
```

==删除操作：==

``` Python
set1 = {10, 20, 30, 40}
set1.remove(10)
print(set1)
```

==修改操作（无法通过下标修改单个元素）：==

``` Python
set1 = {10, 20, 30, 40}
set1.remove(50)
set1.add(100)
print(set1)
```

**代码示例：**

``` Python
    """ 四、set集合（Set） """

    # 创建集合
    #   1.创建非空集合.
    set1 = {10, 20, 30, 40}
    set2 = set(['abc', 12, 'Axiomer', 90])
    print(set1)
    print(set2)
    #   2.创建空集合.
    set3 = set()
    print(set3)

    # 查询操作
    #   1.查询某一元素是否在集合中.
    if 20 in set1:
        print('存在集合中！')
    else:
        print('不存在集合中！')
    #   2.循环遍历.
    for i in set1:
        print(i)

    # 新增操作
    #   1.新增单个元素.
    set1.add(90)
    set1.add(90)
    print(set1)
    #   2.新增多个元素，参数是列表.
    set1.update([100, 110])
    print(set1)

    # 删除操作
    set1.remove(10)
    print(set1)

    # 修改操作（无法通过下标修改单个元素）
    set1.remove(110)
    set1.add(1000)
    print(set1)
```

---

## 二、四种常见容器的比较归纳

| 容器类型 | 定义 | 是否可变 | 是否有有序 | 是否可重复 | 常见操作 |
| --- | --- | --- | --- | --- | --- |
| `List` | `nums = [10, 20, 30]` | 是 | 是（支持切片） | 是 | `index()`; `len()`; `append()`; `insert()`; `pop()`; `remove()` |
| `Tuple` | `nums = (10, 20, 30)` | 否 | 是（支持切片） | 是 | `index()`; `len()` |
| `Dict` | `nums = {'a': 10, 'b': 20, 'c': 30}` | 是 | 否 | `key不可以，但value可以` | `dict[key] = value`; `keys()`; `values()`; `items()`; `len()` |
| `Set` | `nums = {10, 20, 30}` | 是 | 否 | 否 | `add()`; `update()`; `remove()`; `len()` |

---

## 三、课堂小结

勤于将过去学过的知识进行**归纳**、**对比**、**关联**和**总结**：
* 形式：
  * **知识表格**.
  * **思维导图**.
  * **网络拓扑图**.