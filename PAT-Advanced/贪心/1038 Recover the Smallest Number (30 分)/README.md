# 1038 Recover the Smallest Number (30 分)
> Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given { 32, 321, 3214, 0229, 87 }, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.

> ## Input Specification:
> Each input file contains one test case. Each case gives a positive integer N (≤10<sup>4</sup>​​) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

> ## Output Specification:
> For each test case, print the smallest number in one line. Notice that the first digit must not be zero.

> ## Sample Input:
<pre>
5 32 321 3214 0229 87
</pre>
> ## Sample Output:
<pre>
22932132143287
</pre>

## 题目大意
<pre>
给定一个数字片段集合，还原最小的数。
每个片段不超过8位
输出最小的数 首位非0
</pre>
## 解题思路
<pre>
排序：return A + B< B + A;
</pre>