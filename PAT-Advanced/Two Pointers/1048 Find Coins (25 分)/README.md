# 1048 Find Coins (25 分)
>$~~~~$ Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10<sup>5</sup>​​ coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

> ## Input Specification:  
> $~~~~$ Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10<sup>5</sup>​​ , the total number of coins) and M (≤10<sup>​3</sup>​​ , the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

> ## Output Specification:  
> $~~~~$ For each test case, print in one line the two face values V<sub>1</sub>​​ and V<sub>​2</sub>​​  (separated by a space) such that V<sub>​1</sub>​​ +V<sub>2</sub>​​ =M and V<sub>​1</sub>​​ ≤V<sub>​2</sub>​​ . If such a solution is not unique, output the one with the smallest V<sub>1</sub>​​ . If there is no solution, output No Solution instead.

> ## Sample Input 1:
```
8 15
1 2 8 7 2 4 11 15
```
> ## Sample Output 1:
```
4 11
```
> ## Sample Input 2:
```
7 14
1 8 7 2 4 11 15
```
> ## Sample Output 2:
```
No Solution
```
## 题目大意
散列、二分分类下已出现  
题目内容不再赘述，换用方法解决问题。
## 解题思路
开始1939
先对硬币价值排序，指针指向头尾两端  
若大于，移动尾指针，若小于移动头指针，直至头尾重叠
## 总结
1次通过，用时15分钟
