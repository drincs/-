# 1033 To Fill or Not to Fill (25 分)
> With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. <br>

> Different gas station may give different price. You are asked to carefully design the cheapest route to go.

> ## Input Specification:
> Each input file contains one test case. For each case, the first line contains 4 positive numbers: C<sub>max</sub>​ (≤ 100), the maximum capacity of the tank; D (≤30000), the distance between Hangzhou and the destination city; D<sub>avg</sub>(≤20), the average distance per unit gas that the car can run; and N (≤ 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: P<sub>​i</sub>​​ , the unit gas price, and D<sub>​i</sub>​​ (≤D), the distance between this station and Hangzhou, for i=1,⋯,N. All the numbers in a line are separated by a space.

> ## Output Specification:
> For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print The maximum travel distance = X where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

> ## Sample Input 1:
<pre>
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
</pre>
> ## Sample Output 1:
<pre>
749.17
</pre>
> ## Sample Input 2:
<pre>
50 1300 12 2
7.10 0
7.00 600
</pre>
> ## Sample Output 2:
<pre>
The maximum travel distance = 1200.00
</pre>

## 题目大意
<pre>
加油站加油问题
油箱容量受限，开长途的时候需要找加油站加油。不同的加油站价格不一样，设计一条加油路线使得油费最便宜。总费用结果保留两位小数，到达不了终点输出最远距离，保留两位小数。
</pre>
## 解题思路
<pre>
Cmax油箱容量上限100，D目的地距离上限30000，Davg油耗(每升跑的公里数)上限20，n加油站总数上限500.
题目设定油箱初始为空。
在0km处需要加油
设定加满可跑距离Dmax=Cmax*Davg
设定即将加油站pos
下一个加油站next
油箱到达pos的剩余油量Cpos
加油处理：
在pos站加油的加油量num：pos往后Dmax内最便宜的加油站为next
1、计算到达next的用油量
需要的油量need=(next.x-pos.x)/Davg
2、计算加油量
pos.price>=next.price:
num=need-Cpos?need-Cpos:0 
pos.price < next.price：
加满：num=Cmax-Cpos
3、更新pos及Cpos
Cpos=Cpos+num-need;
pos=next;
</pre>
## 反思
<pre>
思路错了，不是加油到最便宜的车站，而是如果下一个加油站便宜就加刚好的油到下一个，如果范围内没有那就加满，再到范围内最便宜的。
</pre>