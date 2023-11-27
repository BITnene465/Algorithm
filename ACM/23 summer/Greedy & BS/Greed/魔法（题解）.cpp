#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
struct node
{
    int tim;
    int b;
}a[100010];    //b大于0的任务
struct ss
{
    int tim;
    int b;
}f[100010];    //b小于等于0的任务
int n,t,z;
int cmp(node &a,node &b)
{
    return a.tim<b.tim;    //由于b大于0，所以先做t小的任务
}
int comp(ss &a,ss &b)
{
    return a.b+a.tim>b.b+b.tim;    //证明如上
}
int main()
{
    scanf("%d",&z);
    for(int i=1;i<=z;i++)
    {
        int s=0,cnt=0,num=0;
        scanf("%d%d",&n,&t);
        for(int j=1;j<=n;j++)
        {
        	int x,y;
        	scanf("%d%d",&x,&y);
        	if(y>0) a[++cnt].tim=x,a[cnt].b=y;
        	else f[++num].tim=x,f[num].b=y;
		}
        sort(a+1,a+cnt+1,cmp);
        sort(f+1,f+num+1,comp);
        for(int j=1;j<=cnt;j++)
        {
            if(t>a[j].tim) t+=a[j].b;
            else{
                s=1;
                break;
            }
		}
        for(int j=1;j<=num;j++)
        {
            if(t>f[j].tim) t+=f[j].b;
            else{
                s=1;
                break;
            }
            if(t<=0){
                s=1;
                break;
            }
        }
        if(s==0) printf("+1s\n");
        else printf("-1s\n");
    }
    return 0;
}