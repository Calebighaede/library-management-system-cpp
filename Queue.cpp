#include"Queue.h"
#include<iostream>
#include<fstream>

using namespace std;

Queue* head = NULL;
Queue* tail = NULL;

void Queue::enqueue(IssueBook Ibook){
    if(tail == NULL){
        tail = new Queue;
        tail->next = NULL;
        tail->Ibook = Ibook;
        head = tail;
    }
    else{
        Queue* temp = new Queue;
        tail->next = temp;
        temp->Ibook = Ibook;
        temp->next = NULL;
        tail = temp;
    }
}

void Queue::set_data(fstream& Issueb){

    fstream dup("temp.txt", ios::out);
    Queue* temp = head;
    while(temp != NULL){
        dup << temp->Ibook.get_student_id()<<"|";
        dup << temp->Ibook.get_student_name()<<"|";
        dup << temp->Ibook.get_book_name()<<"|";
        dup << temp->Ibook.get_status();
        dup << "\n";
    }

    remove("IssueBook.txt");
    rename("temp.txt", "IssueBook.txt");
}

void Queue::view()
{

    if(head == NULL){
        cout << "Queue is empty" << endl;
    }
    else{
        Queue* temp = head;
        cout << "Queue elements are: " << endl;
        while(temp != NULL){
            // cout << temp->data << endl;
            temp = temp->next;
        }
        cout << "-----------------------" << endl;
    }
}
