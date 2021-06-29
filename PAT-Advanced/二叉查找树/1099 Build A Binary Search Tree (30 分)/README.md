# 1099 Build A Binary Search Tree (30 分) 
> A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:  
> The left subtree of a node contains only nodes with keys less than the node's key.  
> The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.  
> Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.

figBST.jpg  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N (≤100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format left_index right_index, provided that the nodes are numbered from 0 to N−1, and 0 is always the root. If one child is missing, then −1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.  
> ## Output Specification:  
> For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.  
> ## Sample Input:
```
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
```
> ## Sample Output:
```
58 25 82 11 38 67 45 73 42
```
## 完成时间
2335 - 0026(最后细节调试较长时间)
## 题目大意
```
建立二叉查找树：
二叉查找树的定义有三，一是左子树所有结点小于当前结点值，二是右子树的所有结点数值域大于等于当前结点，三是左子树右子树也是二叉查找树。
给定一颗二叉树的结构，不同的数据域序列
输出层序序列
输入：
N 结点总数
N行：从0结点开始左右子树的下标 -1代表无
输出：层序序列
```
## 解题思路
```
观察图可知，根据图1的结构进行中序遍历得到的序列递增
```