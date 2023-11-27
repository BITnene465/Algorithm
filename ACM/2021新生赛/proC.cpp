#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    char s1[100001]={};
    char s2[100001]={};
    gets(s1);
    gets(s2);
    int i = 0;
    int step = 0;
    int deta = abs(m-n);
    int minu = m>n?n:m;
    while(i<minu)
    {
        if(s1[i]!=s2[i])
            step++;
        i++;
    }
    step += deta;
    printf("%d\n",step);
    return 0;
}