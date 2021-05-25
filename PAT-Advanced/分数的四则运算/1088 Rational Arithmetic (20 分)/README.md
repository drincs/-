# 1088 Rational Arithmetic (20 分)
> For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

> ## Input Specification:  
> Each input file contains one test case, which gives in one line the two rational numbers in the format a1/b1 a2/b2. The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.  
> ## Output Specification:  
> For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is number1 operator number2 = result. Notice that all the rational numbers must be in their simplest form k a/b, where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output Inf as the result. It is guaranteed that all the output integers are in the range of long int.  
> ## Sample Input 1:
```
2/3 -4/2
```
> ## Sample Output 1:
```
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
```
> ## Sample Input 2:
```
5/3 0/6
```
> ## Sample Output 2:
```
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
```

## 完成时间
16:43 - 17:19
## 题目大意
两个实数，计算他们的和 差 乘积 商  
实数的输入形式为a/b(假分数)，分子分母范围为long int，负号在分子前面，分母保证为非0数字。  
输出4行：
```
a/b + c/d = sum
a/b - c/d  = diff
a/b * c/d  = product
a/b / c/d  = quotient
```
如果分数为负，需用括号包围，如果商不存在输出Inf
## 解题思路
```
+：a/b + c/d = (a*d+c*b)/bd
-: a/b - c/d = (a*d-c*b)/bd
*: a/b * c/d = ac/bd
/: a/b / c/d = ad/bc
```
## 总结
1次AC，速度待提高。