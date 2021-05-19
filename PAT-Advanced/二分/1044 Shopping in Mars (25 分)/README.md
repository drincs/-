# 1044 Shopping in Mars (25 分)
> $~~~~$Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M$). When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one. Once a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15. We may have 3 options:  
> $~~~~$ Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).  
> $~~~~$ Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).  
> $~~~~$ Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).  
>$~~~~$ Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.  
>$~~~~$ If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.

> ## Input Specification:
>$~~~~$ Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10<sup>5</sup>​​ ), the total number of diamonds on the chain, and M (≤10<sup>​8</sup>​​), the amount that the customer has to pay. Then the next line contains N positive numbers D<sub>1</sub>​​ ⋯D<sub>​N</sub>​ (D<sub>​i</sub>​​ ≤10<sup>3</sup>​​ for all i=1,⋯,N) which are the values of the diamonds. All the numbers in a line are separated by a space.

> ## Output Specification:
>$~~~~$ For each test case, print i-j in a line for each pair of i ≤ j such that Di + ... + Dj = M. Note that if there are more than one solution, all the solutions must be printed in increasing order of i.  
>$~~~~$ If there is no solution, output i-j for pairs of i ≤ j such that Di + ... + Dj >M with (Di + ... + Dj −M) minimized. Again all the solutions must be printed in increasing order of i.  
>$~~~~$ It is guaranteed that the total value of diamonds is sufficient to pay the given amount.

> ## Sample Input 1:
```
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
```
> ## Sample Output 1:
```
1-5
4-6
7-8
11-11
```
> ## Sample Input 2:
```
5 13
2 4 5 7 9
```

> ## Sample Output 2:
```
2-4
4-5
```
## 题目大意
火星购物：火星人用钻石项链支付，每颗钻石有一个价值，支付时可以从任意位置切开一次取下若干颗。  
求解支付方案，若无法刚好支付，需要多损失一点，提供损失最小的支付方案。  
多个方案按i升序输出，题目保证所有钻石总价足够支付。
## 解题思路
钻石成串，从i=1处记录1-i的和sum，i-j的和=sum[j]-sum[i-1]  
先查找一次判断支付方案的费用。  
再查找同费用其他方案。

