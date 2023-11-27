#include<bits/stdc++.h>
using namespace std;
map<char, int> indeg;
map<char, int> outdeg;
char s1[105];
char s2[210];
char mi[105]; int cnt1;
char ma[105]; int cnt2;
int main(void)
{
    gets(s1);
    for(int i=0;i<strlen(s1);++i){
        if(s1[i]==',')continue;
        indeg.insert(make_pair(s1[i], 0));
        outdeg.insert(make_pair(s1[i], 0));
    }
    char u, v;
    gets(s2);
    for(int i=0;s2[i]!='\0';)
    {
        if(s2[i]=='<'){
            u = s2[i+1];
            v = s2[i+3];
            i = i+6;
            indeg[v]++;
            outdeg[u]++;
        }
    }
    for (map<char, int>::iterator it = indeg.begin(); it != indeg.end(); ++it)
        if (it->second == 0)
            mi[++cnt1] = it->first;
    for (map<char, int>::iterator it = outdeg.begin(); it != outdeg.end(); ++it)
        if (it->second == 0)
            ma[++cnt2] = it->first;
    // print
    if(cnt1==0)printf("\n");
    else {
        printf("%c",mi[1]);
        for(int i=2;i<=cnt1;++i)printf(",%c", mi[i]);
        printf("\n");
    }
    if(cnt2==0)printf("\n");
    else{
        printf("%c", ma[1]);
        for (int i = 2; i <= cnt2; ++i) printf(",%c", ma[i]);
        printf("\n");
    }
    return 0;
}