# 1040 Longest Symmetric String (25 分)
> Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given Is PAT&TAP symmetric?, the longest symmetric sub-string is s PAT&TAP s, hence you must output 11.  
> ## Input Specification:  
> Each input file contains one test case which gives a non-empty string of length no more than 1000.  
> ## Output Specification:  
> For each test case, simply print the maximum length in a line.  
> ## Sample Input:
```
Is PAT&TAP symmetric?
```
> ## Sample Output:
```
11
```
## 完成时间
19min
## 题目大意
```
最长回文子串：给定一个字符串，输出最长回文子串长度。例如，给定 Is PAT&TAP symmetric?,最长回文子串为s PAT&TAP s,因此输出11.
输入：
非空字符串长度不超过1000
输出：
最大长度
```
## 解题思路
```
dp[i][j]表示S[i]到S[j]是否为回文子串，是的为1，不是为0。
初始化边界
dp[i][i]=1
dp[i][i+1]=(S[i]==S[i+1]?1:0)
从长度为3开始枚举循环，保证计算结果基于已计算结果
```
