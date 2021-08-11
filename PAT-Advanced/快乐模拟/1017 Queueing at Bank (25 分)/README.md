# 1017 Queueing at Bank (25 分)  
> Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.  
> Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10<sup>4</sup>) - the total number of customers, and K (≤100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.  
> Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.  
> ## Output Specification:  
> For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.  
> ## Sample Input:
```
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
```
> ## Sample Output:
```
8.2
```
## 完成时间
30min
## 题目大意
```
银行排队：假设一个银行有K个窗口开放服务。每个窗口前有一个黄线将等待区划为两个部分。所有客户必须在黄线外等候。设定每个窗口最多不得被单个客户占用1个小时。
给定到达时间T以及每个客户需要的处理时间P，告诉他们平均等候时长。
输入：
N 客户总数 ≤10000 K 窗口数量 ≤100
N行：
HH:MM:SS 到达时间 P 处理时长
设定没有两个客户同时到达。
银行营业时间从0800-1700
早到的人必须等到8点，晚于五点到达的人将不会被接待，不计入平均样本。
输出：
保留1位小数
```
## 解题思路
```
需要过滤样本（迟到的不接待）
早于8点到达的客户需要初始化等待时长
需要叠加每个客户的等待时间

时间转化：
将HH:MM:SS转化为秒数T (HH*60+MM)*60+SS
T<8*60*60,wait_T=8*60*60-T

将用户按T升序排序

每个窗口的属性：
窗口服务下一空闲时间

窗口下一空闲时间初始为8*60*60

进入用户后需要更新
窗口满时寻找下一空闲时间最早的窗口


```