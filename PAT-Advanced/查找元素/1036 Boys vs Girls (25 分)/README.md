# 1036 Boys vs Girls (25 分)
> This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

> ## Input Specification:
> Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

> ## Output Specification:
> For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference grade<sub>​F</sub>​​ − grade<sub>​M</sub>​​ . If one such kind of student is missing, output Absent in the corresponding line, and output NA in the third line instead.

> ## Sample Input 1:
> 3
> Joe M Math990112 89
> Mike M CS991301 100
> Mary F EE990830 95
> ## Sample Output 1:
> Mary EE990830
> Joe Math990112
> 6
> ## Sample Input 2:
> 1
> Jean M AA980920 60
> Sample Output 2:
> Absent
> Jean AA980920
> NA
## 题目大意：
计算女学生中分数最高的与男学生中分数最低的分数差，保证所有分数都是唯一的。<br>
输出 女学生信息 男学生信息 分数差, 缺少某个性别的学生对应输出Absent，分数差输出NA。
## 解题思路：
分数不唯一，故N最大值为101，开102的数组即可。
<pre><code>
//男0 女1 从男到女排，从小到大排
bool cmp(student &a, student &b){
    if(a.gender==b.gender){
        return a.score < b.score;
    }
    return a.gender < b.gender;
}
sort(students,students+N,cmp);
</code></pre>
## 思考
也可以边输入边查找