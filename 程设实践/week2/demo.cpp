#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
struct uv{
    int a,b;
}man[maxn];
bool mycmp(uv x, uv y)
{
    return max(y.b,x.a*x.b) < max(x.b,y.a*y.b);
}
int main(void)
{
    // input //
    // ...
    //
    sort(man+1,man+n+1,mycmp);
    // output 
    // ...
    //
}