# 1022 Digital Library (30 分)
> A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains a positive integer N (≤10<sup>4</sup>​​ ) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:
```
Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
```
> It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.  
> After the book information, there is a line containing a positive integer M (≤1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:
```
1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
```
> ## Output Specification:
> For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print Not Found instead.
> ## Sample Input:
```
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
```
> ## Sample Output:
```
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
```
## 完成时间
52min
## 题目大意
```
数字图书馆：一个数字图书馆包含成千上万的书，按照标题 作者 关键字 出版社 出版年份存储。每本书用7位数编号作为id。
给定读者的查询，按编号升序输出。
输入：N （0，10000] 书本总数
N blocks：{
    书籍编号（7位数）
    书本标题（80字符内）
    作者 （80字符内）
    关键字（10字符内 空格分隔）
    出版社（80字符内）
    出版年份（4位数）
}
假设每本书只有1个作者，关键词不超过5个，总关键词数不超过1000个，总出版社不超过1000个。
M 用户查询总数(0,1000]
{
    1:书名
    2:作者
    3:一个关键词
    4:出版社
    5:年份
}其中一个条件
输出:
对每个查询输出对应结果：书籍编号 升序
```
## 解题思路
```
共有5种查询条件，将书籍信息按5种类型录入
map<string,vector<int>>titles
map<string,vector<int>>authors
map<string,vector<int>>keys
map<string,vector<int>>publishers
map<string,vector<int>>years
```
## 总结反思
输出时控制id7位输出时打漏了0，太粗心