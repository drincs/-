# 1015 Reversible Primes (20 分)
> A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.  
> Now given any two positive integers N (<10<sup>5</sup>​​) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.
> ## Input Specification:  
> The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.  
> ## Output Specification:  
> For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.  
> ## Sample Input:
```
73 10
23 2
23 10
-2
```
> ## Sample Output:
```
Yes
Yes
No
```
## 完成时间
23:30 - 23:46
## 题目大意
RP被定义为在某进制系统里逆序仍为素数的数，例如10进制的73是素数，逆序37也是素数。  
给定正整数N、D,计算N在D进制中是否为RP。  
输入：以负数N结束  
输出：输出是否RP
## 解题思路
10进制的素数比较好理解  
剖其本源，素数为约数除了1即为它本身的数。  
23 2进制 10111 -> 11101 29  
```
逆序数的计算 常规求余的同时叠加计算
bool isPrime(int n)
```