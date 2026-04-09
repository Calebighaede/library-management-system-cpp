#include<iostream>
#include"Stack.h"
#include<iomanip>
using namespace std;

Stack* top;

Stack::Stack(){
    top = nullptr;
}

Stack::~Stack(){
    while(top != nullptr){
        Stack* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(Book book){
    Stack* new_node = new Stack;
    new_node->book = book;
    new_node->next = top;
    top = new_node;
}

void Stack::view(){
    Stack* temp;

    if(top == NULL){
        cout << "Stack is empty" << endl;
    }
    else{
        temp = top;
        while(temp != NULL){
            cout<<left << setw(30) ;
            cout<<temp->book.getTitle()<<setw(25)
                <<temp->book.getAuthor()<<setw(20)
                <<temp->book.getYear()<<setw(20)
                <<temp->book.getISBN()<<endl;
            temp = temp->next;
        }
    }
}
