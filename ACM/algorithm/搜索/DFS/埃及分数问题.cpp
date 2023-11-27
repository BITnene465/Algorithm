#include<bits/stdc++.h>
using namespace std;
vector<int> ans;  // 用于存储各个单位分数的分母
int gcd(int m, int n)
{
    // 默认m，n均为正整数 //
    int varT;
    if(m<n)
        swap(m,n);
    while(n)
    {
        varT = m%n;
        m = n;
        n = varT;
    }
    return m;
}
int add()
{
    
}
void print_equation(int f1,int f2,vector<int> ans)
{
    printf("%d/%d=",f1,f2);
    for(int i=0;i<ans.size();i++)
    {
        printf("1/%d%c",ans[i],(i==ans.size()-1)?'+':'\n');
    }
    return;
}
int main(void)
{
    int frac1,frac2;
    cin>>frac1>>frac2;
    //
    //
    print_equation(frac1,frac2,ans);
    return 0;
}