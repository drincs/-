# 1091 Acute Stroke (30 分)
> One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M×N matrix, and the maximum resolution is 1286 by 128); L (≤60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).  
> Then L slices are given. Each slice is represented by an M×N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are connected and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.
> ![figstroke.jpg](./figstroke.jpg)
> ## Output Specification:
> For each case, output in a line the total volume of the stroke core.  
> ## Sample Input:
```
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
```
> ## Sample Output:
```
26
```
## 完成时间
2313 - 2353
## 题目大意
```
急性脑卒中：计算脑死亡的体量
输入：M N L T //M N slice的尺寸 L大脑slice数量 T有效数字
L个：M * N的0-1矩阵 0代表正常 1代表卒  
输出：脑死亡的体量

```
## 解题思路
```
立体空间上有公共边的属于一块，块内1大于等于T可计入脑死亡体量，否则不计入
逐层bfs
```