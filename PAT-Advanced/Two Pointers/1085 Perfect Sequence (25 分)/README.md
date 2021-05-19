# 1085 Perfect Sequence (25 分)
> Given a sequence of positive integers and another positive integer p. The sequence is said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers in the sequence, respectively.

> Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

> ## Input Specification:
> Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (≤10<sup>5</sup>​​ ) is the number of integers in the sequence, and p (≤10<sup>9</sup>​​) is the parameter. In the second line there are N positive integers, each is no greater than 10<sup>​9</sup>​​.

> ## Output Specification:
> For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

> ## Sample Input:
```
10 8
2 3 20 4 5 1 6 7 8 9
```
> ## Sample Output:
```
8
```

## 题目大意
给定一个正整数序列和另一个正整数p  
完美序列：序列中最大数M<=最小数mxp  
给一个序列，构成最长的完美序列。  
输出最长完美序列的长度。
## 解题思路
使用双指针解题。
## 总结
需要考虑p*m的值域溢出情况
