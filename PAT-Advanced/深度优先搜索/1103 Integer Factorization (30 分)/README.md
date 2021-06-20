# 1103 Integer Factorization (30 分)
> The K−P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K−P factorization of N for any positive integers N, K and P.  
> ## Input Specification:
> Each input file contains one test case which gives in a line the three positive integers N (≤400), K (≤N) and P (1 < P ≤ 7). The numbers in a line are separated by a space.
> ## Output Specification:  
> For each case, if the solution exists, output in the format:
```
N = n[1]^P + ... n[K]^P
```
> where n[i] (i = 1, ..., K) is the i-th factor. All the factors must be printed in non-increasing order.  
> Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 12<sup>2</sup>+4<sup>2</sup>+2<sup>2</sup>+2<sup>2</sup>+1<sup>2</sup>, or 11<sup>2</sup>+6<sup>2</sup>+2<sup>2</sup>+2<sup>2</sup>+2<sup>2</sup>, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a<sub>1</sub>​​,a<sub>​2</sub>​​,⋯,a<sub>K</sub>​​} is said to be larger than { b<sub>1</sub>​​,b<sub>​2</sub>​​,⋯,b<sub>​K</sub>​​} if there exists 1≤L≤K such that a<sub>i</sub>​​=b<sub>​i</sub>​​ for i < L and a<sub>L</sub>​​ > b<sub>​L</sub>​​.  
> If there is no solution, simple output Impossible.
> ## Sample Input 1:
```
169 5 2
```
> ## Sample Output 1:
```
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
```
> ## Sample Input 2:
```
169 167 3
```
> ## Sample Output 2:
```
Impossible
```
> ## 完成时间
1051 - 1152 得分27
> ## 题目大意
```
正整数N的The K−P factorization写作N=k个正整数的p次项之和，即
N = n[1]^P + ... n[K]^P
输入：正整数N K P
输出：
N = n[1]^P + ... n[K]^P //大到小 结果不唯一时输出K个元素之和最大的，如果和仍相等，输出元素内数大的  
```
> ## 解题思路
```
怎么求满足条件的等式 e=N开p次方
递归条件i<=e count<K
```
## 总结反思
运行超时的优化需增强：参考题解，修改为先选择大数再选择小数，避免对结果数据进行排序，还有就是临时选择数据的存储，定义为全局变量可以通过测试点5的运行超时。