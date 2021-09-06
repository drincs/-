# 1145 Hashing - Average Search Time (25 分)  
> The task of this problem is simple: insert a sequence of distinct positive integers into a hash table first. Then try to find another sequence of integer keys from the table and output the average search time (the number of comparisons made to find whether or not the key is in the table). The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.  
> Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 3 positive numbers: MSize, N, and M, which are the user-defined table size, the number of input numbers, and the number of keys to be found, respectively. All the three numbers are no more than 10<sup>4</sup>. Then N distinct positive integers are given in the next line, followed by M positive integer keys in the next line. All the numbers in a line are separated by a space and are no more than 10<sup>5</sup>.
> ## Output Specification:  
> For each test case, in case it is impossible to insert some number, print in a line X cannot be inserted. where X is the input number. Finally print in a line the average search time for all the M keys, accurate up to 1 decimal place.  
> ## Sample Input:
```
4 5 4
10 6 4 15 11
11 4 15 2
```
## Sample Output:
```
15 cannot be inserted.
2.8
```
## 完成时间
## 题目大意
```
平均查询次数：
一个序列按顺序插入哈希表，再给出一组待查询序列，输出平均查找次数。
散列函数为除数取余法。
平方探查法（正向）解决冲突
注意表长最好为素数，如果不是素数，重定义最小的素数
```
## 解题思路
```
原思路：打素数表
散列函数插值时记录插入时查询次数
查询时根据数值对应的次数相加求和
思路中对查询的处理有漏洞，对于查询未满哈希表中不存在的值，并非查询次数一定是1+TSize。因此，需要与插入时做相同判断。
```
