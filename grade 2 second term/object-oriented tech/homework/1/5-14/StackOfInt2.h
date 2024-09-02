#ifndef STACKOFINT2_H
#define STACKOFINT2_H
#include <vector>
typedef int Element;
class StackOfInt2{
private:
    // 使用 vector<int> 实现的 StackImp (内部类)
    class StackImp{
    private:
        std::vector<Element> array;
    public:
        StackImp() = default;
        ~StackImp(){};
        int getSize(){
            return array.size();
        }
        void push(Element x){
            array.push_back(x);
        }
        void pop(){
            array.pop_back();
        }
        Element _top(){
            if(!array.empty()) return array[array.size()-1];
            else return -1;
        }
    };

    StackImp* data;

public:
    StackOfInt2();
    ~StackOfInt2();
    void push(Element);
    void pop();
    Element top();
    bool empty();
    int getSize();
};
#endif