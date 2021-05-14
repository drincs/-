# 1083 List Grades (25 分)
> Given a list of N student records with name, ID and grade. You are supposed to sort the records with respect to the grade in non-increasing order, and output those student records of which the grades are in a given interval.

> ## Input Specification:
> Each input file contains one test case. Each case is given in the following format:
<pre><code>
N
name[1] ID[1] grade[1]
name[2] ID[2] grade[2]
... ...
name[N] ID[N] grade[N]
grade1 grade2
</code></pre>
> where name[i] and ID[i] are strings of no more than 10 characters with no space, grade[i] is an integer in [0, 100], grade1 and grade2 are the boundaries of the grade's interval. It is guaranteed that all the grades are distinct.

> ## Output Specification:
> For each test case you should output the student records of which the grades are in the given interval [grade1, grade2] and are in non-increasing order. Each student record occupies a line with the student's name and ID, separated by one space. If there is no student's grade in that interval, output NONE instead.

> ## Sample Input 1:
<pre><code>
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
</code></pre>

> ## Sample Output 1:
<pre><code>
Mike CS991301
Mary EE990830
Joe Math990112
</code></pre>

> ## Sample Input 2:
<pre><code>
2
Jean AA980920 60
Ann CS01 80
90 95
</code></pre>
> ## Sample Output 2:
<pre><code>
NONE
</code></pre>

## 题目大意
给定n个学生记录（姓名 学号 分数），按分数降序排序，输出指定范围的学生记录。不存在输出NONE。
## 解题思路
先排序，再输出。
## 总结
简单题~