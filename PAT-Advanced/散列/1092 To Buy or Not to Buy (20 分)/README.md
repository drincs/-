# 1092 To Buy or Not to Buy (20 分)
> Eva would like to make a string of beads with her favorite colors so she went to a small shop to buy some beads. There were many colorful strings of beads. However the owner of the shop would only sell the strings in whole pieces. Hence Eva must check whether a string in the shop contains all the beads she needs. She now comes to you for help: if the answer is Yes, please tell her the number of extra beads she has to buy; or if the answer is No, please tell her the number of beads missing from the string.

> For the sake of simplicity, let's use the characters in the ranges [0-9], [a-z], and [A-Z] to represent the colors. For example, the 3rd string in Figure 1 is the one that Eva would like to make. Then the 1st string is okay since it contains all the necessary beads with 8 extra ones; yet the 2nd one is not since there is no black bead and one less red bead.
<pre><code>
ppRYYGrrYB225
YrR8RrY
</code></pre>
> ## Input Specification:
> Each input file contains one test case. Each case gives in two lines the strings of no more than 1000 beads which belong to the shop owner and Eva, respectively.

> ## Output Specification:
> For each test case, print your answer in one line. If the answer is Yes, then also output the number of extra beads Eva has to buy; or if the answer is No, then also output the number of beads missing from the string. There must be exactly 1 space between the answer and the number.

> ## Sample Input 1:
<pre><code>
ppRYYGrrYBR2258
YrR8RrY
</code></pre>
> ## Sample Output 1:
<pre><code>
Yes 8
</code></pre>
> ## Sample Input 2:
<pre><code>
ppRYYGrrYB225
YrR8RrY
</code></pre>
> ## Sample Output 2:
<pre><code>
No 2
</code></pre>
## 题目大意
eva想买beads做链子，店家只卖一整串，检查是否都包含，是的话需要额外买无用的多少，否的话告诉她缺的数量。
## 解题思路
字符串比较 int breads[256]={0} 记录需要的 减去店家的