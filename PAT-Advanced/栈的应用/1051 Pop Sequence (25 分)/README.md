# 1051 Pop Sequence (25 分)
> Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.  
> ## Sample Input:
```
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
```
> ## Sample Output:
```
YES
NO
NO
YES
NO
```
## 完成时间
22:05 - 22:27(中间还去开了个洗衣机)
## 题目大意
```
弹出序列：给定一个栈，最多存储M个数，按顺序压入N个数字，任意弹出。给定一个序列，判断是否可能是这个栈的弹出序列。
输入：M N K //栈容量 压入序列长度 弹出序列个数
K行：N长度的弹出序列
输出：YES or NO
```
## 解题思路
```
栈的操作具有先进后出，后进先出的特点
模拟：
栈顶为空 压入1
栈顶=seq[pos] 出栈1
栈顶为空 压入2
……
栈顶7=seq[6] 出栈7 YES
3 2 1 7 5 6 4
栈顶为空 压入1
栈顶不等 继续压入2
栈顶不等 继续压入3
栈顶=seq[pos] 出栈3
栈顶=seq[pos] 出栈2
栈顶=seq[pos] 出栈1
栈顶为空 压入4
栈顶不等 继续压入5
栈顶不等 继续压入6
栈顶不等 继续压入7
栈顶=seq[pos] 出栈7
栈顶不等 且无下一个数 NO

* 空栈//栈顶不等压入
* 栈顶相等出栈
* 无法操作输出NO
```

