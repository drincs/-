# 1084 Broken Keyboard (20 分)
> On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

> Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

> ## Input Specification:
> Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or _ (representing the space). It is guaranteed that both strings are non-empty.

> ## Output Specification:
> For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

> ## Sample Input:
<pre><code>
7_This_is_a_test
_hs_s_a_es
</code></pre>
> ## Sample Output:
<pre><code>
7TI
</code></pre>
## 题目大意
旧键盘上有些键坏了，当你打字时这些字符不会出现在屏幕上。给你需要输入的字符串，和实际输出的，列出哪些键坏了。
<pre><code>
输入：
原始字符串
显示字符串
输出：
按被检测到的顺序输出
</code></pre>

## 解题思路
两个字符串比较，同时需要记录已输出的破键。

## 总结
比较的时候采取了双指针移动，遗漏了原始字符串没遍历完输出字符串已遍历完的情况（测试点4）