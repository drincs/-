# 1135 Is It A Red-Black Tree (30 分)  
> There is a kind of balanced binary search tree named red-black tree in the data structure. It has the following 5 properties:  
> (1) Every node is either red or black.  
> (2) The root is black.  
> (3) Every leaf (NULL) is black.  
> (4) If a node is red, then both its children are black.  
> (5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.  
> For example, the tree in Figure 1 is a red-black tree, while the ones in Figure 2 and 3 are not.
```
rbf1.jpg	rbf2.jpg	rbf3.jpg
Figure 1	Figure 2	Figure 3
```  
> For each given binary search tree, you are supposed to tell if it is a legal red-black tree.  
> ## Input Specification:  
> Each input file contains several test cases. The first line gives a positive integer K (≤30) which is the total number of cases. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the preorder traversal sequence of the tree. While all the keys in a tree are positive integers, we use negative signs to represent red nodes. All the numbers in a line are separated by a space. The sample input cases correspond to the trees shown in Figure 1, 2 and 3.  
> ## Output Specification:  
> For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.  
> ## Sample Input:
```
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
```
> ## Sample Output:
```
Yes
No
No
```
## 完成时间
2116 - 
## 题目大意
```
是否红黑树：
数据结构中有一种平衡二叉树叫做红黑树。
定义：
1、每个结点不是红就是黑。
2、根结点是黑。
3、每个叶子结点是黑。
4、如果一个结点是红，所有孩子结点是黑。
5、每个结点，到它所有的叶子结点最短路径经过的黑结点数相同。
给出平衡二叉树，判断是否为红黑树。
输入：
K 测试用例总数
K：{
    N 结点总数
    先序序列 负数代表红结点。所有结点值为正数。
}
输出：{
    是否红黑树
}
```
## 解题思路
```
二叉查找平衡树 比根结点小的往左子树插入，比根结点大的往右子树插入
根据先序序列建树
根结点为第一个元素
考点：AVL的建立过程（插入，左右旋）
红黑树判断：
1、根结点为正数
2、叶子结点是正数
3、红结点的孩子结点判断
4、结点到叶子结点经过的黑结点数
边建边判断123

```