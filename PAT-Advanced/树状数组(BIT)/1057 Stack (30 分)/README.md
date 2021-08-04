# 1057 Stack (30 分)
> Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains a positive integer N (≤10<sup>5</sup> ). Then N lines follow, each contains a command in one of the following 3 formats:  
```
Push key
Pop
PeekMedian
```  
> where key is a positive integer no more than 10<sup>5</sup>.  
> ## Output Specification:  
> For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print Invalid instead.  
> ## Sample Input:
```
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
```
> ## Sample Output:
```
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
```
## 完成时间
32min
## 题目大意
```
栈：栈是最基础的数据结构，基于先进后出的原则。基本操作包括push(在栈顶插入元素)、pop(删除栈顶元素)。现在你要实现一个栈，增加一个操作：peekmedian（返回栈中所有元素的中位数).中位数的定义：N个元素中，如果N是偶数，为第N/2小的；如果N是奇数，为第(N+1)/2个数。
输入：
N
操作
输出：
push不输出
pop或者peekmedian输出返回值
指令无效输出invalid
```
## 解题思路
```
push：
update(x)
pop：
update(-x)

利用树状数组求解：
hash数组记录每个元素出现的个数
树状数组解决hash数组的求和问题
寻找第一个满足条件getSum(i)>=K的i
```
