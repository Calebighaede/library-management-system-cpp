#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
    string id;
    string name;
public:
    Student();
    Student(string, string);
    void view_log();
    void set_id(string);
    string get_id() const;
    void set_name();
    string get_name() const;
    ~Student();
};

#endif