# 1133 Splitting A Linked List (25 分)
> Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0, K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18→7→-4→0→5→-6→10→11→-2 and K being 10, you must output -4→-6→-2→7→0→5→10→18→11.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10<sup>5</sup>) which is the total number of nodes, and a positive K (≤10<sup>3</sup>). The address of a node is a 5-digit nonnegative integer, and NULL is represented by −1.  
> Then N lines follow, each describes a node in the format:  
```
Address Data Next
```
> where Address is the position of the node, Data is an integer in [−10<sup>5</sup>,10<sup>5</sup> ], and Next is the position of the next node. It is guaranteed that the list is not empty.  
> ## Output Specification:  
> For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.  
> ## Sample Input:
```
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
```
> ## Sample Output:
```
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
```
## 完成时间
1411 - 1444
## 题目大意
```
分割链表：
给定一个单向链表，要求让所有负数出现在非负数之前，0-k的值出现在大于K的值之前，内部顺序不打乱。
例如给定18→7→-4→0→5→-6→10→11→-2 K=10
输出-4→-6→-2→7→0→5→10→18→11
输入：
首结点地址 N 结点总数 K
结点地址 5位非负整数 -1代表空
N行：
地址 数据 下一地址
保证链表不为空
输出：
按顺序输出链表结点。
```
## 解题思路
```
00100 9 10
map存储
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
1、链表结构存储
2、分表处理
负数进一表a
0-k进一表b
剩余一表c
00100 18 进c
访问12309
直至
访问-1
```