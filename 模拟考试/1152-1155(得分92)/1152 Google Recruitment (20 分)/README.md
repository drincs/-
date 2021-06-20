# 1152 Google Recruitment (20 分)
> In July 2004, Google posted on a giant billboard along Highway 101 in Silicon Valley (shown in the picture below) for recruitment. The content is super-simple, a URL consisting of the first 10-digit prime found in consecutive digits of the natural constant e. The person who could find this prime number could go to the next step in Google's hiring process by visiting this website.

> ![prime.jpg](./prime.jpg) 

> The natural constant e is a well known transcendental number（超越数）. The first several digits are: e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427427466391932003059921... where the 10 digits in bold are the answer to Google's question.  
> Now you are asked to solve a more general problem: find the first K-digit prime in consecutive digits of any given L-digit number.  
> ## Input Specification:  
> Each input file contains one test case. Each case first gives in a line two positive integers: L (≤ 1,000) and K (< 10), which are the numbers of digits of the given number and the prime to be found, respectively. Then the L-digit number N is given in the next line.  
> ## Output Specification:  
> For each test case, print in a line the first K-digit prime in consecutive digits of N. If such a number does not exist, output 404 instead. Note: the leading zeroes must also be counted as part of the K digits. For example, to find the 4-digit prime in 200236, 0023 is a solution. However the first digit 2 must not be treated as a solution 0002 since the leading zeroes are not in the original number.
> ## Sample Input 1:
```
20 5
23654987725541023819
```
> ## Sample Output 1:
```
49877
```
> ## Sample Input 2:
```
10 3
2468024680
```
> ## Sample Output 2:
```
404
```
## 完成时间：
15:50 - 16:19
## 题目大意：
```
谷歌招聘：2004年6月，谷歌在Silicon Valley张贴了巨大的广告牌招聘。内容超级简单，一个url由常数e的首个10位素数组成。谁能发现这个素数，通过访问网址，可以进入谷歌招聘流程。
找出首k位素数在给定的L位数字中
输入：L K
L位的数N
输出：
输出这样的素数，不存在输出404（L位的数非前导0的0都可作为素数位数部分，k=4,200236 0023符合要求，002360(即2360)输出404。
```
## 解题思路： 
```
1、素数的判断
2、输入数字的前导0处理，L位数较长，需以字符串形式处理
```