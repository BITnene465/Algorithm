#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll q, tot=3, jizhong=0, debuff=0;
ll K,M,A,B;
bool isend=1;
ll ans = 0;
list<ll> que;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>q;
    int flag;
    while(q--)
    {
        if(isend){   // 回合开始
            isend=0;
            jizhong -= debuff;

        }
        cin>>flag;
        if(flag==1){
            ll up = max(6ll+jizhong, 0ll);
            if(que.size()==tot){
                que.push_front(6);
                que.pop_back();
                for(auto it=que.begin();it!=que.end();++it){
                    *it += up;
                }
                continue;
            }
            que.push_front(6);
            for(auto it=que.begin();it!=que.end();++it){
                    *it += up;
            }
        }
        else if(flag==2){
            cin>>K;
            tot+=K;
        }
        else if(flag==3){
            cin>>M;
            jizhong += M;
        }
        else if(flag==4){
            cin>>A>>B;
            jizhong+=A;
            debuff+=B;
        }
        else if(flag==5){
            if(!que.size())continue;
            ll val = que.back();
            ans += val;
            que.pop_back();
            que.push_front(val);
        }
        else {
            isend = 1;
        }
        for(auto it=que.begin();it!=que.end();++it){
                    printf("%lld ",*it);
                }
            printf("\n");
    }   
    
    return 0;
}