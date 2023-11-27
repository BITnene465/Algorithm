// 我tm重写版 //
#include<bits/stdc++.h>
using namespace std;
string a,b,c;
void del_zero(string &a)   // 删除前导零
{
    int l=(int)a.length();
    int i=0;
    while(i<l&&a[i]=='0')++i;
    if(i==l)a.erase(0,i-1);
    else if(a[i]=='.')a.erase(0,i-1);
    else a.erase(0,i);
}
string add(string &a,string &b)
{
    int l1=(int)a.length();
    int l2=(int)b.length();
    int pos1=(int)a.find('.');if(pos1==string::npos)pos1=l1;
    int pos2=(int)b.find('.');if(pos2==string::npos)pos2=l2;
    string cc;
    if(pos1!=l1||pos2!=l2)    // 存在一个小数的情况
    {
        int pos=max(pos1,pos2);
        int m1=max(l1-pos1-1,0);    // 小数部分的长度
        int m2=max(l2-pos2-1,0);
        int m=max(m1,m2);
        int l=pos+1+m;    // 补全后的长度,1是小数点
        //  cc = aa + bb
        string aa=string(pos-pos1,'0')+a;
        if(pos1==l1)aa+='.';
        aa+=string(m-m1,'0');
        string bb=string(pos-pos2,'0')+b;
        if(pos2==l2)bb+='.';
        bb+=string(m-m2,'0');
        int tmp=0;
        for(int i=0;i<m;++i)
        {
            int x=tmp+aa[l-1-i]-'0'+bb[l-1-i]-'0';
            tmp=x/10;
            cc+=x%10+'0';  
        }
        cc+='.';
        for(int i=0;i<pos;++i)
        {
            int x=tmp+aa[pos-1-i]-'0'+bb[pos-1-i]-'0';
            tmp=x/10;
            cc+=x%10+'0';
        }
        if(tmp)cc+=tmp+'0';
    }
    else   // 两个都是整数
    {
        int l=max(l1,l2);
        //  cc = a + b
        string aa = string(l-l1,'0')+a;
        string bb = string(l-l2,'0')+b;
        int tmp=0;
        for(int i=0;i<l;++i)
        {
            int x=tmp+aa[l-1-i]-'0'+bb[l-1-i]-'0';
            tmp=x/10;
            cc+=x%10+'0';  
        }
        if(tmp)cc+=tmp+'0';
    }
    //
    reverse(cc.begin(),cc.end());
    return cc;
}
void format_print(string &a,string &b,string &c)
{
    int l1=(int)a.length();
    int l2=(int)b.length();
    int l3=(int)c.length();
    int pos1=(int)a.find('.');if(pos1==string::npos)pos1=l1;
    int pos2=(int)b.find('.');if(pos2==string::npos)pos2=l2;
    int pos3=(int)c.find('.');if(pos3==string::npos)pos3=l3;
    // a
    for(int i=1;i<=3+pos3-pos1;++i)cout<<' ';      
    for(int i=0;i<l1;++i)cout<<a[i];
    for(int i=1;i<=l3-l1+pos1-pos3;++i)cout<<' ';  // 补齐尾部空格
    cout<<'\n';
    // +b
    cout<<'+';
    for(int i=1;i<=2+pos3-pos2;++i)cout<<' ';
    for(int i=0;i<l2;++i)cout<<b[i];
    for(int i=1;i<=l3-l2+pos2-pos3;++i)cout<<' ';  // 补齐尾部空格 
    cout<<'\n';
    // =c
    for(int i=1;i<=l3+3;++i)cout<<'-';
    cout<<'\n';
    cout<<"   ";   // 三个空格
    int i;
    for(i=0;i<l3-1&&c[i]=='0'&&c[i+1]!='.';++i)cout<<' ';   // 前导零换成空格
    for(;i<l3;++i)cout<<c[i];
    cout<<'\n';
    return ;
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    // freopen("data.txt","a",stdout);
    cin>>a;cin>>b;
    c=add(a,b);
    format_print(a,b,c);
    return 0;
}