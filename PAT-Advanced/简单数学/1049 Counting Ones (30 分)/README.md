# 1049 Counting Ones (30 分)
> The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

> ## Input Specification:  
> Each input file contains one test case which gives the positive N (≤2<sup>30</sup>​​).

> ## Output Specification:
> For each test case, print the number of 1's in one line.

> ## Sample Input:
```
12
```
> ## Sample Output:
```
5
```
## 题目大意
计算1到n中1出现的个数。
## 解题思路
```
n:1's  
1:1  
2:1  
……
9:1  
10:1+1  
11:[10]+2  
12:[11]+1 
100:[99]+1
101:[100]+2
```
以上测试点4、6超时。  
递归过程中实际存在大量相同含1数的数字，12-19等。  
```
分析
利用上面程序，分析大数规律
23010-》19902
    2 3 0 1 0
i   5 4 3 2 1
i=1 可能出现1的次数 2301 [0000'1 0001'1 2300'1]
i=2 可能出现1的次数 230*10++0+1=2301[000'1'x 001'1'x 229'1'x 230'1'0,x为0-9]
i=3 可能出现1的次数 23*10*10=2300[00'1'xx 22'1'xx]
i=4 可能出现1的次数 3*10*10*10=3000[0'1'xxx 2'1'xxx]
i=5 可能出现1的次数 1*10*10*10*10[1'xxxx]
1's=2301+2301+2300+3000+10000=19902
```
## 总结
独立完成该类题目能力有待提高，参考了题解解出