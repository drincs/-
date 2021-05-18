# 1010 Radix (25 分)
> Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is yes, if 6 is a decimal number and 110 is a binary number.  
> Now for any pair of positive integers N<sub>1</sub>​​  and N<sub>2</sub>​​ , your task is to find the radix of one number while that of the other is given.

> ## Input Specification:
> Each input file contains one test case. Each case occupies a line which contains 4 positive integers:  
> N<sub>1</sub> N<sub>2</sub> tag radix  
> Here N<sub>1</sub> and N<sub>2</sub> each has no more than 10 digits. A digit is less than its radix and is chosen from the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number radix is the radix of N<sub>1</sub> if tag is 1, or of N<sub>2</sub> if tag is 2.

> ## Output Specification:
> For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

> ## Sample Input 1:
```
6 110 1 10
```
> ## Sample Output 1:
```
2
```
> ## Sample Input 2:
```
1 ab 1 2
```
> ## Sample Output 2:
```
Impossible
```
## 题目大意
给一对正整数，以及其中一个数的进制数，判断两数是否可以相等，找出使两数相等的进制数。  
输入：N<sub>1</sub> N<sub>2</sub> tag radix  
给定tag值，1,则N1的进制为radix，否则为N2的进制。  
输出：另外一个进制数（存在多个输出最小的，不存在输出impossible）
## 解题思路
N<sub>1</sub>、N<sub>2</sub>不超过10位，每位可以是{0-9，a-z},输入时将一个数字转化为10进制数，再去找匹配的进制数，从数字的最大数+1的进制开始匹配。