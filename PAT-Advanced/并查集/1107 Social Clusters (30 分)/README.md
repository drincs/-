# 1107 Social Clusters (30 分)
> When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A social cluster is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.  
> ## Input Specification:  
> Each input file contains one test case. For each test case, the first line contains a positive integer N (≤1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:  
> Ki: hi​​[1] h​i​​[2] ... hi​​[K​i​​]  
> where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].  
> ## Output Specification:  
> For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.  
> ## Sample Input:
```
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
```  
> ## Sample Output:
```
3
4 3 1
```
## 完成时间
24min
## 题目大意
```
社交群：注册社交网络时要求描述爱好推荐相近的网友。一个社交群是一群有共同爱好的人。
输入：
N 总人数 编号1-N（1000人）
N行：k爱好数 k个爱好下标(爱好范围1-1000)
输出：
社交群总数
各个群体人数降序输出
```
## 解题思路
```
合并爱好集合，4 （2 7 10）（5 3 6 8 1） 对应增加人数
```