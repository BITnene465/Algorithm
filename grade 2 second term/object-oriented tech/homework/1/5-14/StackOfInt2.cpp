#include "StackOfInt2.h"
StackOfInt2::StackOfInt2()
{
    data = new StackImp();
}

StackOfInt2::~StackOfInt2()
{
    delete data;
}

Element StackOfInt2::top()
{
    return data->_top();
}

void StackOfInt2::push(Element x)
{
    data->push(x);
}

void StackOfInt2::pop()
{
    data->pop();
}

int StackOfInt2::getSize()
{
    return data->getSize();
}

bool StackOfInt2::empty()
{
    return data->getSize() == 0;
}   