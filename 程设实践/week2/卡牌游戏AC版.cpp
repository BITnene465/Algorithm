#include <cstdio>
int map[200005], stack[200005];
// map是第i张牌的索引，即实际位置,map==0代表手牌
// stack记录牌堆
int main(void)
{
    int n, temp, ans = 0, max = 0;
    bool flag = true, bol = true;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) // 标记手牌，0就是手牌，其他还没有初始化
    {
        scanf("%d", &temp);
        map[temp] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        // 索引到数字 （把实际数字放进牌堆）
        stack[i] = temp;
        // 数字到索引  (把堆里的实际位置写入map）
        map[temp] = i;
    }
    // 判断是否是从头到尾的连续序列 temp此时是尾部的数字,即将成为理想的连续串
    // n-1是指向倒数第二位stack
    for (int i = n - 1; temp != 1; i--)
    {
        if (stack[i] != --temp)
        {
            flag = false;
            break;
        }
    }
    if (flag) // 成功走下来,那么temp==stack[i]&&temp==1
    // 代表这是个连续的串，从1到stack[n]，但是1前面的东西不确定
    {
        for (int j = stack[n] + 1; j <= n; j++)
        {
            // map[j]肯定是在我们的stack==1的位置的前面
            // map[j]代表了要上手的操作数，j-（stack[n]+1)代表了操作空间，即几次操作后需要这张牌
            // 比如561234，map[5]==1，所以要拿到5要一步，而5-(4+1)==0，留给你的操作数为0,所以不可能一轮搞定
            // map[j] == 0 ||没有必要,大概是为了可读性,其实map[j]为0的时候，就已经满足后面条件了
            // 因为不管留给你多少操作数，我已经不需要操作了
            if (map[j] <= j - (stack[n] + 1)) // 操作数满足操作空间的，就看下一个
            {
                continue;
            }
            else
            {
                bol = false;
                break;
            }
        }
        if (bol) // 代表剩下那n-stack[n]个数都满足操作空间限制，那就一轮过
        {
            ans += n - stack[n];
        }
        else // 不能一轮走完，那就再多走一轮 1+n  步，变成001234，再一轮过
        {    // 为什么走一轮会是n+1呢？因为还得在手上倒一下,实际上我们的环长是n+1
            ans += 1 + n + n - stack[n];
        }
    }
    else                             // 没有完整走下来此时，i和stack[i]是不相等的,至此断开连续
    {                                // 如216345但是从n到i-1是连续的，但是连续序列首部不是1
        for (int i = 1; i <= n; i++) // 一般来说这个max会对应到1上，或者说在走到max步的时候，1已经在手了
        {
            temp = (map[i] - i + 1) > 0 ? (map[i] - i + 1) : 0;
            if (temp > max)
            {
                max = temp;
            }
        }
        ans += n; // 所有操作数都满足操作空间限制，开始放1，顺次放完
        ans += max;
    }
    printf("%d\n", ans);
    return 0;
}