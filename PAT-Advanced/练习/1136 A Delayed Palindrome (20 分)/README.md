# 1136 A Delayed Palindrome (20 分)  
> Consider a positive integer N written in standard notation with k+1 digits a<sub>i</sub>​	as a<sub>k</sub> ⋯a<sub>1</sub> a <sub>0</sub> with 0≤a<sub>i</sub> <10 for all i and a<sub>k</sub> >0. Then N is palindromic if and only if a<sub>i</sub> = a<sub>k-i</sub> for all i. Zero is written 0 and is also palindromic by definition.  
> Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called a delayed palindrome. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number )  
> Given any positive integer, you are supposed to find its paired palindromic number.  
> ## Input Specification:  
> Each input file contains one test case which gives a positive integer no more than 1000 digits.  
> ## Output Specification:  
> For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:  
> A + B = C  
> where A is the original number, B is the reversed A, and C is their sum. A starts being the input number, and this process ends until C becomes a palindromic number -- in this case we print in the last line C is a palindromic number.; or if a palindromic number cannot be found in 10 iterations, print Not found in 10 iterations. instead.  
> ## Sample Input 1:
```
97152
```
> ## Sample Output 1:
```
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
```
> ## Sample Input 2:
```
196
```
> ## Sample Output 2:
```
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
```
## 完成时间
10:15-13:15 考试模拟
## 题目大意
```
迟延的回文数：
考虑一个正整数N
回文数字
0写作0，也是回文数
非回文数可以通过一系列操作匹配成回文数。
操作：非回文数反序与正序相加，直到结果为回文数。
给定任何正整数，找出匹配的回文数。
输入：
不超过1000位的回文数
输出：
找到回文数的过程
A + B = C
A是原数，B是反序
C为回文数时输出 C is a palindromic number.
10步内达不到，输出Not found in 10 iterations.
```
## 解题思路
```
大数求和（1000位）10步 数字长度需要开到1001以上。
字符串反序相加求和
回文判断函数
```