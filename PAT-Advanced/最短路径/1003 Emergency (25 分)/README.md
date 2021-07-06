# 1003 Emergency (25 分)  
> As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.  
> ## Input Specification:  
> Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C1​ and C​2​​  - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1​​, c​2​​ and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1​ to C​2​.
> ## Output Specification:  
> For each test case, print in one line two numbers: the number of different shortest paths between C1​​ and C​2​​, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.  
> # Sample Input:
```
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
```
> ## Sample Output:
```
2 4
```
## 完成时间
1h
## 题目大意
```
急救中心：作为城市的紧急救生队长，你被给到一张地图。地图上展示了一些城市，部分之间道路相连。每个城市都有一定的救生队，城市间道路长度也被标记出来。当其他城市紧急求救，你的工作是引导队内的人去尽快安置，同时，号召尽可能多的帮助在路上。
输入：
N M C1 C2 分别为城市总数 道路总数 所在城市 救援城市
N整数：各个城市的救援队数量
M行：
c1 c2 L 相连的城市 及该路长度
保证至少存在一条从C1到C2的路
输出：
最短的路径条数 最多能召集到的救援队数量
```
## 解题思路
```
记录边权 最小消耗c
记录点权 最大w
在d[u]时处理
```