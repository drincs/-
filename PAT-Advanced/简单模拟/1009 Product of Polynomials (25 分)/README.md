# 1009 Product of Polynomials (25 分)
> This time, you are supposed to find A×B where A and B are two polynomials.
> ## Input Specification:
> Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:<br>
> K N<sub>1</sub> a<sub>N<sub>1</sub></sub> N<sub>2</sub> a<sub>N<sub>2</sub></sub>…N<sub>K</sub> a<sub>N<sub>K</sub></sub><br>
> where K is the number of nonzero terms in the polynomial, N<sub>i</sub> and a<sub>N<sub>​i</sub></sub> (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤N<sub>​K</sub>​​ < ⋯ < N<sub>2</sub>​​ < N<sub>​1</sub>​​ ≤ 1000.

> ## Output Specification:
> For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

> ## Sample Input:
> 2 1 2.4 0 3.2
> 2 2 1.5 1 0.5
> ## Sample Output:
> 3 3 3.6 2 6.0 1 1.6

# 题目大意
计算两个代数式乘积，N<sub>i</sub>为次数，a<sub>N<sub>i</sub><sub>为系数，系数结果保留一位小数。
# 结题思路
逐项相乘，系数追加到各次数项上。
<pre><code>
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            C[A[i].exp + B[j].exp] += A[i].coe * B[j].coe;
        }
    }
</code></pre>
# AC对比题解
最高幂最多达2000，打代码时想偏了，觉得要开1000001，七想八想做了无用功，实际上直接开2001的结果数组就好了，而且输入B的时候可以边输入边处理。