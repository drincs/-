# 1068 Find More Coins (30 分)  
> Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 10<sup>4</sup>​​ coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10<sup>4</sup>​​ , the total number of coins) and M (≤10<sup>2</sup>​​ , the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each test case, print in one line the face values V​1​ ≤V2​​ ≤⋯≤Vk​​  such that V1​​ +V​2​​ +⋯+Vk​​ =M  
> All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.  
> Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k≥1 such that A[i]=B[i] for all i < k, and A[k] < B[k].  
> ## Sample Input 1:
```
8 9
5 9 8 7 2 3 4 1
```
> ## Sample Output 1:
```
1 3 5
```
> ## Sample Input 2:
```
4 8
7 2 4 3
```
> ## Sample Output 2:
```
No Solution
```
## 题目大意
```
找到更多的硬币：eva喜欢收集全宇宙的硬币，包括别的星球，例如火星。一天她到接受各种硬币支付的宇宙超市，支付要求是必须准确支付，不找零。她最多有10000个硬币，需要帮助，告诉她是否可以支付。
输入：
N M 硬币总数 支付总数
N个硬币的价值（正）
输出：
可以支付的话
升序输出硬币值+……+硬币值=M
不唯一输出最小的序列，不存在输出No Solution
最小的序列定义：数字小
```
## 解题思路
```
背包体积为M
硬币需排序由大到小
```