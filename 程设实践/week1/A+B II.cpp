// 体力活 //
// 对齐方面好像没读对题 //
#include<bits/stdc++.h>
using namespace std;
string a,b,c;
string aa,bb;
// 用于删除前导零 //
void del0(string &a)
{
    int i=0;
    int l=(int)a.length();
    while(i<l&&a[i]=='0')++i;
    if(i==l)a.erase(0,i-1);
    else if(a[i]=='.')a.erase(0,i-1);
    else a.erase(0,i);
}
int main(void)
{
    // freopen("data.txt","a",stdout);
    int f1=0,f2=0;
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>a;
    cin>>b;
    del0(a);
    del0(b);
    int pos1=a.find('.');
    if(pos1==string::npos)f1=1;  // 不是小数
    int pos2=b.find('.');
    if(pos2==string::npos)f2=1;   // 不是小数
    if(!f1&&!f2)     // 两个小数
    {
        int l1=a.end()-a.begin()-pos1-1;
        int l2=b.end()-b.begin()-pos2-1;
        int m1=max(pos1,pos2),m2=max(l1,l2);
        aa = string(m1-pos1,'0')+a.substr(0,pos1)+a.substr(pos1+1,l1)+string(m2-l1,'0');
        bb = string(m1-pos2,'0')+b.substr(0,pos2)+b.substr(pos2+1,l2)+string(m2-l2,'0');
        int l=m1+m2;
        // add
        int tmp=0;
        for(int i=0;i<l;++i)
        {
            int x=tmp+aa[l-1-i]-'0'+bb[l-1-i]-'0';
            tmp=x/10;
            c+=x%10+'0';
        }
        int pos3,l3;
        if(tmp)c+=tmp+'0',l++,pos3=m1+1,l3=m2;
        else pos3=m1,l3=m2;
        // reverse
        reverse(c.begin(),c.end());
        // print
        // a
        for(int i=1;i<=3+pos3-pos1;++i)cout<<' ';
        for(int i=0;i<pos1;++i)cout<<a[i];
        cout<<'.';
        for(int i=0;i<l1;++i)cout<<a[pos1+1+i];
        for(int i=1;i<=m2-l1;++i)cout<<' ';
        cout<<endl;
        // + b
        cout<<'+';
        for(int i=1;i<=2+pos3-pos2;++i)cout<<' ';
        for(int i=0;i<pos2;++i)cout<<b[i];
        cout<<'.';
        for(int i=0;i<l2;++i)cout<<b[pos2+1+i];
        for(int i=1;i<=m2-l2;++i)cout<<' ';
        cout<<endl;
        // = c
        for(int i=1;i<=4+l;++i)cout<<'-';
        cout<<endl;
        cout<<"   ";   // 三个空格
        for(int i=0;i<pos3;++i)cout<<c[i];
        cout<<'.';
        for(int i=pos3;i<l;++i)cout<<c[i];
        cout<<endl;
    }
    else if(f1&&f2) // 两个整数
    {
        // add
        int tmp=0;
        int l1=a.length(),l2=b.length();
        int l=max(l1,l2);
        aa=string(l-l1,'0')+a;
        bb=string(l-l2,'0')+b;
        for(int i=0;i<l;++i)
        {
            int x=tmp+aa[l-1-i]-'0'+bb[l-1-i]-'0';
            tmp=x/10;
            c+=x%10+'0';
        }
        int l3=l;
        if(tmp)c+=tmp+'0',l3++;
        // reverse
        reverse(c.begin(),c.end());
        // print
        // a
        for(int i=1;i<=3+l3-l1;++i)cout<<' ';
        for(int i=0;i<l1;++i)cout<<a[i];
        cout<<endl;
        // + b
        cout<<'+';
        for(int i=1;i<=2+l3-l2;++i)cout<<' ';
        for(int i=0;i<l2;++i)cout<<b[i];
        cout<<endl;
        // = c
        for(int i=1;i<=3+l3;++i)cout<<'-';
        cout<<endl;
        cout<<"   ";   // 三个空格
        for(int i=0;i<l3;++i)cout<<c[i];
        cout<<endl;
    }
    else if(f2)    // a为小数，b为整数
    {
        int t1=a.end()-a.begin()-pos1-1;
        int l1=pos1,l2=b.length();
        int l=max(l1,l2);
        aa = string(l-l1,'0')+a.substr(0,l1);
        bb = string(l-l2,'0')+b.substr(0,l2);
        // add
        int tmp=0;
        for(int i=0;i<l;++i)
        {
            int x=tmp+aa[l-1-i]-'0'+bb[l-1-i]-'0';
            tmp=x/10;
            c+=x%10+'0';
        }
        if(tmp)c+=tmp+'0',l++;
        // reverse
        reverse(c.begin(),c.end());
        // print
        // a
        for(int i=1;i<=3+l-pos1;++i)cout<<' ';
        for(int i=0;i<pos1;++i)cout<<a[i];
        cout<<'.';
        for(int i=0;i<t1;++i)cout<<a[pos1+1+i];
        cout<<endl;
        // + b
        cout<<'+';
        for(int i=1;i<=2+l-l2;++i)cout<<' ';
        for(int i=0;i<l2;++i)cout<<b[i];
        for(int i=1;i<=t1+1;++i)cout<<' ';
        cout<<endl;
        // = c
        for(int i=1;i<=4+l+t1;++i)cout<<'-';
        cout<<endl;
        cout<<"   ";   // 三个空格
        for(int i=0;i<l;++i)cout<<c[i];
        cout<<'.';
        for(int i=1;i<=t1;++i)cout<<a[pos1+i];
        cout<<endl;
    }
    else           // a为整数，b为小数
    {
        int t2=b.end()-b.begin()-pos2-1;
        int l1=a.length(),l2=pos2;
        int l=max(l1,l2);
        aa = string(l-l1,'0')+a.substr(0,l1);
        bb = string(l-l2,'0')+b.substr(0,l2);
        // add
        int tmp=0;
        for(int i=0;i<l;++i)
        {
            int x=tmp+aa[l-1-i]-'0'+bb[l-1-i]-'0';
            tmp=x/10;
            c+=x%10+'0';
        }
        if(tmp)c+=tmp+'0',l++;
        // reverse
        reverse(c.begin(),c.end());
        // print
        // a
        for(int i=1;i<=3+l-l1;++i)cout<<' ';
        for(int i=0;i<l1;++i)cout<<a[i];
        for(int i=1;i<=t2+1;++i)cout<<' ';
        cout<<endl;
        // + b
        cout<<'+';
        for(int i=1;i<=2+l-l2;++i)cout<<' ';
        for(int i=0;i<l2;++i)cout<<b[i];
        cout<<'.';
        for(int i=1;i<=t2;++i)cout<<b[pos2+i];
        cout<<endl;
        // = c
        for(int i=1;i<=4+l+t2;++i)cout<<'-';
        cout<<endl;
        cout<<"   ";   // 三个空格
        for(int i=0;i<l;++i)cout<<c[i];
        cout<<'.';
        for(int i=1;i<=t2;++i)cout<<b[pos2+i];
        cout<<endl;
    }
    return 0;
}