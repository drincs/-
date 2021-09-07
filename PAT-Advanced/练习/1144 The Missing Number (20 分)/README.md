# 1144 The Missing Number (20 分)  
> Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N (≤10<sup>5</sup>). Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int.  
> ## Output Specification:  
> Print in a line the smallest positive integer that is missing from the input list.  
> ## Sample Input:
```
10
5 -25 9 6 1 3 4 2 5 17
```
> ## Sample Output:
```
7
```
## 题目大意
```
负数去掉
考虑不在给定数据内的最小的正数
```
## 解题思路
```
哈希建表1-100002 1万个不同的数字可以得到满足
```