# 1032 Sharing (25 分)
> To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, loading and being are stored as showed in Figure 1.  
> ![fig.jpg](./fig.jpg)  
> You are supposed to find the starting position of the common suffix (e.g. the position of i in Figure 1).  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (≤10<sup>5</sup>​​), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by −1.  
> Then N lines follow, each describes a node in the format:
```
Address Data Next
```  
> where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from { a-z, A-Z }, and Next is the position of the next node.  
> ## Output Specification:  
> For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output -1 instead.  
> ## Sample Input 1:
```
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
```
> ## Sample Output 1:
```
67890
```
> ## Sample Input 2:
```
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
```
> ## Sample Output 2:
```
-1
```
## 完成时间
17min
## 题目大意
```
分享：存储英文单词，一种方法是用链表一个字一个字地存。为了节约空间，相同后缀的单词共用相同子链表。
找出公共后缀的起始位置。
输入：结点地址1 结点地址2 （两个单词的头结点） N (结点总数)
N行：地址 字母 下一地址
输出：公共后缀的起点地址，无则输出-1
```
## 解题思路
```
按顺序构建链表，倒序比较，输出结果
```
## 总结
实际与结点字符无关，从末尾匹配最后一个相同结点即可