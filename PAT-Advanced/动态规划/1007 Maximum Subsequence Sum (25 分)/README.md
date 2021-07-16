# 1007 Maximum Subsequence Sum (25 分)  
> Given a sequence of K integers { N1​​ , N​2​​ , ..., N​K}. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj} where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.  
> Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.  
> ## Input Specification:  
> Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.  
> ## Output Specification:  
> For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.  
> ## Sample Input:  
```
10  
-10 1 2 3 4 -5 -23 3 7 -21
```
> ## Sample Output:
```
10 1 4
```
## 完成时间
25min 
## 题目大意
```
最大连续子序列和：给定一个k个整数的序列，求最大连续子序列的和。例如，给定{-2,11,-4,13,-5,-2},连续子序列的和最大的序列是{11,-4,13}，和为20.
要求找出最大连续子序列的和，以及序列的首尾元素。
输入：
K
K个数字
输出：
最大和 首元素 尾元素（如果不唯一，输出位置最靠前的子序列）
如果所有数字都是负数，最大连续子序列的和定义为0，输出整个序列的首尾元素
```
## 解题思路
```
存储序列num[]
记录当前位置和add[]
add[j]=max(num[j],add[j-1]+num[]) 
判断add[j]中最大值即为最大连续子序列的和
i的位置？
辅助变量start[]
初始化start[0]=0
add[j]赋值时取num[j]时start[j]=j 否则为start[j-1]
```
## 总结
两个循环亦可合并