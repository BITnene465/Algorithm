#include "StackOfInt1.h"
StackOfInt1::StackOfInt1()
{
    data = new StackImp(MAXSIZE);
}

StackOfInt1::StackOfInt1(int size)
{
    data = new StackImp(size);
}

StackOfInt1::~StackOfInt1()
{
    delete data;
}

Element StackOfInt1::top()
{
    return data->_top();
}

void StackOfInt1::push(Element x)
{
    data->push(x);
}

void StackOfInt1::pop()
{
    data->pop();
}

int StackOfInt1::getSize()
{
    return data->getSize();
}

bool StackOfInt1::empty()
{
    return data->getSize() == 0;
}   