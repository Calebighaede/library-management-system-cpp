#ifndef HEAP_H
#define HEAP_H
#include<vector>
#include"IssueBook.h"

using namespace std;


class Heap{
    private:
    vector<IssueBook> IBook;
    public:
    Heap();
    void insert(IssueBook);
    void get_data();
    int size();
};

#endif