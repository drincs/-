# 1079 Total Sales of Supply Chain (25 分)  
> A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.  
> Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.  
> Now given a supply chain, you are supposed to tell the total sales from all the retailers.
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains three positive numbers: N (≤10<sup>5</sup>​​ ), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N−1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:  
> K<sub>​i</sub>​​  ID[1] ID[2] ... ID[K<sub>​ i </sub>​​]

where in the i-th line, K<sub>​i</sub>​​ is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. K<sub>​j</sub>​​ being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after K<sub>​j</sub>​​. All the numbers in a line are separated by a space.
> ## Output Specification:
> For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 10<sup>10</sup>​​.  
> ## Sample Input:
```
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
```
> ## Sample Output:
```
42.4
```
## 题目大意
```
供应链的总销售：一条供应链是一个由零售商、经销商、供应商组成的网络，每个角色都涉及参与在销售到客户的过程中。
从供应商买到的商品价格为P，卖出去（1+r%)P,零售商面对顾客。
给定一个供应链，计算零售商的总销售额。
输入：N供应链成员总数 0-N-1 P 供应商的价格 r 增长率
N行：Ki Ki个ID / 0 零售商产品总数
输出：输出总销售额，保留1位小数
10(N) 1.80(P) 1.00(r)
3 2 3 5 从0分发到2 3 5
1 9     从1分发到9
1 4     从2分发到4
1 7     从3分发到7
0 7     4是零售商
2 6 1   从5分发到6 1
1 8     从6分发到8
0 9     7是零售商
0 4     8是零售商
0 3     9是零售商
0->2->4 7*1.8*(1.01)^2=12.85326
0->3->7 9*1.8*(1.01)^2=16.52562
0->5->6->8 4*1.8*(1.01)^3=7.4181
0->5->1->9 3*1.8*(1.01)^3=5.5636
total=42.4
```
## 解题思路
建静态树并存储叶子结点的深度