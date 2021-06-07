## 1063 Set Similarity (25 分)
> Given two sets of integers, the similarity of the sets is defined to be N<sub>c</sub>​​ /N<sub>​t</sub>​​ ×100%, where N<sub>c</sub>​​ is the number of distinct common numbers shared by the two sets, and N<sub>t</sub>​​ is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.  
> ## Input Specification:  
> Each input file contains one test case. Each case first gives a positive integer N (≤50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (≤10<sub>4</sub>​) and followed by M integers in the range [0,10<sub>9</sub>​​ ]. After the input of sets, a positive integer K (≤2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.
> ## Sample Input:
```
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
```
> ## Sample Output:
```
50.0%
33.3%
```
## 完成时间
29min
## 题目大意
```
集合相似度：给定两个整数集合，相似度被定义为Nc/Nt，Nc为公共数字类数，Nt为总类数。
输入：
正整数N 集合总数
N行：M 集合内数字个数 M1……Mm
正整数K 查询数
K行：集合编号一对（从1开始）
输出：
输出相似度，保留一位。
```
## 解题思路
```
利用set特性对数字去重，处理时以其中一个集合为基数，另一集合逐一判断是否包含在基数集合中，存在则nc+1，否则总数+1.
```