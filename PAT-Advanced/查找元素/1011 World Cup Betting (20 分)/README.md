# 1011 World Cup Betting (20 分)
> With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

> Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

> For example, 3 games' odds are given as the following:

>  W    T    L
> 1.1  2.5  1.7
> 1.2  3.1  1.6
> 4.1  1.2  1.1
> To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1×3.1×2.5×65%−1)×2=39.31 yuans (accurate up to 2 decimal places).

> ## Input Specification:
> Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

> ## Output Specification:
> For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

> ## Sample Input:
> 1.1 2.5 1.7
> 1.2 3.1 1.6
> 4.1 1.2 1.1
> ## Sample Output:
> T T W 39.31
# 题目大意：
给出三场比赛 获胜 平局 落败 三种结果的赔率，要求计算最大利益下三局下注情况及最后利润<br>
利润 =（赔率1 * 赔率2 * 赔率3 * 0.65 - 1)*2,保留2位小数
# 解题思路：
<pre><code>
    double odds=0.65;
    char bet[3]={'W','T','L'};
    int best[3];
    for(int i = 0; i < 3; i++){
        double w,t,l;
        scanf("%lf%lf%lf",&w,&t,&l);
        if(w>=t&&w>=l){
            best[i]=0;
            odds*=w;
        }else if(t>=w&&t>=l){
            best[i]=1;
            odds*=t;
        }else{
            best[i]=2;
            odds*=l;
        }
    }
    double res=(odds-1)*2;
</code></pre>
# 思考
已经采用字符数组表示比赛结果，同样地，可以下标j(012)表示比赛结果赔率的输入，在每轮输入的时候判断目前最大值。
