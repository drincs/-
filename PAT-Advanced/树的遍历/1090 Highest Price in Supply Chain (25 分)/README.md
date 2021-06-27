# 1090 Highest Price in Supply Chain (25 分)
> A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.   
> Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.  
> Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers. 
> ## Input Specification:  
> Each input file contains one test case. For each case, The first line contains three positive numbers: N (≤10<sup>5</sup>​​ ), the total number of the members in the supply chain (and hence they are numbered from 0 to N−1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number S<sub>i</sub>​​ is the index of the supplier for the i-th member. S<sub>​root</sub>​​ for the root supplier is defined to be −1. All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 10<sup>10</sup>​​.  
> ## Sample Input:
```
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
```
> ## Sample Output:
```
1.85 2
```
## 完成时间
2340 - 2357
## 题目大意
```
供应链中的最高价：供应链中有零售商 经销商 供应商，逐级售价提高。给定一个供应链，计算零售商的最高价。
输入：
N P r //结点总数 P原始价格 r提高率
N个数字：Si 第i个结点的供应源，根节点的供应源定义为-1
输出：
零售商最高价 保留2位 以及这样的零售商数量
```
## 解题思路
```
建树计算深度，输出最深对应价格及存在数量
```