#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    char a[4000], b[4000], c[4000];
    int x, y, z, flaga = 0, flagb = 0, ap, bp;
 
    memset(a, '\0', sizeof(a));
    memset(b, '\0', sizeof(b));
    memset(c, '\0', sizeof(c));
    scanf("%s", a);
    scanf("%s", b);
    for (int i = 0; i < 1000; i++)//判断整数还是小数，整数flag为0
    {
        if(a[i] == '.')//flaga flagb为0的话就是整数
        {
            flaga = 1;
            ap = i;
        }
        if(b[i] == '.')
        {
            flagb = 1;
            bp = i;
        }
 
    }    
 
    if(flaga == 0)//将整数弄成小数
    {
        int i = 0;
        while(i++ <= 1000)
        {
            if(a[i] == '\0')
            {
                a[i] = '.';
                ap = i;
                break;
            }
        }
    }
 
    
    if(flagb == 0)//将整数弄成小数
    {
        int i = 0;
        while(i++ <= 1000)
        {
            if(b[i] == '\0')
            {
                b[i] = '.';
                bp = i;
                break;
            }
        }
    }
 
 
    //开始对齐小数点
    if(ap>bp)//移动b的小数点
    {
        int wei = ap - bp;
        for (int j = 1000; j >= 0; j--)
        {
            b[j + wei] = b[j];
            bp = ap;
        }
        for (int j = 0; j < wei; j++)
        {
            b[j] = '\0';
        }
    }
    else if(ap<bp)//移动a的小数点
    {
        int wei = bp - ap;
        for (int j = 1000; j >= 0; j--)
        {
            a[j + wei] = a[j];
            ap = bp;
        }
        for (int j = 0; j < wei; j++)
        {
            a[j] = '\0';
        } 
    }
    else
        ;
 
    for (int i = 3998; i >= 0; i--)
    {
        a[i + 1] = a[i];
        b[i + 1] = b[i];
    }
    a[0] = '\0';
    b[0] = '\0';
 
    int jinwei = 0; //开始从后往前进行计算
    for (int i = 3999; i >= 0; i--)
    {
        if(a[i] == '.')
        {
            c[i] = '.';
            continue;
        }
        switch(a[i])
        {
            case '\0':x=0;break;
            case '0':x = 0; break;
            case '1':x = 1; break;
            case '2':x = 2; break;
            case '3':x = 3; break;
            case '4':x = 4; break;
            case '5':x = 5; break;
            case '6':x = 6; break;
            case '7':x = 7; break;
            case '8':x = 8; break;
            case '9':x = 9; break;
 
        }
        switch(b[i])
        {
            case '\0':y=0;break;
            case '0':y = 0; break;
            case '1':y = 1; break;
            case '2':y = 2; break;
            case '3':y = 3; break;
            case '4':y = 4; break;
            case '5':y = 5; break;
            case '6':y = 6; break;
            case '7':y = 7; break;
            case '8':y = 8; break;
            case '9':y = 9; break;
        }
 
        z = x + y+jinwei;
        c[i] = z % 10 + '0';
        jinwei = z / 10;
    }
 
 
 
 
    //直接判断全为小数，没有整数！
    int k = 0;
    int sa = -1, ea = -1, la, sb = -1, eb = -1, lb, sc = -1, ec, lc,ec1,sc1 = -1;
    k = 0;
    while(a[k] != '.')//获得sa
    {
        if(a[k]!= '\0')
        {
            sa = k;
            break;
        }
        k++;
    }
    if(sa == -1)
    {
        sa = k - 1;
    }
 
    k = 0;
    while (b[k] != '.')
    {
        if(b[k]!= '\0')
        {
            sb = k;
            break;
        }
        k++;
    }
    if(sb == -1)
    {
        sb = k - 1;
    }
 
 
    k = 0;
    while (c[k] != '.')
    {
        if(c[k] != '0' && c[k] != '\0')
        {
            sc1 = k;
            break;
        }
        k++;
    }
    if(sc1 == -1)
    {
        sc1 = k - 1;
    }
    //sa sb sc赋值完成
 
 
        k = 3999;
        while(a[k] != '.')
        {
            if(a[k] != '\0')
            {
                ea = k;
                break;
            }
            k--;
        }
        if(ea == -1)
            ea = k;
 
    k = 3999;
    while(b[k] != '.')
    {
        if(b[k] != '\0')
        {
            eb = k;
            break;
        }
        k--;
    }
 
    if(eb == -1)
        eb = k;
 
        
    k = 3999;
    while(c[k] != '.')
    {
        if(eb > ea)
            ec1 = eb;
        else
            ec1 = ea;
        k--;
    }
    //eaebec赋值完成
 
    la = ea - sa;
    lb = eb - sb;
    if(sa < sb)
        sc = sa;
    else
        sc = sb;
    if(ea < eb)
        ec = eb;
    else
        ec = ea;
 
    lc = ec - sc;
 
    //将flag为0的化为整数
    if(flaga == 0)  a[ap+1] = '\0';
    if(flagb == 0) b[bp+1] = '\0';
    if(flagb == 0)
        eb--;
    if(flaga == 0)
        ea--;
    if(flaga == 0 && flagb == 0)
        lc--;
 
    //判断c为最长的数
    int flagend = 0;
    if(sc1 < sa &&sc1 < sb)
        flagend = 1;
        if (sa < sb) //开始输出a
        {
            if(flagend == 1)
                putchar(' ');
            printf("   ");
            for (int i = sa; i <= ea; i++)
                putchar(a[i]);
            if (ea > eb)
            {
                printf("\n");
            }
            else
            {
                for (int i = 0; i < eb - ea; i++)
                    printf(" ");
                printf("\n");
            }
        }
 
        else
        {
            if(flagend == 1)
                putchar(' ');
            for (int i = 0; i < sa - sb + 3; i++)
                printf(" ");
            for (int i = sa; i <= ea; i++)
                putchar(a[i]);
            if (ea > eb)
            {
                printf("\n");
            }
            else
            {
                for (int i = 0; i < eb - ea; i++)
                    printf(" ");
                printf("\n");
            }
        }
 
    printf("+");//开始输出b
    if(sa > sb)
    {
        if(flagend == 1)
                putchar(' ');
        printf("  ");
        for (int i = sb; i <= eb; i++)
            putchar(b[i]);
        if(ea < eb)
        {
            printf("\n");
        }
        else
        {
            for (int i = 0; i < ea-eb; i++)
                printf(" ");
            printf("\n");
        }
    }
    
    else
    {
        if(flagend == 1)
                putchar(' ');
        for (int i = 0; i < sb - sa + 2; i++)
            printf(" ");
        for (int i = sb; i <= eb; i++)
            putchar(b[i]);
        if(ea < eb)
        {
            printf("\n");
        }
        else
        {
            for (int i = 0; i < ea-eb; i++)
                printf(" ");
            printf("\n");
        }
    }
 
    for (int i = 0; i < lc+4; i++)
        putchar('-');
    if(flagend == 1)
                putchar('-');
    putchar('\n');
 
    if(flagend == 1)
                putchar(' ');
    for (int i = 0; i < sc1 - sc + 3; i++)
        printf(" ");
        if (flaga == 0 && flagb == 0)
        {
            for (int i = sc1; i < ec; i++)
                putchar(c[i]);
            putchar('\n');
        }
        else
        {
            for (int i = sc1; i<=ec1; i++)
        putchar(c[i]);
    putchar('\n');
    }
 
 
    return 0;
}