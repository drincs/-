# 1018 Public Bike Management (30 分)  
> There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.  
> The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.  
> When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.  
> The above figure illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3​​, we have 2 different shortest paths:  
> * PBMC -> S1​​ -> S​3​​.In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S​1​​  and then take 5 bikes to S3​​ , so that both stations will be in perfect conditions.  
> * PBMC -> S​2 -> S​3​​ . This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (≤100), always an even number, is the maximum capacity of each station; N (≤500), the total number of stations; Sp​​ , the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers C​i​​ (i=1,⋯,N) where each Ci​​  is the current number of bikes at S​i​​ respectively. Then M lines follow, each contains 3 numbers: S​i​​ , S​j​​ , and T​ij​​  which describe the time Tij​​  taken to move betwen stations S​i​​  and Sj​​ . All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0−>S1​​ −>⋯−>S​p​​ . Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp​​ is adjusted to perfect.  
> Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.  
> ## Sample Input:
```
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
```
> ## Sample Output:
```
3 0->2->3 0
```
## 完成时间
1h
## 题目大意
```
公共自行车管理：公共自行车服务提供便捷。可以在城市中的任意一个站点租车，任意其他站点还车。
管理中心PBMC实时监控站点容量，半满是最佳状态。如果站点全空或者全满，PBMC将要调整使其达到半满，沿路的站点也会被调整。
问题站点上报时，PBMC选择最短路径到达该站点。如果存在多条，选择需要从PBMC中送出车辆最少的路径。
输入：
Cmax 偶数 站点最大容量 N 站点总数 Sp 问题站点下标 M道路总数
N个非负数 Ci 站点Si的车辆数
M行：Si Sj Tij 从Si移动到Sj的时间
输出：
PBMC出车数 路径 PBMC回车数
如果路径不唯一，输出带回数量最少的。
```
## 解题思路
```
带出数带回数最小
```
## 总结反思
原思路是边找最短路径的同时确定带出数带回数最小的情况，后面发现在确定路径终点之前，对于带回数是无法确定的，因此需要确定路径之后再去对第二标尺第三标尺进行处理。