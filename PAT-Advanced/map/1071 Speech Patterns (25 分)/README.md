# 1071 Speech Patterns (25 分)  
> People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.  
> Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?  
> ## Input Specification:  
> Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return \n. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].  
> ## Output Specification:  
> For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.  
> Note that words are case insensitive.  
> ## Sample Input:
```
Can1: "Can a can can a can?  It can!"
```
> ## Sample Output:
```
can 5
```
## 完成时间
23min
## 题目大意
```
演讲模式：人们在同义词中经常有种偏好，有些人叫警察有些人叫条子，分析这样的模式可以帮助理解演讲者的特性。
现在给定一个文本段落，找出最常用的单词。
输入：一行文本，以换行符结束
输出：频率最高的单词 次数 如果存在多个，输出字典序最小的一个，输出时小写。 单词：连续的字母数字 其他符合分隔结束。
例子：Can1: "Can a can can a can?  It can!"
存在单词can1(1) can(5) a(2) it(1)
```
## 解题思路
```
用map存储单词，增加其次数
注意大小写的转换及单词的判定
```