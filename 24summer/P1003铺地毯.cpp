#include<bits/stdc++.h>
using namespace std;
class Rect{
private:
    int _x, _y, _w, _h;
public:
    Rect(int x, int y, int w, int h):_x(x), _y(y), _w(w), _h(h){}    // constructor
    Rect() = default;   // default constructor
    bool Inside(int x, int y);
};
bool Rect::Inside(int x, int y){
    return x >= _x && x <= _x + _w && y >= _y && y <= _y + _h;
}
int n, idx;
int x, y;
Rect rect[10005];
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    idx = -1;
    for(int i =0;i<n;++i){
        int x,y,w,h;
        cin >> x >> y >> w >> h;
        rect[i] = Rect(x, y, w, h);
    }
    cin >> x >> y;
    while(n--){
        if(rect[n].Inside(x, y)){
            idx = n + 1;
            break;
        }
    }
    cout << idx << endl;
    return 0;
}