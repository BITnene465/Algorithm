// 希望 min(a,b,c) 最大 //
// 我们规定 a<=b<=c ， 那么合并的时候肯定是合并 （b,c） 相等的两个水晶块（否则没有更大的a） //
// 时间复杂度 O(nlogn) 主要在排序 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,tmp[5];
int id[2],flag=1,now=0;
struct Cube{
    int id;
    int a,b,c;   // a<=b<=c
}cubes[maxn];
bool cmp(Cube cube1,Cube cube2)    // sort函数的比较千万不能用 大于等于 或 小于等于 号，可能导致RE 
{
    if(cube1.c==cube2.c)
    {
        if(cube1.b==cube2.b)return cube1.a>cube2.a;
        else return cube1.b>cube2.b;
    }
    else return cube1.c>cube2.c;
}
int main(void)
{
    // freopen("data.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d %d",tmp,tmp+1,tmp+2);
        sort(tmp,tmp+3);
        cubes[i].a=tmp[0];
        cubes[i].b=tmp[1];
        cubes[i].c=tmp[2];
        cubes[i].id=i;
    }
    sort(cubes+1,cubes+n+1,cmp);
    // for(int i=1;i<=n;++i)cout<<cubes[i].a<<' '<<cubes[i].b<<' '<<cubes[i].c<<endl;
    for(int i=1;i<=n;++i)
    {
        if(cubes[i].a>now){flag=1;id[0]=cubes[i].id;now=cubes[i].a;}   // 单个的情况
        if(cubes[i-1].b==cubes[i].b&&cubes[i-1].c==cubes[i].c)   // i-1 和 i 可以拼凑的情况
        {
            int t = min(cubes[i].b,cubes[i-1].a+cubes[i].a);
            if(t>now){now=t;flag=2;id[0]=cubes[i-1].id;id[1]=cubes[i].id;}
        }
    }
    // print
    if(flag==1){printf("1\n%d\n",id[0]);}
    else {printf("2\n%d %d\n",id[0],id[1]);}
    return 0;
}