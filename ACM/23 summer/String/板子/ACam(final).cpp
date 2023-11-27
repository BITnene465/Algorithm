#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct ACam
{
    // 字典树中，0为根节点，0也为空节点，记得判断
    int nex[50*maxn+5][26],cnt;  // 只考虑小写的26个字母
    int fail[50*maxn+5];  // fail指针,自动机的精髓
    int indeg[50*maxn+5];   // 记录fail图入度，是此优化的核心
    int ans[50*maxn+5];    // ans标记，可以最后拓扑排序得到答案，此优化的核心
    int vis[50*maxn+5];    // 记录某个字符串被匹配了多少次，这个可以在topu排序中叠加计算
    queue<int> q;
    // 自定义参数
    bool exist[50*maxn+5];  // 某个节点的字符串是否存在
    int ccnt[50*maxn+5];    // 某个节点的某个属性的计数
    bool flag[50*maxn+5];   // 某个节点是否被遍历过或其他什么操作
    int fa[50*maxn+5];  // 可能有些题需要用到父节点
    //
    int getnum(char ch)   // 字符集和整数的对应
    {
        return ch-'a';
    }
    void Insert(char s[],int l)
    {
        int p=0;
        for(int i=0;i<l;++i)
        {
            int c=getnum(s[i]);
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
        }
    }       
    // 多模式匹配
    void Query(char t[],int l)    
    {
        int p=0;
        for(int i=0;i<l;++i){p=nex[p][getnum(t[i])];ans[p]++;}   // 返回值不需要，打上ans标记即可
    }
    void Pre_fail()   // 插入完毕后再预处理fail指针,处理类似于BFS
    {
        fail[0]=0;   // 约定一下，不初始化也可以
        for(int i=0;i<26;++i)
            if(nex[0][i])q.push(nex[0][i]),fail[nex[0][i]]=0;   // 初始化第一层
        while(q.size())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<26;++i)    
            {
                int v=nex[u][i];
                if(!v)
                {
                    nex[u][i]=nex[fail[u]][i];
                    continue;
                }
                fail[v]=nex[fail[u]][i];
                indeg[nex[fail[u]][i]]++;    // 入度加一,与上一个唯一的不同之处
                q.push(v);
            }
        }
    }
    // 拓扑排序算答案       只是找存在性可以用拓扑遍历
    void topu()
    {
        for(int i=1;i<=cnt;++i)
            if(!indeg[i])q.push(i);
        while(q.size())
        {
            int fr=q.front();q.pop();
            vis[fr]=ans[fr];
            int v=fail[fr];
            ans[v]+=ans[fr];
            if(!(--indeg[v]))q.push(v);
        }
    }
};
ACam AC;
char s[maxn];
int n;
int main(void)
{
    // insert ...//
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        AC.Insert(s,strlen(s));
    }
    // pre_fail //
    AC.Pre_fail();
    cin>>s;
    AC.Query(s,strlen(s));
    AC.topu();
    // 每个vis是查询时该节点被访问的次数 //
    for(int i=1;i<=AC.cnt;++i)
    {
        cout<<AC.vis[i]<<endl;
    }
    //
    return 0;
}