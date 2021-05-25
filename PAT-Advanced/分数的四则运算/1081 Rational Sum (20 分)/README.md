# 1081 Rational Sum (20 分)
> Given N rational numbers in the form numerator/denominator, you are supposed to calculate their sum.

> ## Input Specification:
> Each input file contains one test case. Each case starts with a positive integer N (≤100), followed in the next line N rational numbers a1/b1 a2/b2 ... where all the numerators and denominators are in the range of long int. If there is a negative number, then the sign must appear in front of the numerator.  
> ## Output Specification:  
> For each test case, output the sum in the simplest form integer numerator/denominator where integer is the integer part of the sum, numerator < denominator, and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.  
> ## Sample Input 1:
```
5
2/5 4/15 1/30 -2/60 8/3
```  
> ## Sample Output 1:
```
3 1/3
```
> ## Sample Input 2:
```
2
4/3 2/3
```
> ## Sample Output 2:
```
2
```
> ## Sample Input 3:
```
3
1/3 -1/6 1/8
```
> ## Sample Output 3:
```
7/24
```
## 题目大意
给定N个实数，以分数形式，求和。  
每个输入用例以正整数N开始，下一行为n个分数，分子分母范围为long int，如果存在负数，符号会出现在分子前。
输出简化后的和（带分数）
## 解题思路
分数表示形式：  
{
    int fenzi;
    int fenmu;
}  
求和需要分母通分，求分母的最小公倍数  
```
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
//最大公约数
int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        gcd(b,a%b);
    }
}
```
注意求和结果的约分处理
## 总结
负分子的取余计算存在问题
改用符号表示分数的正负  
最后发现一直没有通过的原因是longlong型数据的输入格式，笔者使用的g++(mingw64)使用%lld输入异常，改用%I64d后提交显示答案错误，pat平台为g++(linux i386)