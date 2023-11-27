// STL ½â·¨ //
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

map<string,set<int> > m;
set<int>::iterator iter;

int main()
{
    ios::sync_with_stdio(false);
	int n,p;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
	    int l;
	    cin>>l;
	    for(int j=0;j<l;++j)
	    {
	        string s;
	        cin>>s;
	        m[s].insert(i);
	    }
	}
	cin>>p;
	while(p--)
	{
	    string s;
	    cin>>s;
	    if(m.count(s))
	        for(iter=m[s].begin();iter!=m[s].end();++iter)
	            cout<<*iter<<" ";
	    cout<<endl;
	}
	return 0;
}