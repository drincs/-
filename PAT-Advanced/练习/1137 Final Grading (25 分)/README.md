# 1137 Final Grading (25 分)  
> For a student taking the online course "Data Structures" on China University MOOC (http://www.icourse163.org/), to be qualified for a certificate, he/she must first obtain no less than 200 points from the online programming assignments, and then receive a final grade no less than 60 out of 100. The final grade is calculated by G=(G<sub>mid−term</sub>​ ×40%+G<sub>final</sub> ×60%) if G<sub>mid−term</sub> >G<sub>final</sub>, or G<sub>final</sub> will be taken as the final grade G. Here G<sub>mid−term</sub> and G<sub>final</sub> are the student's scores of the mid-term and the final exams, respectively.  
> The problem is that different exams have different grading sheets. Your job is to write a program to merge all the grading sheets into one.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives three positive integers: P , the number of students having done the online programming assignments; M, the number of students on the mid-term list; and N, the number of students on the final exam list. All the numbers are no more than 10,000.  
> Then three blocks follow. The first block contains P online programming scores G<sub>p</sub>'s; the second one contains M mid-term scores G<sub>mid−term</sub>'s; and the last one contains N final exam scores G<sub>final</sub>'s. Each score occupies a line with the format: StudentID Score, where StudentID is a string of no more than 20 English letters and digits, and Score is a nonnegative integer (the maximum score of the online programming is 900, and that of the mid-term and final exams is 100).  
> ## Output Specification:  
> For each case, print the list of students who are qualified for certificates. Each student occupies a line with the format:  
> StudentID G<sub>p</sub> G<sub>mid−term</sub> G<sub>final</sub> G  
> If some score does not exist, output "−1" instead. The output must be sorted in descending order of their final grades (G must be rounded up to an integer). If there is a tie, output in ascending order of their StudentID's. It is guaranteed that the StudentID's are all distinct, and there is at least one qullified student.  
> ## Sample Input:
```
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
```
> ## Sample Output:
```
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
```
## 完成时间

## 题目大意
```
最终：
在线数据结构课程考核：
1、必须得到不少于200积分(在线编程任务)
2、fg不少于60/100
fg计算：
G=G期中*40%+G期末*60% 如果G期中>G期末
G=G期末
合并成绩单
输入：
P 完成任务的学生数 M 期中列表页学生数 N期末列表页学生数 不超过10000
{
    Gp
}
{
    G期中
}
{
    G期末
}
格式：
学生ID 分数
输出：
考核通过的学生列表
学生ID Gp G期中 G期末 G
分数不存在的输出-1
按G降序输出 按ID升序输出
保证至少1位通过的学生
```
## 解题思路
```
处理三类分数
Gp<200 淘汰
Gf>Gm G=Gf
Gf<=Gm G=46Gmf
G<60 淘汰
```