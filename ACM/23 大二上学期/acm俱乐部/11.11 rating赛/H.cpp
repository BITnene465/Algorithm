#include<bits/stdc++.h>
using namespace std;
string s[35];
int n, T, flag, cur;
string now;
string ans[5] = {
    "", "dong", "xi", "nan", "bei"
};
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>now;
    if(now==ans[1])flag = 1;
    else if(now==ans[2])flag = 2;
    else if(now==ans[3])flag = 3;
    else if(now==ans[4])flag = 4;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i];
    cin>>T;
    cur = 1;
    while(T--)
    {
        cin>>now;
        for(int i=1;i<=n;++i){
            if(now==s[i])
            {
                if(cur==flag){
                    cout<<"zimo!"<<endl;
                    return 0;
                }
                cout<< ans[cur] <<endl;
                return 0;
            }
        }
        cur = (cur % 4)+1;
    }
    cout<< "gan" <<endl;
    return 0;
}