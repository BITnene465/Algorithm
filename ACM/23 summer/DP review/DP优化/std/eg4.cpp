#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define pr pair
#define mkp make_pair
#define fi first
#define se second
const int N=5e5+10;
#define LL long long
int a[N],n,p1[N],p2[N],s[N];
int sq(LL x){
    LL l=0,r=100000,res=-1;
    while(l<=r){
        LL mid=l+r>>1;
        if(mid*mid>=x)res=mid,r=mid-1;else l=mid+1;
    }
    return res;
}
struct T{
    int x,l,r;
}q[N];
int ql,qr;
int trans(int i,int j){
    return a[j]-a[i]+s[i-j];
}
double trans2(int i,int j){
    return a[j]-a[i]+sqrt(i-j);
}
void solve(int* p){
    int i;rep(i,1,n)p[i]=0;
    ql=1;qr=0;
    q[++qr]=(T){1,2,n};
    rep(i,2,n){
        while(ql<=qr && q[ql].r<i)++ql;
        q[ql].l=max(q[ql].l,i);
        int j=q[ql].x;
        p[i]=trans(i,j);
        while(ql<=qr && trans2(q[qr].l,q[qr].x)<=trans2(q[qr].l,i)){
            --qr;q[qr].r=n;
        }
        if(ql>qr){
            q[++qr]=(T){i,i+1,n};
        }else{
            int l=q[qr].l,r=q[qr].r,res=-1;
            while(l<=r) {
                int mid = l + r >> 1;
                if (trans2(mid, i) >= trans2(mid, q[qr].x))res = mid, r = mid - 1; else l = mid + 1;
            }
            if(res>0){
                q[qr].r=res-1;
                q[++qr]=(T){i,res,n};

            }
        }
    }
}
int main(){//freopen("in.txt","r",stdin);//freopen("o1.txt","w",stdout);
    scanf("%d",&n);int i,j;
    rep(i,0,n)s[i]=sq(i);
    rep(i,1,n)scanf("%d",&a[i]);
    solve(p1);
    reverse(a+1,a+1+n);
    solve(p2);
    reverse(p2+1,p2+1+n);
    rep(i,1,n)printf("%d\n",max(0,max(p1[i],p2[i])));
}
