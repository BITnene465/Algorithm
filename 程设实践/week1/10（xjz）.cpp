#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
char a[1009][1009];    
/* run this program using the console pauser or add your own getch, system("pause") or input loop */    
char *l="fattyhappy";    
  
void swap(char*x,int a,int b){    
    char tmp;    
    tmp = x[a];    
    x[a] = x[b];    
    x[b] = tmp;    
}    
    
int main(int argc, char *argv[]) {    
    int T=0;    
    scanf("%d",&T);    
    getchar();    
    for(int i=0;i<T;i++){    
        gets(a[i]);    
    }    
    for(int i=0;i<T;i++){ 
      if(strlen(a[i])<10){ 
            puts("-1"); 
            continue; 
      } 
          int flag = 0;  
        if(strstr(a[i],l)) {    
            char* m = strstr(a[i],l);    
            char* g = strstr(a[i],a[i]);    
            printf("%d %d\n",m-g+3,m-g+4);    
            continue;   
        }else {    
            for(int j=0;j<strlen(a[i])-9;j++){    
                int x=-1,y=-1,cnt=0;    
                if(a[i][j]=='f') cnt++; else x=j;    
                if(a[i][j+1]=='a') cnt++;else{    
                    if(x==-1) x = j+1;    
                    else y = j+1;    
                }     
                if(a[i][j+2]=='t') cnt++;else{    
                    if(x==-1) x = j+2;    
                    else y = j+2;    
                }    
                if(a[i][j+3]=='t') cnt++;else{    
                    if(x==-1) x = j+3;    
                    else y = j+3;    
                }    
                if(a[i][j+4]=='y') cnt++;else{    
                    if(x==-1) x = j+4;    
                    else y = j+4;     
                }    
                if(a[i][j+5]=='h') cnt++;else{    
                    if(x==-1) x = j+5;    
                    else y = j+5;    
                }      
                if(a[i][j+6]=='a') cnt++;else{    
                    if(x==-1) x = j+6;    
                    else y = j+6;     
                }     
                if(a[i][j+7]=='p') cnt++;else{    
                    if(x==-1) x = j+7;    
                    else y = j+7;    
                }      
                if(a[i][j+8]=='p') cnt++;else{    
                    if(x==-1) x = j+8;    
                    else y = j+8;    
                }      
                if(a[i][j+9]=='y') cnt++;else{    
                    if(x==-1) x = j+9;    
                    else y = j+9;    
                }      
                if(cnt==8){    
                    swap(a[i],x,y);    
                    int z=j;    
                    if(a[i][z]=='f'&&a[i][z+1]=='a'&&a[i][z+2]=='t'&&a[i][z+3]=='t'&&a[i][z+4]=='y'&&a[i][z+5]=='h'&&a[i][z+6]=='a'&&a[i][z+7]=='p'&&a[i][z+8]=='p'&&a[i][z+9]=='y'){    
                        printf("%d %d\n",x+1,y+1);   
                      flag = 1;     
                      continue; 
                    }
                    }    
                else if(cnt==9){    
                    char w[1];    
                    w[0] = l[x-j];    
                    for(int q=0;q<j;q++){    
                        if(a[i][q]==w[0]){    
                            printf("%d %d\n",x+1,q+1);    
                            flag = 1;   
                            continue;    
                        }    
                    }    
                    for(int c=j+10;c<strlen(a[i]);c++){    
                        if(a[i][c]==w[0]){    
                            printf("%d %d\n",x+1,c+1);   
                         flag = 1;    
                            continue;   
                        }    
                    }    
                }    
            }    
        }  if(flag == 0) puts("-1");          
    }  
      
    return 0;    
}  
