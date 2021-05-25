# 1078 Hashing (25 分)
> The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.  
> Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (≤10<sup>4</sup>) and N (≤MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.
> ## Output Specification:  
> For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.  
> ## Sample Input:
```
4 4
10 6 4 15
```
> ## Sample Output:
```
0 1 4 -
```
## 完成时间
23:50 - 00:25
## 题目大意
向哈希表中插入一个不重复的正整数序列，输出输入的数字下标，H(key)=key%TSize,增量解决重复问题？  
注意表大小最好为素数，如果不是素数，重定义为最接近的素数（大于原大小）。  
输入：
```
第一行：MSize N //原定义表大小，N序列长度
第二行：N个数字
```
输出：
```
输出对应输入数字的下标，一行输出，控制空格，无法插入输出-
```
## 解题思路
```
分析示例：
4 4         //非素数，调整为5
10 6 4 15   //10%5==0 6%5=1 4%5=4 15%5=0已存在
```
对于题目及示例没看懂无法插入的情况如何定义,[Quadratic probing (with positive increments only) is used to solve the collisions.],但肯定不是线性增1，
## 总结
Quadratic probing 为二次方探查法，题目说明正向解决冲突。
测试点2、3是因为哈希表大小开小了，10001是不够的，因为接近的素数会大于该数。