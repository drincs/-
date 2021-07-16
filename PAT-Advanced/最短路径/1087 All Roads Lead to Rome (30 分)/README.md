# 1087 All Roads Lead to Rome (30 分)  
> Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 2 positive integers N (2≤N≤200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N−1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format City1 City2 Cost. Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.  
> ## Output Specification:  
> For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommanded. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.  
> Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommanded route. Then in the next line, you are supposed to print the route in the format City1->City2->...->ROM.  
> ## Sample Input:
```
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
```  
> ## Sample Output:
```
3 3 195 97
HZH->PRS->ROM
```
## 完成时间
0925 - 
## 题目大意
```
条条道路通罗马：实际上有很多不同的旅游线路从我们的城市到罗马。找出开销最少获得幸福最多的路线。
输入：
N K name 城市总数 城市间路线总数 起点城市名称
N-1行：
城市名字 幸福值
K行：
城市间路线 起点 终点 开销
城市名字是3个大写字母，目的地永远是ROM代表罗马

寻找开销最小的路线，如果不唯一，幸福最多的。如果还不唯一，那就是平均幸福最多的
输出：
开销最小的路线总数 开销 幸福值 平均幸福(整数部分)
路线具体
```
## 解题思路
```
以开销作为边权，城市幸福作为点权。
寻找边权最小的路径，同时点权最大，点权相同的路径保留，后面对路径结果做平均值比较
城市名与编号映射
设定起点编号为0
```
## 总结
审题有误，题目求最小边权的路径数，因此在遍历过程中只比较边权值，点权皆在路径确定后比较。