# 1086 Tree Traversals Again (25 分)  
> An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.  
> ![fig.jpg](./fig.jpg)
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.  
> ## Output Specification:  
> For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.  
> ## Sample Input:
```
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
```
> ## Sample Output:
```
3 4 2 6 5 1
```
## 完成时间
2246 - 2330
## 题目大意
```
树的再遍历：二叉树的中序遍历用栈模拟。例如，假设一颗6结点的二叉树，数字1到6，入栈1，入栈2，入栈3，出栈，出栈，入栈4，出栈，出栈，入栈5，入栈6，出栈，出栈。
给出这二叉树的后序序列
输入：正整数N 结点总数
2N行：栈的操作
输出：输出对应的后序遍历序列。
```
## 解题思路
```
根据栈的操作：
push的序列是先序序列
pop的序列是中序序列
重建二叉树
输出后序遍历序列
```
## 总结
对题目隐藏信息不敏感，只看见了栈的模拟结果是中序遍历序列。