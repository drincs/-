# 1014 Waiting in Line (30 分)  
> Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:  
> The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.  
> Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.  
> Customer<sub>i</sub> will take T<sub>i</sub> minutes to have his/her transaction processed.  
> The first N customers are assumed to be served at 8:00am.  
> Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.  
> For example, suppose that a bank has 2 windows and each window may have 2 customers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer<sub>1</sub>​	is served at window<sub>1</sub>​ while customer<sub>2</sub> is served at window<sub>2</sub>. Customer<sub>3</sub> will wait in front of window<sub>1</sub> and customer<sub>4</sub> will wait in front of window<sub>2</sub>. Customer<sub>5</sub>will wait behind the yellow line.At 08:01, customer<sub>1</sub>is done and customer<sub>5</sub>enters the line in front of window<sub>1</sub>since that line seems shorter now. Customer<sub>2</sub>will leave at 08:02, customer<sub>4</sub> at 08:06, customer<sub>3</sub>at 08:07, and finally customer<sub>5</sub>at 08:10.  
> ## Input Specification:  
> Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (≤20, number of windows), M (≤10, the maximum capacity of each line inside the yellow line), K (≤1000, number of customers), and Q (≤1000, number of customer queries).  
> The next line contains K positive integers, which are the processing time of the K customers.  
> The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.  
> ## Output Specification:  
> For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.  
> ## Sample Input:
```
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
```  
> ## Sample Output:
```
08:07
08:06
08:10
17:00
Sorry
```
## 完成时间
2220 - 2334
## 题目大意
```
排队：假设银行有N个窗口开放服务。每个窗口前有条黄线将等待区划为2部分。
排队规则如下：
1、黄线内每个窗口前可以容纳M个人。黄线内满时客户在黄线外等待(第NM+1个人开始)。
2、每个客户进入黄线内时会选择当前队伍最短的窗口。如果有多条队伍一样长，会选择最左边的窗口(编号最小的)。
3、每个客户的业务处理时间是Ti.
4、前n个客户的开始服务时间是早上8点。
现在给定每个客户的处理时间，告诉他们业务处理完成的时间。
例如：有2个窗口 黄线内容纳量为2人。
5个客户 分别需要1 2 6 4 3分钟。
早上8点，客户1到达窗口1，客户2到达窗口2，客户3在窗口1前等待，客户4在窗口2前等待。客户5在黄线外等待。8.01，客户1完成了，客户3开始处理，客户5在窗口1前等待。8.02客户2完成了，8.06客户4完成了，8.07客户3完成了，8.10客户5完成了。
输入：N M K Q 分别为窗口总数 黄线容纳数 客户总数 查询次数
K：客户业务处理时间
Q:查询的用户编号（从1开始）
输出：
业务完成时间
银行17.00关门，17.00前不能被服务的无法得到服务，输出sorry。

```
## 解题思路
```
窗口属性：
下一更新时间
等待队伍

客户属性：
业务需要时间
业务开始时间 1700 对应sorry
```