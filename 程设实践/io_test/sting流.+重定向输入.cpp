#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
struct address_info
{
    string name;
    vector<string> address;
};
vector<address_info> infos;
string line,addr;
int main(void)
{
    fstream ifs("peopleinfo.txt",fstream::in);
    if(!ifs.is_open()){cout<<"failed to open"<<endl;return 0;}
    streambuf* oldcin=cin.rdbuf(ifs.rdbuf());    // ÖØ¶¨Ïò
    while(getline(cin,line))
    {
        address_info info;
        stringstream record(line);
        record>>info.name;
        while(record>>addr)info.address.push_back(addr);
        infos.push_back(info);
    }
    system("pause");
    // print_all
    for(int i=0;i<infos.size();++i)
    {
        cout<<infos[i].name<<' ';
        for(int j=0;j<infos[i].address.size();++j)cout<<infos[i].address[j]<<' ';
        cout<<endl;
    }
    //
    cin.rdbuf(oldcin);
    ifs.close();
    return 0;
}