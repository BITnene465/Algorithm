#include<bits/stdc++.h>
using namespace std;
int n1,m1,num1,n2,m2,num2;
struct point{
    int x,y;
    int val;
    point(int x, int y, int val):x(x),y(y),val(val){};
};
bool cmp(point a, point b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
vector<point> mat1,mat2,mat3;
int main(void)
{
    cin>>n1>>m1>>num1;
    for(int i=1;i<=num1;++i){
        int x,y,val;
        cin>>x>>y>>val;
        mat1.push_back(point(x,y,val));
    }
    cin>>n2>>m2>>num2;
    for(int i=1;i<=num2;++i){
        int x,y,val;
        cin>>x>>y>>val;
        mat2.push_back(point(x,y,val));
    }
    for(int i=0;i<mat1.size();++i){
        for(int j=0;j<mat2.size();++j){
            if(mat1[i].y != mat2[j].x)continue;
            bool flag = 0;
            int x = mat1[i].x;
            int y = mat2[j].y;
            int val = mat1[i].val*mat2[j].val;
            for(int k=0;k<mat3.size();++k){
                if(x==mat3[k].x&&y==mat3[k].y){
                    flag = 1;
                    mat3[k].val += val;
                    break;
                }
            }
            if(!flag)mat3.push_back(point(x,y,val));
        }
    }
    // output
    // for(int i=0;i<mat1.size();++i){
    //     cout<<mat1[i].x<<','<<mat1[i].y<<','<<mat1[i].val<<'\n';
    // }
    // cout<<endl;
    // for(int i=0;i<mat2.size();++i){
    //     cout<<mat2[i].x<<','<<mat2[i].y<<','<<mat2[i].val<<'\n';
    // }
    sort(mat3.begin(),mat3.end(),cmp);
    cout<<n1<<'\n'<<m2<<'\n'<<mat3.size()<<'\n';
    for(int i=0;i<mat3.size();++i){
        cout<<mat3[i].x<<','<<mat3[i].y<<','<<mat3[i].val<<'\n';
    }
    return 0;
}