# 1023 Have Fun with Numbers (20 分)
> Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!  
> Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.  
> ## Input Specification:  
> Each input contains one test case. Each case contains one positive integer with no more than 20 digits.  
> ## Output Specification:  
> For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.  
> ## Sample Input:  
```
1234567899
```
> ## Sample Output:
```
Yes
2469135798
```
## 完成时间
23:30 - 23:50
## 题目大意
给定k位的数字，x2的结果是不是由原数字组成  
输入：不超过20位的正整数  
输出：如果是输出Yes，否则输出No，输出乘积
## 解题思路
```
10^20*2 超出2^64
用数组表示大数 n[22] 0为低位 
原数 数字个数len[10]
乘积 res[22]
数字个数 len_r[10]
```