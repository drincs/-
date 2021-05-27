# 1024 Palindromic Number (25 分)
> A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.  
> Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.  
> Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.  
> ## Input Specification:  
> Each input file contains one test case. Each case consists of two positive numbers N and K, where N (≤10<sup>10</sup>​​ ) is the initial numer and K (≤100) is the maximum number of steps. The numbers are separated by a space.
> ## Output Specification:  
> For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.  
> ## Sample Input 1:
```
67 3
```
> ## Sample Output 1:
```
484
2
```
> ## Sample Input 2:
```
69 3
```
> ## Sample Output 2:
```
1353
3
```
## 完成时间
23:53 - 00:28
## 题目大意
回文数字，所有个位数都是回文数。非回文数可以系列操作而转变，例67：  
+  1、76 + 67 =143
+  2、143+341=484
给定任意N及转变最大次数，找出回文数字及步数，找不到输出k次结果及k。
## 解题思路
```
N的范围为10^10,K<=100.数字上限为10^12
判断回文
for(int i=0;i<=len/2;i++){
    if(num[i]!=num[len-1-i]){
        break;
    }
}
```
## 总结
测试点2、3，个位数的回文处理