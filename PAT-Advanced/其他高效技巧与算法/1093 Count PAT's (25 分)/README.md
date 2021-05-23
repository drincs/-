# 1093 Count PAT's (25 分)
> $~~~~$ The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.  
> Now given any string, you are supposed to tell the number of PAT's contained in the string.

> ## Input Specification:  
> $~~~~$ Each input file contains one test case. For each case, there is only one line giving a string of no more than 10<sup>5</sup>​​ characters c   ontaining only P, A, or T.

> ## Output Specification:  
> $~~~~$ For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

> ## Sample Input:
```
APPAPT
```
> ## Sample Output:
```
2
```
## 题目大意
开始2000
计算字符串中PAT子串的个数，子串定义方式：不同位置的P、A、T（顺序满足），输出结果模1000000007
## 解题思路
字符串长度10^5  
直至遍历完字符串{
找A之前的P的个数p
PT之间的A个数a
下一轮回P之前的T个数t
本次个数c=p * a * t
计算结果取模 res=(res+c) mod MAXN
}
参考题解：  
A左边P的个数*右边T的个数即为当前A可组成的子串个数
记i处左边P的个数（含i处）为leftP[i]  
记i处右边T的个数(含i处)为rightT[i]
i处为A时计算累加。
## 总结
原思路没有理清楚，把PAT三个都找到作为整体，但是过程中出现的非该回合的P需要另外记录，较为复杂。
