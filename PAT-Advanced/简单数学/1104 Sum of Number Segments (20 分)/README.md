# 1104 Sum of Number Segments (20 分)
> Given a sequence of positive numbers, a segment is defined to be a consecutive subsequence. For example, given the sequence { 0.1, 0.2, 0.3, 0.4 }, we have 10 segments: (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) and (0.4).  
> Now given a sequence, you are supposed to find the sum of all the numbers in all the segments. For the previous example, the sum of all the 10 segments is 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N, the size of the sequence which is no more than 10<sup>5</sup>​​. The next line contains N positive numbers in the sequence, each no more than 1.0, separated by a space.  
> ## Output Specification:  
> For each test case, print in one line the sum of all the numbers in all the segments, accurate up to 2 decimal places.  
> ## Sample Input:
```
4
0.1 0.2 0.3 0.4
```
> ## Sample Output:
```
5.00
```
## 题目大意
给定一个正整数序列，片段被定义为一个连续的序列，所有片段求和。
## 解题思路
1 2 3 …… n-1 n  
1 1到2 …… 1到n-1 1到n 存在n个1 n-1个2 1个n
2 2到3 …… 2到n        存在n-1个2 n-2个3 1个n
……                    ……
n                  存在1个n
1：n
2：2(n-1) 
3: 3(n-2) 
……
n：n
=>i*(n-i+1)  
从0开始：(i+1)*(n-i)
## 总结
测试点2：结果数据的精度问题，改用long double通过