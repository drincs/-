# 1052 Linked List Sorting (25 分)  
> A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains a positive N (<10<sup>5</sup>​​) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by −1.  
> Then N lines follow, each describes a node in the format:
```
Address Key Next
```  
> where Address is the address of the node in memory, Key is an integer in [−10<sup>5</sup>​​,10<sup>​5</sup>​​ ], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.   
> ## Output Specification:  
> For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.  
> ## Sample Input:
```
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
```
> ## Sample Output:
```
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
```
## 完成时间
30min 
## 题目大意
```
链表排序：链表的存储各块结构内存不相邻。假设每一个结构包含一个整数键值及指向下一地址的指针，现给定一个链表，将其按键值升序排序。
输入：N结点总数 address链表首地址
N行: 地址 键值 下一地址
保证所有键值唯一 链表不成回环
输出：升序输出链表结点
```
## 解题思路
```
键值排序：以非链表形式排序后直接输出（当前地址 键值 下一个地址）
int key[MAXN]
int next[MAXN]
int list[]//找出链表结点
sort(){
    compare(key[list[a]],key[list[b]])    
}
```
## 总结反思
没有1A的原因是漏看了输出要求，审题不仔细，还有就是对空链表的输出处理
