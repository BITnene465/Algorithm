// 貌似是数据结构题，在树上再维护一个 dist 值，并且动态更新 //
#include<bits/stdc++.h>
using namespace std;
int q,s,n,cnt_s,cnt_n,cur_node;
struct node{
    int fa;
    int dist;
    vector<int> son;
}tr[100005]; 
void initTree()
{
    cnt_n = cnt_s = 1;
    cur_node = 0;
    tr[0].fa = -1;   // 规定根节点的父亲为 -1 节点
    tr[0].dist = 0;
}
void addSon(int x)
{
    ++cur_node;
    tr[x].son.push_back(cur_node);
    tr[cur_node].fa = x;
    tr[cur_node].dist = 0;
    cnt_n++,cnt_s++;
    int cur_fa = x;
    while(cur_fa != -1){
        int minn = INT_MAX;
        for(auto son: tr[cur_fa].son){
            minn = min(minn, tr[son].dist+1);
        }
        if(minn==tr[cur_fa].dist)break;   // 无需更新了
        if(tr[cur_fa].dist <= n && minn > n) cnt_n--;
        if(tr[cur_fa].dist <= s && minn > s) cnt_s--;
        if(tr[cur_fa].dist > n && minn <= n) cnt_n++;
        if(tr[cur_fa].dist > s && minn <= s) cnt_s++;
        tr[cur_fa].dist = minn;
        cur_fa = tr[cur_fa].fa;
    }
}
int main(void)
{
    scanf("%d %d %d",&q,&s,&n);
    initTree();
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            addSon(x);
        }
        else if(op==2){
            // for(int i=0;i<=cur_node;++i){
            //     printf("index: %d dist: %d\n", i, tr[i].dist);
            // }
            printf("%d %d\n",cnt_s,cnt_n);
        }
    }
    return 0;
}