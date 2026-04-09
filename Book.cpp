#include"Book.h"
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

Book::Book(){

}

Book::Book(string title, string author, int year, string ISBN){
    this->title = title;
    this->author = author;
    this->year = year;
    this->ISBN = ISBN;
}

Book::~Book(){

}

void Book::setTitle(string title){
    this->title = title;
}

string Book::getTitle(){
    return title;
}

void Book::setAuthor(string author){
    this->author = author;
}

string Book::getAuthor(){
    return author;
}

void Book::setYear(int year){
    this->year = year;
}

int Book::getYear(){
    return year;
}

void Book::setISBN(string ISBN){
    this->ISBN = ISBN;
}

string Book::getISBN(){
    return ISBN;
}

string Book::to_string()const{
    return title+"\n"+author+"\n"+std::to_string(year)+"\n"+ISBN+"\n";
}
