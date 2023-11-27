#include<stdio.h>
int main()
{
    char s[200000]={};
    gets(s);
    char *p = s;
    int cou1,cou2;
    int ans;
    cou1 = 0;
    cou2 = 0;
    while(*p!='J')
    {
        if(*p=='[')
            ++cou1;
        else
            ++cou2;
        p++;
    }
    ans = cou1-cou2;
    p++;
    cou1 = cou2 =0;
    while(*p!='\0')
    {
        if(*p=='[')
            ++cou1;
        else
            ++cou2;
        p++;
    }
    if(cou2-cou1<ans)
        ans = cou2 - cou1;
    printf("%d\n",ans);
    return 0;
}