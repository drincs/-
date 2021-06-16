# 1074 Reversing Linked List (25 分)  
> Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10<sup>5</sup>​​) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.  
> Then N lines follow, each describes a node in the format:
```
Address Data Next
```
> where Address is the position of the node, Data is an integer, and Next is the position of the next node.  
> ## Output Specification:
> For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.  
> ## Sample Input:
```
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
```
> ## Sample Output:
```
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
```
## 完成时间
0857
## 题目大意
```
反转链表：给定一个常量K和一个单向链表L，在链表L上反转每K个元素（K个元素内反转，每组K个）。
输入：首结点地址 N结点总数 K反转长度（地址5位非负整数，空用-1表示）
N行：结点地址 数据 尾指针
输出：结果链表 一个结点一行
```
## 解题思路
```
第一个结点开始->next 直到next==-1
根据k值，足k时反转（根据题意可得L长度6，k=4时，尾部未反转）
struct node{
    int next;
    int data;
};
map<int,node> nodes;
```
## 总结反思
原思路未完全ac，尚不理解原先两个错误点的原因，已经避让了无效结点，尾部结点不反转等情况。解法二是参考网上题解，用纯数组模拟。解法一的其中一个测试点为100000数据，未报超时，使得我毫无头绪。找个时间用真链表做一遍。