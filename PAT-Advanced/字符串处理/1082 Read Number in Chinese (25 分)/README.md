# 1082 Read Number in Chinese (25 分)
> Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output Fu first if it is negative. For example, -123456789 is read as Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu. Note: zero (ling) must be handled correctly according to the Chinese tradition. For example, 100800 is yi Shi Wan ling ba Bai.

> ## Input Specification:
> Each input file contains one test case, which gives an integer with no more than 9 digits.

> ## Output Specification:
> For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

> ## Sample Input 1:
> -123456789
> ## Sample Output 1:
> Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
> ## Sample Input 2:
> 100800
> ## Sample Output 2:
> yi Shi Wan ling ba Bai
## 题目大意
按中文方式读数，0-9数字首字母小写，十百千万亿为大写，数字最长9位（不含正负号）
## 解题思路
正负判断 负数 输出Fu<br>
num[9]={0} 从左到右 存储高位到低位数字<br>
xxxxxxxxxx<br>
^        ^  <br>   
high     low<br>
左移low指针，使得high指针与low指针属于同个位级（个 万 亿）<br>
自高位向低位处理
## 总结
需要注意对0的处理。
