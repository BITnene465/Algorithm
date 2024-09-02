#include <iostream>
using namespace std;
class Instrument
{
public:
    virtual void play()
    {
        cout << "Instrument::play" << endl;
    }
};
class Wind : public Instrument
{
public:
    // overriding
    void play()
    {
        cout << "Wind::play" << endl;
    }
};
void tune(Instrument &ins)
{
    ins.play();
}

int main()
{
    Wind w;
    w.play();
    tune(w);
    return 0;
}