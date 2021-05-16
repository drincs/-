# 1037 Magic Coupon (25 分)
> The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!<br>

> For example, given a set of coupons { 1 2 4 −1 }, and a set of product values { 7 6 −2 −3 } (in Mars dollars M$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.<br>

> Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.<br>

> ## Input Specification:
> Each input file contains one test case. For each case, the first line contains the number of coupons N<sub>C</sub>​​, followed by a line with N<sub>C</sub>coupon integers. Then the next line contains the number of products N<sub>​P</sub>​​, followed by a line with N<sub>P</sub> product values. Here 1≤N<sub>C</sub>,N<sub>​P</sub> ≤10<sup>5</sup>, and it is guaranteed that all the numbers will not exceed 2<sup>30</sup>.

> ## Output Specification:
> For each test case, simply print in a line the maximum amount of money you can get back.

> ## Sample Input:
<pre>
4
1 2 4 -1
4
7 6 -2 -3
</pre>
> ## Sample Output:
<pre>
43
</pre>

## 题目大意
<pre>
计算两个序列最大的乘积和，每个序列中的每一个数只能使用一次
</pre>
## 解题思路
<pre>
两个序列长度上限100000,乘积之和上限2的30次方
数字排序
正与正 负与负
</pre>