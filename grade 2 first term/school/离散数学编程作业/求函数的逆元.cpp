#include<bits/stdc++.h>
using namespace std;
int table1[6][6] = {
                    {1, 2, 3, 4, 5, 6},
                    {2, 1, 4, 3, 6, 5},
                    {3, 5, 1, 6, 2, 4},
                    {4, 6, 2, 5, 1, 3},
                    {5, 3, 6, 1, 4, 2},
                    {6, 4, 5, 2, 3, 1}
};  // 复合函数对应表
int table2[6] = {1, 2, 3, 5, 4, 6};  // 逆函数对应表
char s[1005];
int idx[105], cnt;   // 用于存函数表达式中的下标序列
int main(void)
{
    scanf("%s", s);   // 接收函数表达式的字符串
    for(char* p=s;*p!='\0';++p)
    {
        if(*p=='f'){  // 那么下一个字符一定是数字，直接存入序列中即可
            idx[++cnt] = *(++p) - '0';
        }
    }
    // 下标序列就是所有的有效信息，下面来处理下标序列
    for(int i=1;i<=cnt-1;++i) idx[i+1] = table1[idx[i]-1][idx[i+1]-1];  // 求复合函数，最后的下标储存在idx[cnt]
    printf("f%d\n", table2[idx[cnt]-1]);   // 求逆函数并打印
    return 0;
}