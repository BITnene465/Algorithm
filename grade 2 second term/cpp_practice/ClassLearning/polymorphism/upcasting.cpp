#include<iostream>
using namespace std;
class Instrument{
public:
    void play(){
        cout << "Instrument::play" << endl;
    }
};
class Wind: public Instrument{
public:
    // redefining
    void play(){
        cout << "Wind::play" << endl;
    }
};
void tune(Instrument& ins){
    ins.play();
}

int main(){
    Wind w;
    w.play();
    tune(w);
    return 0;
}