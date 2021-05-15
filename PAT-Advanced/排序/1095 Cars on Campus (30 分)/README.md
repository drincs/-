# 1095 Cars on Campus (30 分)
> Zhejiang University has 8 campuses and a lot of gates. From each gate we can collect the in/out times and the plate numbers of the cars crossing the gate. Now with all the information available, you are supposed to tell, at any specific time point, the number of cars parking on campus, and at the end of the day find the cars that have parked for the longest time period.

> ## Input Specification:
> Each input file contains one test case. Each case starts with two positive integers N (≤10<sup>​4</sup>​​ ), the number of records, and K (≤ 8×10 <sup>4</sup>​​ ) the number of queries. Then N lines follow, each gives a record in the format:<br>
> plate_number hh:mm:ss status<br>
> where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents the time point in a day by hour:minute:second, with the earliest time being 00:00:00 and the latest 23:59:59; and status is either in or out.

> Note that all times will be within a single day. Each in record is paired with the chronologically next record for the same car provided it is an out record. Any in records that are not paired with an out record are ignored, as are out records not paired with an in record. It is guaranteed that at least one car is well paired in the input, and no car is both in and out at the same moment. Times are recorded using a 24-hour clock.

> Then K lines of queries follow, each gives a time point in the format hh:mm:ss. Note: the queries are given in ascending order of the times.

> ## Output Specification:
> For each query, output in a line the total number of cars parking on campus. The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.

> ## Sample Input:
<pre><code>
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
</code></pre>
> ## Sample Output:
<pre><code>
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
</code></pre>
## 题目大意
浙江大学有8个校区以及很多大门，我们可以收集到车辆进出大门的时间及车牌号，按任意时间点查询停车数量及停车时间最久的车。
<pre><code>
输入：记录条数n 查询数k
n行： 车牌 时间 状态
无法配对的进出记录需要忽略，输入中保证至少有一对匹配的记录
k行: 时间（升序）
输出：
当前停车总量
停车时间最长的车牌号 停车时长 多选字母表序在前的车牌
</code></pre>
## 解题思路
<pre><code>
1、按车牌号 按时间 按状态排序 得到有效出入记录
2、根据匹配情况计算每次的停车时长
3.1、处理查询
3.2、计算每辆车的停车总时长
</code></pre>
## 总结
需要加强练习，加快速度