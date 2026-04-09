#ifndef STACK_H
#define STACK_H
#include"Book.h"
#include"Library.h"


class Stack
{
private:
   Book book;
   Stack* next;
public:
    Stack();
    ~Stack();

    void push(Book);
    void view();
};




#endif