# 1080 Graduate Admission (30 分)
> It is said that in 2011, there are about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.

> Each applicant will have to provide two grades: the national entrance exam grade G<sub>E</sub>​​, and the interview grade G​<sub>I</sub>​ . The final grade of an applicant is (G<sub>​E</sub>​​ +G<sub>I</sub>​​ )/2. The admission rules are:

> The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.

> If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade G<sub>E</sub>. If still tied, their ranks must be the same.

> Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.

> If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.

> ## Input Specification:
> Each input file contains one test case.<br>

> Each case starts with a line containing three positive integers: N (≤40,000), the total number of applicants; M (≤100), the total number of graduate schools; and K (≤5), the number of choices an applicant may have.<br>

> In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.<br>

> Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's G<sub>E</sub>​​ and G<sub>I</sub>​​ , respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M−1, and the applicants are numbered from 0 to N−1.

> ## Output Specification:
> For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.

> ## Sample Input:
<pre><code>
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
</code></pre>
> ## Sample Output:
<pre><code>
0 10
3
5 6 7
2 8

1 4
</code></pre>
## 题目大意
自动处理研究生入学程序：申请者有2科成绩：笔试ge及面试gi。<br>
综合得分为（ge+gi)/2<br>
入学规则：按综合得分排序，分数相同按笔试成绩，笔试仍相同则排名相同。<br>
考生有k个志愿，逐个轮。如果所有志愿都无法满足，他就名落孙山了。如果排名相同，申请同个学校，学校会一起接受这些人，尽管名额会超。<br>
<pre><code>
输入：考生总数n 学校数m 志愿数k
1……m 学校招生名额
n行：ge gi k1 ……k
学校编号0 - m-1
考生编号0 - n-1
输出：所有研究生学校的招生结果
每个学校一行：考生编号 升序 无招生输出空行
</code></pre>
## 解题思路
考生按成绩排行处理考生志愿 相同排名的考生需要并行考虑志愿学校。
## 总结
更新学校状态的时候错误的使用了变量k导致多花了20分钟找错误。