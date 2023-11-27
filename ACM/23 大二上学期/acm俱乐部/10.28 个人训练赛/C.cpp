#include<bits/stdc++.h>
using namespace std;
int main(void){
    int T;
    scanf("%d",&T);
    while(T--){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int x,y,r;
        scanf("%d %d %d",&x,&y,&r);
        int xmi,xma,ymi,yma;
        xmi = x-r;
        xma = x+r;
        ymi = y-r;
        yma = y+r;
        if(x1<=xmi && xma<=x2 && y1<=ymi && yma<=y2)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}