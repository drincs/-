# 1096 Consecutive Factors (20 分)
> Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3×5×6×7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.  
> ## Input Specification:  
> Each input file contains one test case, which gives the integer N (1<N<2<sup>31</sup>).  
> ## Output Specification:  
> For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format factor[1]*factor[2]*...*factor[k], where the factors are listed in increasing order, and 1 is NOT included.
> ## Sample Input:
```
630
```
> ## Sample Output:
```
3
5*6*7
```
## 完成时间
12:10 - 12:34
## 题目大意
给定一个正整数，计算连续因子的最大长度，输出最小的连续因子（不含1）。  
输入：N  
输出：最大长度 最小的连续因子（升序）
## 解题思路
```
1 1 0
2 2 1 2
3 3 1 3
4 2*2 4 1 2
5 5 1 5
素数 1 其本身
6 1*2*3
1百搭
8 2*2*2
630 2*3*3*5*7
```
不含1，则被整除的范围为根号n。