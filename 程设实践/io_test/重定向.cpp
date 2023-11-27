#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
    fstream outfile("output.txt", fstream::out);
    streambuf* oldcout = cout.rdbuf(outfile.rdbuf());   // oldcout是指向旧cout缓冲区的一个指针
    cout << "This line will be written to the output file" << endl;
    cout.rdbuf(oldcout);     // 恢复cout
    outfile.close();
    return 0;
}
