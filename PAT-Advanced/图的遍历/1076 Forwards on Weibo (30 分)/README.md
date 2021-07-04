# 1076 Forwards on Weibo (30 分)  
> Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤1000), the number of users; and L (≤6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:
> M[i] user_list[i]  
> where M[i] (≤100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.  
> Then finally a positive K is given, followed by K UserID's for query.  
> ## Output Specification  
> For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can trigger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.  
> ## Sample Input:
```
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
```
> ## Sample Output:
```
4
5
```
## 完成时间  
2137 - 
## 题目大意
```
微博转发：用户在微博上有很多粉丝，关注很多。因此一个社交网被粉丝关系构成。当一个用户发表内容在微博上，所有他的粉丝都能看见并转发，还可以被粉丝的粉丝转发。现在给定一个社交网，你要计算某个用户的最大潜在数量转发数，假设只计算L层。
输入：
N L 用户总数 计算层级
N行: m[i] userlist[i] 用户i的关注数 关注用户编号
保证没人关注自己
K 查询个数 k个用户id
输出：
输出最大潜在转发数
```
## 解题思路
从目标用户的结点开始遍历，L步，可达的结点数 BFS