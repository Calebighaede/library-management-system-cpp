#ifndef QUEUE_H
#define QUEUE_H
#include"IssueBook.h"

class Queue
{
private:
    IssueBook Ibook;
    Queue* next;
public:
    // Queue(/* args */);
    // ~Queue();
    void set_data(fstream&);
    void enqueue(IssueBook);
    void view();
};



#endif