# 1054 The Dominant Color (20 分)
> Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800×600), you are supposed to point out the strictly dominant color.  
> ## Input Specification:  
> Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (≤800) and N (≤600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0,2<sup>24</sup>​​ ). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.  
> ## Output Specification:  
> For each test case, simply print the dominant color in a line.  
> ## Sample Input:
```
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
```
> ## Sample Output:
```
24
```
## 完成时间
12min
## 题目大意
```
电脑内存里，像素的颜色被定义为若干个24位信息。现给定一张M*N的图片，指出strictly dominant color（strictly dominant color占总面积一半以上）
输入：M N
N行 M个颜色
输出：保证结果存在
```
## 解题思路
```
判断过半的颜色数值：用map<int,int>存储颜色及次数
```
