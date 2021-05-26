# 1059 Prime Factors (25 分)
> Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p<sub>1</sub><sup​>k<sub>1</sub></sup>×p<sub>​2</sub>​<sup>k<sub​>2</sub></sup>​​ ×⋯×p<sub>m</sub><sup>​k<sub>​m</sub></sup>    
> ## Input Specification:  
> Each input file contains one test case which gives a positive integer N in the range of long int.  
> ## Output Specification:  
> Factor N in the format N = p<sub>1</sub><sup​>k<sub>1</sub></sup>×p<sub>​2</sub>​<sup>k<sub​>2</sub></sup>​​ ×⋯×p<sub>m</sub><sup>​k<sub>​m</sub></sup>, where p<sub>​i</sub>​​'s are prime factors of N in increasing order, and the exponent k<sub>​i</sub> is the number of p<sub>​i</sub>​​-- hence when there is only one p<sub>​i</sub>​​, k<sub>​i</sub> is 1 and must NOT be printed out.  
> ## Sample Input:
```
97532468
```  
> ## Sample Output:
```
97532468=2^2*11*17*101*1291
```

## 题目大意
给定正整数N，找出所有质因子，  
按N = p<sub>1</sub><sup​>k<sub>1</sub></sup>×p<sub>​2</sub>​<sup>k<sub​>2</sub></sup>​​ ×⋯×p<sub>m</sub><sup>​k<sub>​m</sub></sup> 格式输出  
输出：次数为1的省略输出次数
## 解题思路
先输出素数表，再判断因子个数