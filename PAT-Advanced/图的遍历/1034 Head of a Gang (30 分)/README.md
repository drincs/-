# 1034 Head of a Gang (30 分)  
> One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:  
> Name1 Name2 Time  
> where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.  
> ## Output Specification:  
> For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.  
> ## Sample Input 1:
```
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
```
> ## Sample Output 1:
```
2
AAA 3
GGG 3
```
> ## Sample Input 2:
```
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
```
> ## Sample Output 2:
```
0
```

## 完成时间
1706 - 1800
## 题目大意
```
黑帮老大：警察找黑帮老大的方法是检查通话记录。如果a跟b之间有通话，我们认为他们有联系。联系权值等于两人通话总时长。一群超过2个人且该群通话总时长大于等于K,则为黑帮。在每个黑帮内，点权值最大的为黑帮老大。给定一系列通话记录，找出黑帮及他们的老大。
输入：
N K //小于等于1000 N通话记录总数 k阈值
N行：姓名1 姓名2 时长
姓名三个字母A到Z，时长不超过1000分钟。
输出：
黑帮总数
每个黑帮的老大姓名 以及 总人数
题目保证老大不重复，输出按头目的字典序升序输出。
```
## 解题思路
```
1000条记录，姓名上限2000个，姓名需要跟数值映射。
黑帮群 需要先计算连通块数 各连通块内同时满足人数>2 总时长>=k时为黑帮，记录黑帮信息
```
## 总结
邻接矩阵开空间的时候需要注意需要按n的2倍开，否则会出现测试点段错误。