#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;

class Book
{
private:
    /* data */ 
    string title;
    string author;
    int year;
    string ISBN;

public:
    Book();
    Book(string title, string author, int year, string ISBN);
    void setTitle(string );
    string getTitle();
    void setAuthor(string );
    string getAuthor();
    void setYear(int);
    int getYear();
    void setISBN(string);
    string getISBN();
    string to_string()const;
    ~Book();
};

#endif
