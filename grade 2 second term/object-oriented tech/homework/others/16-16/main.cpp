#include<iostream>
#include "TPStash2.h"
#include "TStack2.h"
#include "Shape.h"
using namespace std;

int main(void)
{
    Stack<Shape*> stack;
    PStash<Shape*> pStash;

    Circle* circle = new Circle();
    Square* square = new Square();
    Line* line = new Line();


    stack.push(&circle);
    stack.push(&square);
    stack.push(&line);

    pStash.add(&circle);
    pStash.add(&square);
    pStash.add(&line);

    cout << "Drawing shapes from Stack:" << endl;
    for (Stack<Shape>::iterator it = stack.begin(); it != stack.end(); ++it)
    {
        (*it)->draw();
    }

    cout << "Drawing shapes from PStash:" << endl;
    for (PStash<Shape>::iterator it = pStash.begin(); it != pStash.end(); ++it)
    {
        (*it)->draw();
    }

    return 0;
}