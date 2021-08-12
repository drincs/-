# 1026 Table Tennis (30 分)  
> A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.  
> Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.  
> One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the privilege to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains an integer N (≤10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (≤100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.  
> ## Output Specification:  
> For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.  
> ## Sample Input:
```
10
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 30 0
08:12:00 10 1
20:40:00 13 0
08:01:30 15 1
20:53:00 10 1
20:54:00 10 0
3 1
2
```  
## Sample Output:
```
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:40:00 20:40:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
20:53:00 20:53:00 0
4 3 2
```
## 完成时间
1945 - 1953 2339 - 
## 题目大意
```
乒乓球：一个乒乓球俱乐部有N张桌子对外开放，编号从1到N。每一对选手到达时如有桌空，优先选择编号小的桌子。如果所有桌子都被占用，他们需要排队等待。假设每一对选手最多可以使用2小时。
你的工作是计算队伍中每个人的等待时间，以及每张桌子当天服务次数。
俱乐部会保留一些桌子供vip用户使用。当vip桌开放时，队伍中的第一对会员有特权使用。如果队伍中没有会员，队伍最前面的选手可以使用。如果没有vip桌可用，会员跟普通人一样排队。
输入：
N 选手总数（对） 
N行：HH:MM:SS 到达时间 P 使用时间 tag vip标识 1为vip 0普通
保证所有到达时间在8点到21点之间（俱乐部营业时间）。
K 桌子数 M vip桌子数
M：vip桌子编号
输出：
按服务时间顺序（玩不到的不输出）
到达时间 服务时间 等待时间 保留到分钟
每张桌子服务次数

```
## 解题思路
```
K张桌 M张vip
桌子属性：
编号
下一更新时间 初始为8.00

玩家属性：
到达时间
被服务时间
玩耍时间
vip标识

查找下一安排桌子：更新时间最早的且编号最小的桌子
取时间 看桌子是否vip
时间前队伍有人： 
是： 看队伍中是否有vip
是：安排vip使用
否：安排下一队使用
下一更新时间+=使用时间
队伍无人：
安排时间点之后最早到达的人使用
下一更新时间=到达时间+使用时间
```