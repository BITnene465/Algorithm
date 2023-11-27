#include <iostream>
#include <cstring>
using namespace std;
int s[500][30] = {0};
int sum0 = -1, sum1 = -1, sum2 = 0;
void input(char *str)
{ // 将输入字符串存到s数组
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')s[sum2][str[i] - 'a'] = 1;
        else if (str[i] == '&')sum2++;
        else if (str[i] == '!')s[sum2][str[++i] - 'a'] = 2;
    }
}
bool equal(int a[], int b[])
{ // 判断两简单析取式是否相同
    for (int i = 0; i < 26; i++)if (a[i] != b[i])return false;
    return true;
}

bool check(int c[])
{ // 检查S1，S2，S3中是否有重复,有重复返回false
    for (int i = 0; i <= sum2; i++)if (equal(s[i], c))return false;
    return true;
}

bool res(int *a, int *b)
{                   // 消解函数，若得到空子句，返回false，否则返回true
    int single = 0; // 不能消解的变项个数
    int couple = 0; // 可消解的变项个数
    for (int i = 0; i < 26; i++)
    { // 遍历26个字母
        if (!a[i] && !b[i])continue;
        else if ((a[i] == 1 && b[i] == 2) || (a[i] == 2 && b[i] == 1))couple++;
        else single++;
    }

    if (couple != 1)return true;
    if (!single)return false;

    int c[30];
    for (int i = 0; i < 26; i++)
    {
        if ((!a[i] && !b[i]) || (a[i] + b[i] == 3)) c[i] = 0;
        else if (a[i] == 1 || b[i] == 1) c[i] = 1;
        else c[i] = 2;
    }
    if (check(c)) {sum2++;for (int i = 0; i < 26; i++)s[sum2][i] = c[i];}
    return true;
}
int main()
{
    char str[1000];
    cin >> str;
    input(str);
    do{
        sum0 = sum1; sum1 = sum2;
        for (int i = 0; i <= sum0; i++)for (int j = sum0 + 1; j <= sum1; j++)if (!res(s[i], s[j])){cout << "NO" << endl;return 0;}
        for (int i = sum0 + 1; i < sum1; i++)for (int j = i + 1; j <= sum1; j++) if (!res(s[i], s[j])){cout << "NO" << endl;return 0;}
    } while (sum2 > sum1);
    cout << "YES" << endl;
    return 0;
}
