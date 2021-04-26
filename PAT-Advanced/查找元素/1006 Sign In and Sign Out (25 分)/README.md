# 1006 Sign In and Sign Out (25 分)
> At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

> ## Input Specification:
> Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:
> ID_number Sign_in_time Sign_out_time
> where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.

> ## Output Specification:
> For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

> Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

> ## Sample Input:
> 3
> CS301111 15:30:28 17:00:10
> SC3021234 08:00:00 11:25:25
> CS301133 21:45:00 21:58:40
> ## Sample Output:
> SC3021234 CS301133

## 题目大意：
给定一份出勤表（一天内的数据，含签到、签退时间），找出谁开门，谁关门。<br>
提示:每个人的签到时间早于签退时间，不存在同时签到或签退的情况。

## 解题思路：
M数量级未作说明，因此边输入边记录最大值
<pre><code>
for(int i = 0;i < M; i++){
    //输入
    if(unlocked > in){
        unlocked = in;
        unlocked_id = id;
    }
    if(locked < out){
        locked = out;
        locked_id = id;
    }
}
</code></pre>
## 思考：
可以开结构体比较时间大小，无需换算到秒。