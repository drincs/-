# 1105 Spiral Matrix (25 分)  
> This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has m rows and n columns, where m and n satisfy the following: m×n must be equal to N; m≥n; and m−n is the minimum of all the possible values.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N. Then the next line contains N positive integers to be filled into the spiral matrix. All the numbers are no more than 10<sup>4</sup>. The numbers in a line are separated by spaces.  
> ## Output Specification:  
> For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.  
> ## Sample Input:
```
12
37 76 20 98 76 42 53 95 60 81 58 93
```
> ## Sample Output:
```
98 95 93
42 37 81
53 20 76
58 60 76
```
## 完成时间
40min 
## 题目大意
```
将一组序列按非递增顺序螺旋填充成矩阵。从左上角开始填充，顺时针旋转。矩阵有m行n列，m>=n,m-n尽可能小（即尽可能方正)
输入：
N
N个正整数
所有数字不超过10000
输出：
输出结果矩阵
```
## 解题思路
```
例：
37 76 20 98 76 42 53 95 60 81 58 93
降序排序：
98 95 93 81 76 76 60 58 53 42 37 20
回旋顺时针排列：
98 95 93
42 37 81
53 20 76
58 60 76
矩阵的mn计算：N开根号 向上取整为m 根号12->m=4 n=(12/m)向上取整。
可能会存在部分元素为空 
(0,0)           (0,1)       (0,2)   ……    (0,n-1)
(1,0)           (1,1)       (1,2)   ……    (1,n-1)
……
(m-1,0)         (m-1,1)     (m-1,2) ……    (m-1,n-1)
i=0 j++
j=n-1 i++
i=m-1 j--
j=0 i--

i=1 j++
j=n-2 i++
i=m-2 j--
j=1 i--
……
visited数组
```
## 反思
```
m×n must be equal to N这点被遗漏了，导致测试点1、3不通过，完全填充意味着质数N的m为N本身，n为1。N为平方数时m为根号N，否则m递增直到能被N整除。
```