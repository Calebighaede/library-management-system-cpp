#ifndef ISSUEBOOK_H
#define ISSUEBOOK_H
#include<iostream>
#include<vector>
#include"Book.h"

using namespace std;

class IssueBook{
private:
    string student_name;     
    string student_id;
    string book_name;
    string status; // Issued/return 
public:
    IssueBook();
    IssueBook(string, string, string, string);
    void get_data();
    void set_data();
    void set_student_name(string);
    void set_student_id(string);
    void set_book_name(string);
    void set_status(string);
    string get_student_name() const;
    string get_student_id() const;
    string  get_book_name() const;
    string get_status() const;

    void issue_book();
    void return_book();
    void view_issued_books();
    void view_issued_booksbyId();

    ~IssueBook();
};

#endif