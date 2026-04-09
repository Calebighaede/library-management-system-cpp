#include"Library.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include"Stack.h"
using namespace std;

Stack stack;

void Library::set_data(){

    fstream lib("books.txt");
    fstream temp("temp.txt",ios::out);

    int n = book.size();

    for(int i=0; i<n; i++){
        temp << book.at(i).getTitle()<<"|";
        temp << book.at(i).getAuthor()<<"|";
        temp << book.at(i).getYear()<<"|";
        temp << book.at(i).getISBN();
        temp <<"\n";
    }
    lib.close();
    temp.close();
    remove("books.txt");
    rename("temp.txt", "books.txt");
}

void Library::get_data(){

    if(!book.empty()){
        book.clear();
    }

    fstream lib;
    lib.open("books.txt");

    string title;
    string author;
    string year;
    string ISBN;

    while(!lib.eof()){
        getline(lib, title,'|');
        getline(lib, author,'|');
        getline(lib,year,'|');
        getline(lib,ISBN); 
        if(lib.eof())
            break;
        book.push_back(Book(title, author, stoi(year), ISBN));
    }
    lib.close();
}

void Library::add_book(){

    string name;
    string author;
    int year;
    string ISBN;

    cin.ignore();

    cout<<"Enter Book Name : "<<endl;
    getline(cin, name);
    cout<<"Enter author name : "<<endl;
    getline(cin,author);
    cout<<"Enter Year when the book published : "<<endl;
    cin>>year;
    cout<<"Enter ISBN number of book : "<<endl;
    cin>>ISBN;
    get_data();
    book.push_back(Book(name, author, year, ISBN));
    set_data();
}

void Library::update_book(){

    get_data();

    cin.ignore();

    string book_name;
    cout << "Enter the book name to update: " << endl;
    getline(cin, book_name);

    bool bookFound = false; 

    string newTitle;
    string newAuthor;
    int newYear;
    string newISBN;

    int n = book.size();

    for(int i=0;i<n;i++){
        if(book.at(i).getTitle() == book_name){
            cout << "Enter updated Book Name: " << endl;
            getline(cin, newTitle);
            book.at(i).setTitle(newTitle);
            cout << "Enter updated author name: " << endl;
            getline(cin, newAuthor);
            book.at(i).setAuthor(newAuthor);
            cout << "Enter updated Year when the book published: " << endl;
            cin >> newYear;
            book.at(i).setYear(newYear);
            cout << "Enter updated ISBN number of book: " << endl;
            cin >> newISBN;
            book.at(i).setISBN(newISBN);

            bookFound = true;
        }
    }

    if (!bookFound) {
        cout << "Book not found in the library." << endl;
    }
    else{
        set_data();
    }

}

void Library::search_book(){
    cin.ignore();
    get_data();
    bool bookFound = false; 

    string book_name;
    cout<<"Enter the book name: "<<endl;
    getline(cin,book_name);

    int n = book.size();

    for(int i=0; i < n; i++){
        if(book.at(i).getTitle() == book_name){
            stack.push(Book(book.at(i).getTitle(), book.at(i).getAuthor(), book.at(i).getYear(),book.at(i).getISBN()));
            stack.view();
            bookFound = true;
        }
    }
    if (!bookFound) {
        cout << "Book not found in the library." << endl;
    }
}

void Library::delete_book(){
    cin.ignore();

    get_data();
    display_books();
    fstream archiveBook("archive.txt", ios::app);

    string book_name;
    cout << "Enter the book name to delete : " << endl;
    getline(cin, book_name);

    bool bookFound = false; 

    int n = book.size();
    int id;
    for(int i=0; i < n; i++){
        if(book.at(i).getTitle() == book_name){
            bookFound = true;
            archiveBook << book.at(i).getTitle() << "\n";
            archiveBook << book.at(i).getAuthor() << "\n";
            archiveBook << book.at(i).getYear() << "\n";
            archiveBook << book.at(i).getISBN() << "\n";
            archiveBook << "\n";
            id = i;
        }
    }

    archiveBook.close();

    if (!bookFound) {
        cout << "Book not found in the library." << endl;
    }
    else{
        book.erase(book.begin()+id);
        set_data();

    }
}

void Library::display_books(){

    get_data();
    int n = book.size();
    cout<<"------------------------------- LIBRARY BOOKS -----------------------------------------"<<endl;
    if(book.empty()){
        cout<<"No books in Library"<<endl;
    }
    else{
        cout<<left << setw(30);
        cout<<"Title"<<setw(25)
            <<"Author"<<setw(20)
            <<"Year"<<setw(20)
            <<"ISBN"<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        for(int i=0; i < n; i++){
            cout<<left << setw(30) ;
            cout<<book.at(i).getTitle()<<setw(25)
                <<book.at(i).getAuthor()<<setw(20)
                <<book.at(i).getYear()<<setw(20)
                <<book.at(i).getISBN()<<endl;
        }
    }
    cout<<"--------------------------------------------------------------------------------------"<<endl;
} 

