# 1077 Kuchiguse (20 分)
> The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

+ Itai nyan~ (It hurts, nyan~)

+ Ninjin wa iyada nyan~ (I hate carrots, nyan~)

> Now given a few lines spoken by the same character, can you find her Kuchiguse?

> ## Input Specification:
> Each input file contains one test case. For each case, the first line is an integer N (2≤N≤100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

> ## Output Specification:
> For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write nai.

> ## Sample Input 1:
> 3
> Itai nyan~
> Ninjin wa iyadanyan~
> uhhh nyan~
> ## Sample Output 1:
> nyan~
> ## Sample Input 2:
> 3
> Itai!
> Ninjinnwaiyada T_T
> T_T
> ## Sample Output 2:
> nai
## 题目大意
日语句尾同词含义不同，找出最长公共后缀
## 解题思路
两两比较。
## 总结
过程中测试点3没过，一开始以为是数据输入长度问题引起的错误，后检查代码,发现将移除暂存的最长公共后缀中不匹配部分的代码放在了循环外。
<pre><code>
    for (int i = 1; i < n; i++)
    {
        int pos = res.size() - 1;
        int size = spokens[i].size();
        for (int j = size - 1; j >= 0 && pos >= 0; j--, pos--)
        {
            if (spokens[i][j] == res[pos])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (pos > 0)
            res.erase(res.begin(), res.begin() + pos + 1);
    }
</code></pre>
pos=1的时候break出来pos为0（pos--）