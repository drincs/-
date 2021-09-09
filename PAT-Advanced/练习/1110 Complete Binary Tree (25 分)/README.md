# 1110 Complete Binary Tree (25 分)  
> Given a tree, you are supposed to tell if it is a complete binary tree.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N (≤20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.  
> ## Output Specification:  
> For each case, print in one line YES and the index of the last node if the tree is a complete binary tree, or NO and the index of the root if not. There must be exactly one space separating the word and the number.  
> Sample Input 1:
```
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
```
> ## Sample Output 1:
```
YES 8
```
> ## Sample Input 2:
```
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
```
> ## Sample Output 2:
```
NO 1
```
## 题目大意
```
完全二叉树：
是否为完全二叉树 判断
给定结点总数编号0-n-1
给出各个结点的左右孩子
是 最后一个结点
否 根结点
```
## 解题思路
```
按照完全二叉树去填空
填不了的就报no
num[10]
先找根结点 没有在孩子里出现的为根结点
1 2 3 4 5 6 7 8 9
6 4 5 0 1 2 3 7 8
```
## 总结反思
字符串数组开边界2，取数的时候判断'\0',白改了半天