# 1002 A+B for Polynomials (25 分)
> This time, you are supposed to find A+B where A and B are two polynomials.

## Input Specification:
> Each input file contains one test case. Each case occupies 2 lines, and > each line contains the information of a polynomial:<br>
> K N​<sub>1</sub>​​ a<sub>​N​<sub>1</sub</sub> ​​N​2​​ a<sub>N<sub>2</sub></sub>…N<sub>K</sub> a<sub>N<sub>K</sub></sub><br>
> where K is the number of nonzero terms in the polynomial, N<sub>i</sub>​​ and a<sub>​N<sub>i</sub></sub> (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that<br>
> 1≤K≤10，0≤N<sub>​K</sub>​​<⋯<N<sub>2</sub><N<sub>​1</sub>​​≤1000.

## Output Specification:
> For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

## Sample Input:
> 2 1 2.4 0 3.2
> 2 2 1.5 1 0.5
## Sample Output:
> 3 2 1.5 1 2.9 0 3.2

## 题目大意:
代数式求和<br>
输入两行分别代表A B<br>
K为非0项的个数<br>
N<sub>i</sub>为次数 a<sub>N<sub>i</sub></sub>为系数<br>
计算A+B 系数保留1位小数<br>
# 解题思路
逐项相加
<pre><code>
for(int i = 0; i < K;i++){
    int n;
    double a;
    scanf("%d %lf",&n,&a);
    C[n] += a;
}
</code></pre>



