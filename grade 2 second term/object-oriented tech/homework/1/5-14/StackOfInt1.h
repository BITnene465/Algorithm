#ifndef STACKOFINT1_H
#define STACKOFINT1_H
#define MAXSIZE 1005
typedef int Element;
class StackOfInt1{
private:
    // 使用数组实现的 StackImp (内部类)
    class StackImp{
    private:
        Element* array;
        int top;  // 栈顶指针
    public:
        StackImp(int size){
            array = new Element[size];
            top=-1;
        }
        ~StackImp(){
            delete[] array;
        }
        int getSize(){
            return top+1;
        }
        void push(Element x){
            array[++top] = x;
        }
        void pop(){
            --top;
        }
        Element _top(){
            if(top!=-1) return array[top];
            else return -1;
        }
    };

    StackImp* data;

public:
    StackOfInt1();
    StackOfInt1(int);
    ~StackOfInt1();
    void push(Element);
    void pop();
    Element top();
    bool empty();
    int getSize();
};
#endif