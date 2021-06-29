# 1043 Is It a Binary Search Tree (25 分)
> A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:  
> The left subtree of a node contains only nodes with keys less than the node's key.  
> The right subtree of a node contains only nodes with keys greater than or equal to the node's key.  
> Both the left and right subtrees must also be binary search trees.  
> If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.  
> Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.  
> ## Output Specification:
> For each test case, first print in a line YES if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or NO if not. Then if the answer is YES, print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.  
> ## Sample Input 1:
```
7
8 6 5 7 10 8 11
```
> ## Sample Output 1:
```
YES
5 7 6 8 11 10 8
```
> ## Sample Input 2:
```
7
8 10 11 8 6 7 5
```
> ## Sample Output 2:
```
YES
11 8 10 7 5 6 8
```
> ## Sample Input 3:
```
7
8 6 8 5 10 9 11
```
> ## Sample Output 3:
```
NO
```
## 完成时间
较为分散不做记录
## 题目大意
```
它是二叉查找树吗：二叉查找树被定义为:左子树所有数据域小于当前结点
右子树的所有数据域大于等于当前结点;所有左右子树都是二叉查找树。
如果我们交换左右子树，结果树称为镜像BST
给定一序列整数，判断是否是bst或者镜像bst的先序序列
输入：N 
N个数字
输出：是否
是：中序遍历序列
```
## 解题思路
```
建树 遍历
```