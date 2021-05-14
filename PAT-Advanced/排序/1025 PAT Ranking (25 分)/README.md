# 1025 PAT Ranking (25 分)
> Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

> ## Input Specification:
> Each input file contains one test case. For each case, the first line contains a positive number N (≤100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (≤300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

> ## Output Specification:
> For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
> registration_number final_rank location_number local_rank
> The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

> ## Sample Input:
<pre><code>
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
</code></pre>
> ## Sample Output:
<pre><code>
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
</code></pre>
## 题目大意
考点排名合并：给定n个考点 每个考点有k个考生（考号13位 得分）<br>
输出：考生考号 综合排名 考点号 考点排名<br>
得分相同名次相同，相同名次占排名位，按综合排名输出。
## 解题思路
所有输入完之后排序两次：1考点排名 2综合排名
## 总结
strcpy_s()函数会编译报错。<br>
参考题解的思路为：输入时分考场排序，综合排序后输出时处理名次。<br>
参考题解的时间复杂度为：分考场排序 k<sub>i</sub>log(k<sub>i</sub>)(i ∈ [1,n] ) 综合排序nlog(n) 输出n<br>
我的：输入n 2*nlog(n) 输出n<br>
不知道这样比对不对

