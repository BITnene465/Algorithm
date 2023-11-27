#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
using ll = long long;

char s[MAXN];
char trans[1000];
int main(){
    ll n,m;
    cin >> n >> m;
    scanf("%s",s);
    for(int i = 1; i <= 256; i++){
        trans[i] = '\0'+i; 
    }
    char a,b;
    for(ll i = 0; i < m; i++){
        
        cin >> a;
        cin >> b;
        for(int j = 1; j <= 256; j++){
            if(trans[j] == a)trans[j] = b;
            else if(trans[j] == b)trans[j] = a;
        }
    }
    for(ll i = 0; i < n; i++){
        putchar(trans[(int)s[i]]);
    }
    puts("");
    return 0;
}