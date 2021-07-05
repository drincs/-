# 1098 Insertion or Heap Sort (25 分)  
> According to Wikipedia:  
> Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.  
> Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.  
> Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.    
> ## Output Specification:  
> For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.  
> ## Sample Input 1:
```
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
```
> ## Sample Output 1:
```
Insertion Sort
1 2 3 5 7 8 9 4 6 0
```
> ## Sample Input 2:
```
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
```
> ## Sample Output 2:
```
Heap Sort
5 4 3 1 0 2 6 7 8 9
```
## 完成时间
0844 - 
## 题目大意
```
插入排序还是堆排序：
根据维基百科，插入排序逐个插入到已排序的序列中
堆排序：非线性查找去找最大值
给定数字集合的初始序列，一个部分排序结果，告知采用了哪种方法排序
输入：
N 数字个数
N个数字的初始序列
部分排序的序列
假设目标序列升序排序。
输出：
排序类型
下一步排序结果
```
## 解题思路
```
插入排序与堆排序的区别：插入是前部分元素已排序，大顶堆排序结果是后部分先有序
题目保证答案唯一
对已知序列插入排序与堆排序的判断：
当前排到p
1、数字origin[1]到origin[p]之间是否呈有序排序
2、origin[p+1]到origin[n]应与partial相同。
存在这样的p时为插入排序
否则为堆排序
第一次AC测试点2不过原因分析：
第一次的解题思路是单步模拟插入与堆排序步骤，过程数据与partial相同时，判为下一次排序为结果，忽略了输入数组与原数组相同的情况，步骤0时无法决定是插入还是堆，因此这样的比较方式是错误的，需要加以辅助判断
测试点2数据：
4
3 4 2 1
3 4 2 1
输出应为插入排序 2 3 4 1
```