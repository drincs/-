# 1072 Gas Station (30 分)  
> A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.  
> Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 4 positive integers: N (≤10<sup>​3</sup>​​), the total number of houses; M (≤10), the total number of the candidate locations for the gas stations; K (≤10<sup>​4</sup>​​), the number of roads connecting the houses and the gas stations; and D<sub>S</sub>​​, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.  
> Then K lines follow, each describes a road in the format  
> P1 P2 Dist  
> where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.  
> ## Output Specification:  
> For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output No Solution.  
> ## Sample Input 1:
```
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
```
> ## Sample Output 1:
```
G1
2.0 3.3
```
> ## Sample Input 2:
```
2 1 2 10
1 G1 9
2 G1 20
```
> ## Sample Output 2:
```
No Solution
```
## 完成时间
1725 - 
## 题目大意
```
加油站：给定一张地图，加油站的候选点，推荐最佳的位置。如果存在多个，输出平均距离最小的那一个；如果仍存在多个，输出下标最小的那个。
输入：
N M K Ds 房子总数 候选点数 道路数 加油站最大服务范围
K行：
P1 P2 dist 道路起点 道路终点(可以是加油站编号也可以是房子编号) 距离
输出：
最佳位置
最短距离 平均距离
选址方法：加油站与所有房子最小距离越远越好
```
## 解题思路
```
所有加油站候选点作为起点遍历
```
## 总结反思
测试点段错误原因分析：p1 p2的输入最多会有5位，字符数组开小了