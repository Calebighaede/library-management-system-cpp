#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"Book.h"
#include"Library.h"
#include"Login.h"
#include"Student.h"
#include"IssueBook.h"


using namespace std;

const int MAX_CAPACITY = 50;

void issue_book();

void librarian_portal();

void student_portal(string);

int main(){

    Login login;
    bool flag = true;
    string login_data[2];
    string Id;

    while(flag){
        cout<<"Library Management System"<<endl;
        cout<<"1.Login"<<endl;
        cout<<"2.Exit Application"<<endl;
        cout<<"Enter your choice "<<endl;
        int n;
        cin>>n;

        switch (n){ 
        case 1:
            cout<<"Login"<<endl;
            login.login(login_data);

            if(login_data[1] == "student"){
                student_portal(login_data[0]);
            }
            else if(login_data[1] == "librarian"){
                librarian_portal();
            }
            else{
                continue;
            }
            
            break;
        case 2:
            cout<<"Close application"<<endl;
            flag = false;
            break;
        default:
            cout<<"Invalid Option"<<endl;
            break;
        }
    }
    return 0;
}

void librarian_portal(){

    bool flag = true;
    Library library;
    
    while (flag){
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        cout<<"1. Add a Book"<<endl;
        cout<<"2. Update a Book"<<endl;
        cout<<"3. Issued Book"<<endl;
        cout<<"4. Search for a Book"<<endl;
        cout<<"5. Delete a Book"<<endl;
        cout<<"6. Dispaly all Books"<<endl;
        cout<<"7. Logout"<<endl;

        int n;
        cout<< "Enter your choice: "<<endl;
        cin>> n;

        switch (n)
        {
        case 1:
            library.add_book();
            break;
        case 2:
            library.update_book();
            break;
        case 3:
            issue_book();
            break;
        case 4:
            library.search_book();
            break;
        case 5: 
            library.delete_book();
            break;
        case 6:
            library.display_books();
            break;
        case 7:
            flag = false;
            break;
        default:        
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
}

void student_portal(string id){
    cout<<"--------------------------------------------------------------------------------------"<<endl;

  
    
}

void issue_book(){

    IssueBook Ibook;

    bool flag = true;
    
    while(flag){
        int n;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        cout<<"1. Issue Book"<<endl;
        cout<<"2. Return Book"<<endl;
        cout<<"3. Display Issued Books by Student ID"<<endl;
        cout<<"4. Display Issued Books"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>n;
        switch(n){
            case 1:
                Ibook.issue_book();
                break;
            case 2:
                Ibook.return_book();
                break;
            case 3:
                Ibook.view_issued_booksbyId();
                break;
            case 4:
                Ibook.view_issued_books();
                break;
            case 5:
                flag = false;
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
}
