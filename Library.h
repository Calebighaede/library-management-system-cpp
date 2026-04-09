#ifndef LIBRARY_H
#define LIBRARY_H
#include<string>
#include<vector>
#include"Book.h"
#include"IssueBook.h"
#include"FileHandle.h"

using namespace std;

class Library:public FileHandle{
private:
   vector<Book>book;
   vector<IssueBook>Ibook;
public:
    void get_data();
    void set_data();
    void add_book();
    void update_book();
    void search_book();
    void delete_book();
    void display_books();
    

};

#endif