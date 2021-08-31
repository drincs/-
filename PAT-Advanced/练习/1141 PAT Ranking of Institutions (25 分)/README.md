# 1141 PAT Ranking of Institutions (25 分)  
> After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances. Now you are asked to generate the ranklist.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N (≤10<sup>5</sup>), which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:  
> ID Score School  
> where ID is a string of 6 characters with the first one representing the test level: B stands for the basic level, A the advanced level and T the top level; Score is an integer in [0, 100]; and School is the institution code which is a string of no more than 6 English letters (case insensitive). Note: it is guaranteed that ID is unique for each testee.  
> ## Output Specification:  
> For each case, first print in a line the total number of institutions. Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:  
> Rank School TWS Ns  
> where Rank is the rank (start from 1) of the institution; School is the institution code (all in lower case); ; TWS is the total weighted score which is defined to be the integer part of ScoreB/1.5 + ScoreA + ScoreT*1.5, where ScoreX is the total score of the testees belong to this institution on level X; and Ns is the total number of testees who belong to this institution.  
> The institutions are ranked according to their TWS. If there is a tie, the institutions are supposed to have the same rank, and they shall be printed in ascending order of Ns. If there is still a tie, they shall be printed in alphabetical order of their codes.  
> ## Sample Input:
```
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
```
> ## Sample Output:
```
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
```
## 完成时间

## 题目大意
```
排名:
1代表考试等级 B 乙级 A甲级 T顶级
排名升序输出：
tws 乙级/1.5 + 甲级 + 顶级*1.5
tws降序排序 ns升序排序 
```
## 解题思路
```
```
## 总结
精度问题导致最后一个测试点一直过不去，排序前要先处理成int型tws，否则会影响同tws其他排序结果。