# 1056 Mice and Rice (25 分)
> Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.  
> First the playing order is randomly decided for N<sub>P</sub>​​ programmers. Then every N<sub>G</sub>​​ programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every N<sub>G</sub>​ winners are then grouped in the next match until a final winner is determined.  
> For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 2 positive integers: N<sub>P</sub> and N<sub>G</sub>(≤1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than N<sub>G</sub>​​ mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains N<sub>P</sub>​​ distinct non-negative numbers W<sub>​i</sub>​​  (i=0,⋯,N<sub>P</sub>​​ −1) where each W<sub>i</sub>​​ is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,⋯,N<sub>​P</sub>​​−1 (assume that the programmers are numbered from 0 to N<sub>​P</sub>​​−1). All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.  
> ## Sample Input:
```
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
```
> ## Sample Output:
```
5 5 5 2 5 5 5 3 1 3 5
```
## 完成时间
22:38 - 23:03
## 题目大意
```
Mice and Rice：一个编程竞赛，每个参赛者必须写一份代码控制老鼠的行动。每只老鼠的目的都是吃尽可能多的大米变成大老鼠。
顺序随机
每Ng个选手一组，组内最大的老鼠获胜进入下一轮
失败的选手排名相同
获胜继续分组比赛直到冠军出现
给出所有老鼠体重及初始顺序，输出排名。
输入：Np Ng //参赛总数 分组最大数，不足自动一组
Np个Wi 体重
参赛顺序
输出：一行输出排序，相同排名会占位。
```
## 解题思路
```
struct{
    int weight;
    int rank;
}
```