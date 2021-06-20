# 1154 Vertex Coloring (25 分)  
> A proper vertex coloring is a labeling of the graph's vertices with colors such that no two vertices sharing the same edge have the same color. A coloring using at most k colors is called a (proper) k-coloring.  
> Now you are supposed to tell if a given coloring is a proper k-coloring.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than 10<sup>4</sup>​​), being the total numbers of vertices and edges, respectively. Then M lines follow, each describes an edge by giving the indices (from 0 to N−1) of the two ends of the edge.  
> After the graph, a positive integer K (≤ 100) is given, which is the number of colorings you are supposed to check. Then K lines follow, each contains N colors which are represented by non-negative integers in the range of int. The i-th color is the color of the i-th vertex.  
> ## Output Specification:  
> For each coloring, print in a line k-coloring if it is a proper k-coloring for some positive k, or No if not.  
> ## Sample Input:
```
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
4
0 1 0 1 4 1 0 1 3 0
0 1 0 1 4 1 0 1 0 0
8 1 0 1 4 1 0 5 3 0
1 2 3 4 5 6 7 8 8 9
```
> ## Sample Output:
```
4-coloring
No
6-coloring
No
```
## 完成时间：
1730 - 1753
## 题目大意：
```
输入： N M v 边数
M行：两端
K 判断个数
K行 N个颜色
// 输出是否K-coloring 每条线的两端颜色要求不一样 有几个颜色就叫几coloring
```
## 解题思路：
```
存储各线段两端结点下标，遍历判断
```
## 总结
需要注意对各个判断的颜色总数计算是针对点的而非线的，对单点的颜色不能忽视。