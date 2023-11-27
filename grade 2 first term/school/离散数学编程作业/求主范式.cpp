#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int Ranking(char a){
    switch (a)
    {
    case '(':return 0;
    case '+':return 1;
    case '-':return 2;
    case '&':return 3;
    case '|':return 4;
    case '!':return 5;
    case ')':return 6;
    }
}
bool is_in(char a,string x){
    for(unsigned int i=0;i<x.size();i++){
        if (x[i]==a) return true;
    }
    return false;
}
string post_rpn(string &input){
    string stack,output;
    int b=0;
    for(unsigned int i=0;i<input.size();i++){
        if(is_in(input[i],"()+-&|!")){
            if(input[i]==')'){
                while(stack[stack.size()-1]!='('){
                    output+=stack[stack.size()-1];
                    stack.erase(stack.begin()+stack.size()-1);
                }
                stack.erase(stack.begin()+stack.size()-1);
            }
            else{
                while((stack.size()!=0)&&Ranking((stack[stack.size()-1]))>=Ranking(input[i])&&input[i]!='('){
                    output+=stack[stack.size()-1];
                    stack.erase(stack.begin()+stack.size()-1);
                }
                stack+=input[i];
            }
        }
        else output+=input[i];
    }
    while(stack.size()!=0) {
        output+=stack[stack.size()-1];
        stack.erase(stack.begin()+stack.size()-1);
    }
    return output;
}
string Elements(string a){
    string b="";
    for(unsigned int i=0;i<a.size();i++){
        if(a[i]>='a'&&a[i]<='z'&&!is_in(a[i],b)){
            b+=a[i];
        }
    }
    for(unsigned int x=0;x<b.size();x++){
        for(unsigned int y=0;y<b.size()-x-1;y++){
            if(a[y]>a[y+1]){
                char c=a[y];
                a[y]=a[y+1];
                a[y+1]=c;
            }
        }
    }
    return b;
}
int cal(int a,int b,char c){
    if(c=='+'){
        if(a==b) return 1;
        else return 0;
    }
    else if(c=='-'){
        if(a==1&&b==0) return 0;
        else return 1;
    }
    else if(c=='|'){
        if(a+b>=1) return 1;
        else return 0;
    }
    else if(c=='&') {return a*b;}
    else if(c=='!') {
        if(a==1) return 0;
        else return 1;
    }
}
int calculate(string a){
    while(a.size()>1){
        for(unsigned int i=0;i<a.size();i++){
        if(is_in(a[i],"+|&-!")){
            if(a[i]!='!'){
                a[i-2]=char(cal(int(a[i-2]-'0'),int(a[i-1]-'0'),a[i])+'0');
                a.erase(a.begin()+i-1);
                a.erase(a.begin()+i-1);
                break;
            } 
            else{
                a[i-1]=char(cal(int(a[i-1]-'0'),0,a[i])+'0');
                a.erase(a.begin()+i);
                break;
            }
        }
        }
    }
    return int(a[0]-'0');
}
bool is_in2(int a,int *x,int d){
    for(int i=0;i<d;i++){
        if (x[i]==a) return true;
    }
    return false;
}
bool is_in3(int n,int i0,int *x,int d){
    for(int i=i0+1;i<n;i++){
        if(!is_in2(i,x,d)) return true;
    }
    return false;
}
void PrintExpression(int *n,string number,int d){
    if(d==0){
        cout<<"0"<<" ; ";
    }
    for(int i=0;i<d;i++){
        if((i!=d-1)&&is_in2(n[i],n,d)){
            cout<<"m"<<n[i]<<" ¡Å ";
        }
        else if(is_in2(n[i],n,d)){
            cout<<"m"<<n[i]<<" ; ";
        }
    }
    for(int i=0;i<pow(2,number.size());i++){
        if(!is_in3(pow(2,number.size()),-1,n,d)){
            cout<<"1"<<endl;
            break;
        }
        else {if(!is_in2(i,n,d)&&is_in3(pow(2,number.size()),i,n,d)){
            cout<<"M"<<i<<" ¡Ä ";
        }
        else if(!is_in2(i,n,d)){
            cout<<"M"<<i<<endl;
        }}
    }
    
}
int WhereIsElement(string number0,char a){
    for(int i=0;i<number0.size();i++){
        if(number0[i]==a) return i;
    }
}
void Travesal(string number,string output2){
    string a="",number0=number;
    int c[500],d=0;
    for(int i=0;i<pow(2,number.size());i++){
        int p=i;
        a="";
        while(p!=0){
            a=char(p%2+'0')+a;
            p=p>>1;
        }
        int b=0;
        for(unsigned int j=0;j<number.size();j++){
            if(a.size()<number.size()-j) number[j]='0';
            else number[j]=a[b++];
        }
        string output=output2;
        for(unsigned int i=0;i<output.size();i++){
            if(output[i]>='a'&&output[i]<='z') {
                output[i]=number[WhereIsElement(number0,output[i])];
            }
        }
        if(calculate(output)==1) {c[d++]=i;}
 
    }
    PrintExpression(c,number,d);
}
int main(void){
    string input;
    cin>>input;
    Travesal(Elements(post_rpn(input)),post_rpn(input));
}