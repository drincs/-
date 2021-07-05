# 1013 Battle Over Cities (25 分)  
> It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.  
> For example, if we have 3 cities and 2 highways connecting city1​​ -city​2​​  and city​1​​ -city​3​​ . Then if city​1​​  is occupied by the enemy, we must have 1 highway repaired, that is the highway city​2​​ -city​3​​ .  
> ## Input Specification:  
> Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.  
> ## Output Specification:  
> For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.  
> ## Sample Input:
```
3 2 3
1 2
1 3
1 2 3
```
> ## Sample Output:
```
1
0
0
```
## 完成时间
15:23 - 15:48
## 题目大意
```
战争中的城市：战争中所有城市的交通连接非常重要。如果一个城市被敌人侵略，所有出边入边都会被关闭。我们需要快速知道剩余城市的交通完整性需要修复哪些高速。
例如，城市1 城市2 城市3有2条高速，城市1到城市2，城市1到城市3，如果城市1被侵略，我们必须修建一条城市2到城市3的高速，保证交通网。
输入：
N M K//城市总数 剩余高速 需要检查的城市数量
M行：
高速连接的两个城市 编号从1到N
K个数字：受到关注的城市编号
输出：
对每个关注的城市，输出需要修建的高速条数如果该城市失守
```
## 解题思路
```
求去除某点的连通分量个数x,x-1即为需要修建的高速数量。
```