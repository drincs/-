# 1140 Look-and-say Sequence (20 分)  
> Look-and-say sequence is a sequence of integers as the following:  
> D, D1, D111, D113, D11231, D112213111, ...  
> where D is in [0, 9] except 1. The (n+1)st number is a kind of description of the nth number. For example, the 2nd number means that there is one D in the 1st number, and hence it is D1; the 2nd number consists of one D (corresponding to D1) and one 1 (corresponding to 11), therefore the 3rd number is D111; or since the 4th number is D113, it consists of one D, two 1's, and one 3, so the next number must be D11231. This definition works for D = 1 as well. Now you are supposed to calculate the Nth number in a look-and-say sequence of a given digit D.  
> ## Input Specification:  
> Each input file contains one test case, which gives D (in [0, 9]) and a positive integer N (≤ 40), separated by a space.  
> ## Output Specification:  
> Print in a line the Nth number in a look-and-say sequence of D.  
> ## Sample Input:
```
1 8
```
> ## Sample Output:
```
1123123111
```
## 完成时间
2233开始模拟
## 题目大意
```
1:D                     D:1 
2:D1                    D:1 1:1
3:D1 11                 D:1 1:3
4:D1 13                 D:1 1:2 3:1
5:D1 12 31              D:1 1:2 2:1 3:1 1:1
6:D1 12 21 31 11        D:1 1:2 2:2 1:1 3:1 1:3
7:D1 12 22 11 31 13     D:1 1:2 2:3 1:2 3:1 1:2 3:1   
8:D1 12 23 12 31 12 31

1
11
12
1121
122111
112213
12221131
1123123111
```
## 解题思路
```
对了四十分钟也对不出D112213111到第八步为什么D为1可对为1123123111
直接用1展开可得输出示例
字符串扩展
D开始 D表示的数字1个 记录D1 ……
```