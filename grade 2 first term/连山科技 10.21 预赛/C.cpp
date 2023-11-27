#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll arr[40];
ll arrtemp[40];

inline void solve(){
    ll n = 0;
    cin >> n;
    for(ll i = 0; i < 32; i++){
        cin >> arrtemp[i];
    }
    for(ll i = 0; i < n; i++){
        ll op, mask, delta;
        cin >> op >> mask >> delta;
        for(ll j = 0 ; j < 32; j++){
            arr[j] = arrtemp[j];
            if((j & mask) == mask){
                switch (op)
                {
                case 0:
                    if(j - delta >= 0 && ((j - delta)&mask) == mask){
                        arr[j] += arrtemp[j-delta];
                        // cout << j << " " << j - delta << endl;
                    }
                    break;
                case 1:
                    if(j + delta < 32 && ((j+delta)&mask) == mask){
                        
                        arr[j] += arrtemp[j+delta];
                        // cout << j << " " << j + delta << endl;
                    }
                    break;
                case 2:
                    if((j ^ delta) < 32 && (j^delta) >= 0 && ((j ^ delta)&mask) == mask){
                        arr[j] += arrtemp[j^delta];
                        // cout << j << " " << (j ^ delta) << endl;
                    }
                    break;
                default:
                    break;
                }
            }
            
        }
        memcpy(arrtemp,arr,40*sizeof(ll));
    }
    ll ans = 0;
    for(ll i = 0; i < 32; i++){
        ans = (ans ^ arr[i]);
    }
    printf("%lld\n",ans);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n = 0;
    cin >> n;
    while(n--){
        solve();
    }
    return 0;
}