// 练习使用class //
#include<iostream>   // 标准 io
#include<fstream>   // 文件读写流
#include<sstream>   // string 读写流
#include<vector>
#include<cstdio>
#include<cstring>
const char f_name[]="data.dat";
class PAdata
{
    public:
    std::istream &read(std::istream &is)
    {
        std::cout<<"name url pa"<<'\n';
        is>>this->name>>this->url>>this->pa;
        return is;
    }
    std::ostream &print(std::ostream &os)
    {
        os<<"    name:"<<this->name<<'\n';
        os<<"     url:"<<this->url<<'\n';
        os<<"password:"<<this->pa<<'\n';
        return os;
    }
    bool empty()
    {
        return !strlen(this->pa);
    }
    char name[100];
    char url[100];
    char pa[100];
};
class li_PA
{
    public:
    bool save_as_file(const char f_name[])
    {
        std::fstream ofs;
        ofs.open(f_name,std::ofstream::out | std::ofstream::binary);    // 二进制写打开文件流
        if(!ofs.is_open()){std::cout<<"can't open file:"<<f_name<<std::endl;return 0;}   // 判断文件流是否打开
        // c++风格二进制文件写入 //
        //    ofs.write(reinterpret_cast<char*>(this->data.data()),sizeof(PAdata)*data.size());   // data是vector内置的一个成员函数
        //    ofs.write((char*)&(this->data),sizeof(PAdata)*data.size());    
        //  以上两种存法和后面的读取不兼容，所以我选择一个一个存
        for(int i=0;i<data.size();++i)ofs.write((char *)&data[i],sizeof(PAdata));
        ofs.close();
        this->data.clear();
        return true;
    }
    unsigned int read_file(const char f_name[])
    {
        std::fstream ifs;
        ifs.open(f_name,std::fstream::in | std::fstream::binary);
        if(!ifs.is_open()){std::cout<<"can't open file:"<<f_name<<std::endl;return 0;}   // 读取失败
        this->data.clear();
        PAdata tmp;
        unsigned int cnt=0;
        while(1)
        {
            if(!(ifs.read((char *)&tmp,sizeof(PAdata))))break;   // 一直读到结尾
            ++cnt;
            data.push_back(tmp);
        }
        ifs.close();
        return cnt;
    }
    void print_all(void)
    {
        for(int i=1;i<=data.size();++i)
        {
            std::cout<<i<<'\n';
            data[i-1].print(std::cout);
        }
    }
    void print_all(std::vector<int> idx)   // 函数重载
    {
        for(int i=0;i<idx.size();++i)
        {
            std::cout<<i+1<<'\n';
            data[idx[i]].print(std::cout);
        }
    }
    bool addpa()
    {
        PAdata npa;
        npa.read(std::cin);
        if(!npa.empty()){data.push_back(npa);return 1;}
        else return 0;
    }
    std::vector<int> find(std::string &re_str,int flag)  
    // 单模式串，多次匹配，用kmp算法
    {
        int l=(int)re_str.length();
        std::vector<int> pi(l,0);
        // 计算pi数组
        for(int i=1;i<l;++i)
        {
            int j=pi[i-1];
            while(j>0&&re_str[i]!=re_str[j])j=pi[j-1];
            if(re_str[i]==re_str[j])++j;
            pi[i]=j;
        }
        //
        std::vector<int> idx;
        if(flag==1)
        {
            for(int i=0;i<data.size();++i)if(kmp_match(data[i].name,re_str,pi))idx.push_back(i);
            return idx;
        }
        else if(flag==2)
        {
            for(int i=0;i<data.size();++i)if(kmp_match(data[i].url,re_str,pi))idx.push_back(i);
            return idx;
        }
        else if(flag==3)
        {
            for(int i=0;i<data.size();++i)if(kmp_match(data[i].pa,re_str,pi))idx.push_back(i);
            return idx;
        }
    }
    ;
    private:
    std::vector<PAdata> data;
    // 匹配算法,类似于有限状态机 //
    bool kmp_match(std::string s,std::string &pat,std::vector<int>& pi)
    {
        int l1=(int)s.length();
        int l2=(int)pat.length();
        int p=0;
        for(int i=0;i<l1;++i)
        {
            while(s[i]!=pat[p]&&p)p=pi[p];
            if(!p&&s[i]!=pat[p])continue;
            if((++p)==l2)return 1;
        }
        return 0;
    }
    ;
};
int main_loop(li_PA& li)
{
    int flag,code,tmp_f;
    std::string re_str;
    std::cin>>flag;
    switch(flag)
    {
        case 0:
            code=-1;
            break;
        case 1:
            li.print_all();
            code=0;
            break;
        case 2:
            if(li.addpa())std::cout<<"success\n";
            else std::cout<<"fail\n";
            code=0;
            break;
        case 3:
            std::cout<<"please input regix string:";
            std::cin>>re_str;
            std::cout<<"1:by name 2:by url 3:by password"<<std::endl;
            std::cin>>tmp_f;
            if(tmp_f>3||tmp_f<1){std::cout<<"invalid input"<<std::endl;break;}
            std::vector<int> idx=li.find(re_str,tmp_f);
            std::cout<<"LIST\n=============================="<<std::endl;
            li.print_all(idx);
            code=0;
            break;
    }
    system("pause");
    system("cls");
    return code;
}
int main(void)
{
    // 如果不存在文件，就创建文件data.dat //
    std::fstream ff;
    ff.open(f_name,std::fstream::in | std::fstream::binary);
    if(!ff.is_open())ff.open(f_name,std::fstream::out | std::fstream::binary);
    ff.close();
    //
    li_PA myPAlist1;
    myPAlist1.read_file(f_name);     // 此处还是有问题
    while(1)
    {
        std::cout<<"password manager"<<std::endl;
        std::cout<<"================"<<std::endl;
        std::cout<<"0:exit 1:print all item 2:add item 3.find item(with regix)"<<std::endl;
        int code=main_loop(myPAlist1);
        if(code==-1){std::cout<<"exit success"<<std::endl;break;}
    }
    myPAlist1.save_as_file(f_name);
    return 0;
}