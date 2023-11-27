#include<bits/stdc++.h>
using namespace std;
class Bintree{
    public:
    struct node{
        char name;
        node *ls,*rs;
        node *fa;
        node(char name,node* ls,node* rs,node* fa):name(name),ls(ls),rs(rs),fa(fa){};
        node()=default;
    };
    map<char,node*> m;
    node* root;
    void Init()
    {
        // ÉèÖÃ * Îª NULL
        m['*']=NULL;
        return;
    }
    void add(char chrt,char chls,char chrs)
    {
        if(!m.count(chrt))
        {
            node* rt = new node(chrt,NULL,NULL,NULL);
            m[chrt] = rt;
        }
        if(!m.count(chls))
        {
            node* ls = new node(chls,NULL,NULL,NULL);
            m[chls] = ls;
        }
        if(!m.count(chrs))
        {
            node* rs = new node(chrs,NULL,NULL,NULL);
            m[chrs] = rs;
        }
        node *rt,*ls,*rs;
        rt = m[chrt];
        ls = m[chls];
        rs = m[chrs];
        rt->ls = ls; 
        rt->rs = rs; 
        if(rs)rs->fa=rt;
        if(ls)ls->fa=rt;
        return;
    }
    void pre_order()
    {
        _pre_order(root);
        cout<<endl;
    }
    void _pre_order(node* rt)
    {
        if(!rt)return;
        cout<<rt->name;
        _pre_order(rt->ls);
        _pre_order(rt->rs);
        return;
    }
};
int n;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    Bintree tr;
    tr.Init();
    for(int i=1;i<=n;++i)
    {
        string line;
        cin>>line;
        tr.add(line[0],line[1],line[2]);
        if(i==1)    tr.root = tr.m[line[0]];
    }
    tr.pre_order();
    return 0;
}