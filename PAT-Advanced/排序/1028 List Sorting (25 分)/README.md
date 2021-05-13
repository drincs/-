# 1028 List Sorting (25 分)
> Excel can sort records according to any column. Now you are supposed to imitate this function.

> ## Input Specification:
> Each input file contains one test case. For each case, the first line contains two integers N (≤10 <sup>5</sup>​​ ) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

> ## Output Specification:
> For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

> ## Sample Input 1:
<pre><code>
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
</code></pre>
> ## Sample Output 1:
<pre><code>
000001 Zoe 60
000007 James 85
000010 Amy 90
</code></pre>

> ## Sample Input 2:
<pre><code>
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
</code></pre>
> ## Sample Output 2:
<pre><code>
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
</code></pre>

> ## Sample Input 3:
<pre><code>
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
</code></pre>

> ## Sample Output 3:
<pre><code>
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
</code></pre>
## 题目大意
模拟excel排序功能，对任意列进行排序。给定n条记录，需排序的列号，1为学号升序，2为姓名升序，3为分数升序，同分同名按学号升序。
## 解题思路
easy~
