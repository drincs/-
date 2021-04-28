# 1031 Hello World for U (20 分)
> Given any string of N (≥5) characters, you are asked to form the characters into the shape of U. For example, helloworld can be printed as:
> h  d
> e  l
> l  r
> lowo
> That is, the characters must be printed in the original order, starting top-down from the left vertical line with n<sub>1</sub> characters, then left to right along the bottom line with n<sub>​2</sub>​​ characters, and finally bottom-up along the vertical line with n<sub>3</sub>​​ characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n<sub>1</sub>​​ = n<sub>​3</sub>​​ = max { k | k≤n<sub>​2</sub>​​  for all 3≤n<sub>2</sub>​​ ≤N } with n<sub>1</sub>​​ +n<sub>​2</sub>​​ +n<sub>​3</sub>​​ −2=N.

> ## Input Specification:
> Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

> ## Output Specification:
> For each test case, print the input string in the shape of U as specified in the description.

> ## Sample Input:
> helloworld!
> Sample Output:
> h   !
> e   d
> l   l
> lowor

## 题目大意：
给定长度N(>=5)的字符串，按U字型输出。<br>
n<sub>1</sub> + n<sub>2</sub> +n<sub>3</sub> - 2 = N <br>
n<sub>1</sub>​​ = n<sub>​3</sub>​​ = max { k | k≤n<sub>​2</sub>​​  for all 3≤n<sub>2</sub>​​ ≤N }
## 解题思路：
(N+2)%3==0 n2=(N+2)/3<br>
(N+2)%3==1 n2=(N+2)/3+1<br>
(N+2)%3==2 n2=(N+2)/3+2<br>
<pre><code>
for(int i = 0; i < n1 - 1;i++){
    printf("%c",str[i]);
    for(int j = 1;j < n2 - 1;j++){
        printf(" ");
    }
    printf("%c\n",str[N - 1 - i]);
}
for(int i = 0;i < n2;i++){
    printf("%c",str[n1 -1 + i]);
}
printf("\n");
</code></pre>
## 思考：
实际编码时发现n2其实可以通过n1计算。亦可用二维数组存储输出字符。