#include<string.h>
#include<stdio.h>
char tab[400][400];
int n,m;
void paint(char ch,int row1,int row2,int col1,int col2)
{
    int i,j;
    for(i=row1;i<=row2;i++)
    {
        for(j=col1;j<=col2;j++)
        {
            tab[i][j] = ch;
        }
    }
    return;
}
int CheckCol(int col)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(tab[i][col]!='.')
            return 0;
    }
    return 1;
}
int CheckRow(int row)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(tab[row][i]!='.')
            return 0;
    }
    return 1;
}
int main()
{
    scanf("%d %d",&n,&m);
    getchar();
    for(int i =0;i<n;i++)
    {
        gets(tab[i]);
    }

    

}