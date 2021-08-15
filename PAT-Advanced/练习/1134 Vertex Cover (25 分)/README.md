# 1134 Vertex Cover (25 分)  
> A vertex cover of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. Now given a graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than 10<sup>4</sup>), being the total numbers of vertices and the edges, respectively. Then M lines follow, each describes an edge by giving the indices (from 0 to N−1) of the two ends of the edge.  
> After the graph, a positive integer K (≤ 100) is given, which is the number of queries. Then K lines of queries follow, each in the format:  
> N<sub>v</sub>​ v[1] v[2]⋯v[ N<sub>v</sub> ​]  
> where N<sub>v</sub> is the number of vertices in the set, and v[i]'s are the indices of the vertices.  
> ## Output Specification:  
> For each query, print in a line Yes if the set is a vertex cover, or No if not.  
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
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
```
> ## Sample Output:
```
No
Yes
Yes
No
No
```
## 完成时间
1617 - 1639 1845 - 1918
## 题目大意
```
现给定一个图以及点集合，每一个是否都能覆盖。
输入：
N M 点数 边数
M行：一条边的两个点
K 查询数
K行：
点数量v v个点下标
输出：
是否覆盖Yes or No
```
## 解题思路
```
乍一看不太明白，结合用例看一看
10个点 11条边
每条边至少有一个在被查询集合内的点
对于集合{0,3,8,4}，
如8-7，8在集合内；6-8，8在集合内；4-5，4在集合内；
8-4，在集合内；8-1，8在集合内；1-2，不存在，输出No
对于集合{6，1，7，5，4，9}
如8-7，7在集合内；6-8，6在集合内；4-5，在集合内；
8-4，4在集合内；8-1，1在集合内；1-2，1在集合内；
1-4，在集合内；9-8，9在集合内；9-1，在集合内；
1-0，1在集合内；2-4，4在集合内。输出Yes
对于集合{2,8}，
如8-7，8在集合内；6-8，8在集合内；4-5不存在，输出no

记录
各点所连接的边的编号
如
vertex[i]={x,y,z}
判断集合时
遍历集合内各点
将已访问过的边标记为1 
判断11条边是否皆已访问
hash[m]==1?
```