# 1138 Postorder Traversal (25 分)  
> Suppose that all the keys in a binary tree are distinct positive integers. Given the preorder and inorder traversal sequences, you are supposed to output the first number of the postorder traversal sequence of the corresponding binary tree.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each test case, print in one line the first number of the postorder traversal sequence of the corresponding binary tree.  
> ## Sample Input:
```
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
```
> ## Sample Output:
```
3
```
## 完成时间
不够快
## 题目大意
```
前序 + 中序 得后序第一个元素
```
## 解题思路
```
大树变2棵小树：
通过先序序列可以确定根结点prel
在中序[inl,inr]遍历中查找得到左子树while(in[i]==pre[prel])
下一查找：prel=prel+1,inl,i-1
直到叶子结点为止
如果没有这样的左子树，那么寻找右子树的左子树递归prel=prel+i-inl+1,i+1,inr
```