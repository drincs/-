# 1020 Tree Traversals (25 分)
> Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.  
> ## Sample Input:
```
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
```
> ## Sample Output:
```
4 1 6 3 5 7 2
```
## 完成时间
2206 - 2241
## 题目大意
```
树的遍历：假设二叉树的所有结点数值唯一（正整数）。给定后序序列及中序序列，输出层序序列。
输入：正整数N 二叉树节点总数
后序序列
中序序列
输出：一行输出层序序列
```
## 解题思路
```
根据后序中序序列建二叉树，再层序输出（bfs)
建树：
后序(子序列)最右为当前根结点
```