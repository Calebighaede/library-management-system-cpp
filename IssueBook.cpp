#include"IssueBook.h"
#include<iostream>
#include<fstream>
#include"Queue.h"
#include<vector>
#include<iomanip>

using namespace std;

Queue queue;

vector<IssueBook> Ibook;

IssueBook::IssueBook(){
    
}

IssueBook::IssueBook(string name, string id, string book_name, string status){
    student_name = name;
    student_id = id;
    this->book_name = book_name;
    this->status = status;
}

void IssueBook::set_student_name(string student_name){
    this->student_name = student_name; 
}
string IssueBook::get_student_name() const{
    return student_name;
}

void IssueBook::set_student_id(string student_id){
    this->student_id = student_id;
}
string IssueBook::get_student_id() const{
    return student_id;
}

void IssueBook::set_book_name(string book_name){
    this->book_name = book_name;
}

string IssueBook::get_book_name() const{
    return book_name;
}

void IssueBook::set_status(string status){
    this->status = status;
}

string IssueBook::get_status() const{
    return status;
}

void IssueBook::get_data(){

    if(!Ibook.empty()){
            Ibook.clear();
    }

     fstream issueb;
     issueb.open("IssueBooks.txt");

        string student_id;
        string student_name;
        string book_name;
        string status;

        while(!issueb.eof()){
            getline(issueb, student_id,'|');
            getline(issueb, student_name,'|');
            getline(issueb,book_name,'|');
            getline(issueb, status);
            if(issueb.eof())
            break;
            Ibook.push_back(IssueBook(student_name, student_id, book_name, status));
        }
     
}

void IssueBook::set_data(){

    fstream Issueb("IssueBooks.txt");
    fstream temp("temp.txt",ios::out);

        int n = Ibook.size();
        cout<<n<<endl;

        for(int i=0; i<n; i++){
            cout<< Ibook.at(i).get_student_id()<<endl;
            temp << Ibook.at(i).get_student_id()<<"|";
            temp << Ibook.at(i).get_student_name()<<"|";
            temp << Ibook.at(i).get_book_name()<<"|";
            temp << Ibook.at(i).get_status();
            temp <<"\n";
        }
        Issueb.close();
        temp.close();
        remove("IssueBooks.txt");
        rename("temp.txt", "IssueBooks.txt");
}

void IssueBook::issue_book()
{
    get_data();

    string student_name;     
    string student_id;
    string book_name;
    string status;
    cin.ignore();
    cout<<"Enter Student Name: "<<endl;
    getline(cin, student_name);
    cout<<"Enter Student Id: "<<endl;
    getline(cin,student_id);
    cout<<"Enter Book Name: "<<endl;
    getline(cin, book_name);
    cout<<"Enter the book status take/given: "<<endl;
    getline(cin, status);
    Ibook.push_back(IssueBook(student_name, student_id, book_name, status));
    set_data();
}

void IssueBook::return_book(){
    get_data();
    string student_id;
    string book_name;
    string status;

    cout<<"Enter student Id: "<<endl;
    getline(cin,student_id);
    cout<<"Enter Book Name: "<<endl;
    getline(cin,book_name);
    cout<<"Enter the book status: "<<endl;
    getline(cin, status);
    int n = Ibook.size();

    bool bookfound = false;

    for(int i=0;i<n;i++){
        if((Ibook.at(i).get_student_id() == student_id)&&(Ibook.at(i).get_book_name() == book_name)){
            Ibook.at(i).set_status(status);
            bookfound = true;
        }
    }

    if(!bookfound){
        cout<<"No book found with the student Id"<<endl;
    }
}

void IssueBook ::view_issued_books(){
    get_data();

    int n = Ibook.size();

    for(int i=0;i<n;i++){
        cout<<left << setw(30) ;
        cout<<Ibook.at(i).get_student_id()<<setw(25)
            <<Ibook.at(i).get_student_name()<<setw(20)
            <<Ibook.at(i).get_book_name()<<setw(20)
            <<Ibook.at(i).get_status()<<endl;
    }
}

void IssueBook::view_issued_booksbyId(){
    get_data();

    int n = Ibook.size();
    cin.ignore();
    string student_id;
    cout<<"Enter Student Id: "<<endl;
    getline(cin, student_id);

    for(int i=0;i<n;i++){
        if(Ibook.at(i).get_student_id() == student_id){
            queue.enqueue(IssueBook(Ibook.at(i).get_student_name(), Ibook.at(i).get_student_id(), 
                Ibook.at(i).get_book_name(), Ibook.at(i).get_status()));
        }
    }
    queue.view();
}


IssueBook::~IssueBook(){
  
}