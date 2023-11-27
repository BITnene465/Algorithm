#include<bits/stdc++.h>
using namespace std;
string line;
int solve()
{
    int num=0, minn=0, maxx=0;
    for(auto ch: line)
    {
        if(ch=='-')num--;
        else num++;
        minn = min(minn, num);
        maxx = max(maxx, num);
    }
    return maxx - minn;
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>line;
        cout<<solve()<<endl;
    }
    return 0;
}