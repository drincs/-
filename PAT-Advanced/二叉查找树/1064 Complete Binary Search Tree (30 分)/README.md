# 1064 Complete Binary Search Tree (30 分) 
> A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:  
> The left subtree of a node contains only nodes with keys less than the node's key.  
> The right subtree of a node contains only nodes with keys greater than or equal to the node's key.  
> Both the left and right subtrees must also be binary search trees.  
> A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.  
> Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.  
> ## Output Specification:  
> For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.  
> ## Sample Input:
```
10
1 2 3 4 5 6 7 8 9 0
```
> ## Sample Output:
```
6 3 8 1 5 7 9 0 2 4
```
## 完成时间
2202 - 2328(有中断)
## 题目大意
```
完全二叉查找树：
二叉查找树的定义有三，一是左子树所有结点小于当前结点值，二是右子树的所有结点数值域大于等于当前结点，三是左子树右子树也是二叉查找树。
完全二叉树CBT被定义为：最底层由左至右按顺序填充。
现给定一个序列（不同的非负数），可以构造一棵唯一的二叉查找树如果同时要求完全二叉树，输出层序遍历序列。
输入：
N
N个唯一的数字
输出：
层序遍历序列
```
## 解题思路
```
高度差不可超过1，建树时，记录高度差，不超过，可插入在当前结点，如果超过，需要调整。
例如
1 2 3 4 5 6 7 8 9 0
观察可得，这样的树中序遍历呈递增顺序
尝试从k层左边开始填充
后发现即按中序遍历数字递增填入
```