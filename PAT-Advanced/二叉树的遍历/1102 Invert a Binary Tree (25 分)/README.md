# 1102 Invert a Binary Tree (25 分)  
> The following is from Max Howell @twitter:  
> Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.  
> Now it's your turn to prove that YOU CAN invert a binary tree!  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node from 0 to N−1, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.  
> ## Output Specification:  
> For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.  
> ## Sample Input:
```
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
```
> ## Sample Output:
```
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
```
## 完成时间
2335 - 0003
## 题目大意
```
反转二叉树：证明你能反转二叉树
输入：正整数N 结点总数 编号0 - N-1
N行：对应0-N-1 给出左右结点编号，不存在用-表示
输出：
层序遍历
中序遍历
```
## 解题思路
```
对于每一个结点给出了其左右孩子，建树怎么建
0的左孩子是1 右无
1是叶子结点
2的左孩子是0
3的左孩子是2 右孩子是7
4是叶子结点
5是叶子结点
6的左孩子是5
7的左孩子是4 右孩子是6
得根节点是3
从各结点高度出发
```
## 总结
反转可以通过后序遍历进行左右子树交换，自下而上