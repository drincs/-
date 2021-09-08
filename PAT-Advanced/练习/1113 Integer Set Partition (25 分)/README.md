# 1113 Integer Set Partition (25 分)  
> Given a set of N (>1) positive integers, you are supposed to partition them into two disjoint sets A<sub>1</sub> and A<sub>2</sub> of n <sub>1</sub> and n<sub>2</sub>  numbers, respectively. Let S<sub>1</sub> and S<sub>2</sub> denote the sums of all the numbers in A<sub>1</sub> and A <sub>2</sub>, respectively. You are supposed to make the partition so that ∣n<sub>1</sub> −n<sub>2</sub> ∣ is minimized first, and then ∣S<sub>1</sub> −S<sub>2</sub> ∣ is maximized.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives an integer N (2≤N≤10<sup>5</sup> ), and then N positive integers follow in the next line, separated by spaces. It is guaranteed that all the integers and their sum are less than 2<sup>31</sup>.
> ## Output Specification:  
> For each case, print in a line two numbers: ∣n<sub>1</sub>  −n <sub>2</sub> ∣ and ∣S<sub>1</sub> −S <sub>2</sub> ∣, separated by exactly one space.  
> ## Sample Input 1:
```
10
23 8 10 99 46 2333 46 1 666 555
```
> ## Sample Output 1:
```
0 3611
```
> ## Sample Input 2:
```
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
```
> ## Sample Output 2:
```
1 9359
```