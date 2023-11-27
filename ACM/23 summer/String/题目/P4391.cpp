// kmp+ ¡Á?¡¦????????? //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int pi[maxn],n;
char s[maxn];
int main(void)
{
    scanf("%d",&n);
    getchar();
    scanf("%s",s);
    for(int i=1;i<n;++i)
    {
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
    cout<<n-pi[n-1]<<endl;
    return 0;
}