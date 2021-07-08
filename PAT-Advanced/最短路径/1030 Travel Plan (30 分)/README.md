# 1030 Travel Plan (30 分)
> A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.  
> ## Input Specification:  
> Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (≤500) is the number of cities (and hence the cities are numbered from 0 to N−1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:  
> City1 City2 Distance Cost  
> where the numbers are all integers no more than 500, and are separated by a space.  
> ## Output Specification:  
> For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.  
> ## Sample Input:
```
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
```
> ## Sample Output:
```
0 2 3 3 40
```
## 完成时间
50min
## 题目大意
```
旅行计划：游客地图上有城市间高速距离，以及每条高速的花销。帮助一个游客选择最短的路径从他的开始城市到目的地。如果这样的路径不唯一，输出开销最小的路径，这样的路径保证唯一。
输入：
N M S D 城市总数 高速数量 起点 终点
M行：
城市1 城市2 距离 开销
所有数字都不超过500
输出：
最短路径（总开销最少） 总开销 
```
## 解题思路
```
记录总开销 Dijkstra + DFS
```