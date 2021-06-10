# 1100 Mars Numbers (20 分)
> People on Mars count their numbers with base 13:  
> Zero on Earth is called "tret" on Mars.  
> The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars,respectively.  
> For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.  
> For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains a positive integer N (<100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.  
> ## Output Specification:  
> For each number, print in a line the corresponding number in the other language.  
> ## Sample Input:
```
4
29
5
elo nov
tam
```
> ## Sample Output:
```
hel mar
may
115
13
```
## 题目大意
```
火星数字：火星人以13进制数数，0叫tret，1到12为月份简称(jan,feb,mar, apr, may, jun, jly, aug, sep, oct, nov, dec).
高位：1-12 tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou
例如：地球29在火星叫做hel mar（29/13 29%13），火星elo nov为8*13+11=115
要求：翻译两个星球的数字
输入：N（正整数）
N行：数字[0,169) 可能是地球数字或者火星数字
输出：对应的另外一个星球语言
```
## 解题思路
```
数字范围有限，使用map也许会更好
```
## 总结
13的表达方式为tam 不加低位tret