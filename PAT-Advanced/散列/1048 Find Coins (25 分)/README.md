# 1048 Find Coins (25 分)
> Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10<sup>5</sup>​​ coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

> ## Input Specification:
> Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10<sup>5</sup>​​, the total number of coins) and M (≤10<sup>3</sup>​​ , the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

> ## Output Specification:
> For each test case, print in one line the two face values V<sub>1</sub>​​ and V<sub>2</sub>​​  (separated by a space) such that V<sub>​1</sub>​​ +V<sub>2</sub>​​ =M and V<sub>1</sub>​​ ≤V<sub>2</sub>. If such a solution is not unique, output the one with the smallest V<sub>1</sub>. If there is no solution, output No Solution instead.

> ## Sample Input 1:
<pre><code>
8 15
1 2 8 7 2 4 11 15
</code></pre>
> ## Sample Output 1:
> 4 11
> ## Sample Input 2:
<pre><code>
7 14
1 8 7 2 4 11 15
</code></pre>
> ## Sample Output 2:
> No Solution

## 题目大意
<pre>
Eva喜欢收集全宇宙各地的硬币，包括别的行星，例如火星。
宇宙商店交易规则：每次使用2个硬币支付
让我告诉eva她能不能买，并且给出两个硬币差异最大的解决方案。
</pre>
## 解题思路
<pre>
硬币数量100000上限，支付金额上限1000，硬币数额上限500.
开一个硬币数组 coins[501],记录硬币的数量。
</pre>
## 总结
数组开500不够，支付金额上限是1000。