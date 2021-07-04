# 1021 Deepest Root (25 分)  
> A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains a positive integer N (≤10<sup>4</sup>​ ) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N−1 lines follow, each describes an edge by given the two adjacent nodes' numbers.  
> ## Output Specification:  
> For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print Error: K components where K is the number of connected components in the graph.  
> ## Sample Input 1:
```
5
1 2
1 3
1 4
2 5
```
> ## Sample Output 1:
```
3
4
5
```
> ## Sample Input 2:
```
5
1 3
1 4
2 5
3 4
```
> ## Sample Output 2:
```
Error: 2 components
```
## 完成时间：
1628 - 1702
## 题目大意
```
最深的根：一个连通图可以被认为是一棵树，树的高度取决于选择的根结点，现在你被要求找出这样构成的树中最高的树的根结点。这样的结点叫做最深的根结点。
输入：
N 结点总数 1到N N小于等于10000
N-1行：
边的两个端点
输出：
最深的根，不唯一，按编号升序输出。不存在，输出连通块数。
```
## 解题思路
```
BFS 更新层号
连通块数=1{
记录当前根结点及层数
}
>1 输出块数
```
## 总结
第一次AC测试点1未过，考虑特殊数值，n=1时未考虑，控制n为1的输出，通过