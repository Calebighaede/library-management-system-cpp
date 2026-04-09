#ifndef LOGIN_H
#define LOGIN_H

#include<iostream>
using namespace std;

class Login
{
private:
    string username;
    string password;
    string role;
    string id;
public:
    Login(/* args */);
    Login(string, string);
    void login(string*);
    string get_username() const;
    string get_password() const;
    string get_role() const;
    string get_id() const;
    bool login_validation();
    bool is_valid_input_username(const string &);
    bool is_valid_input_password(const string &);
    ~Login();
};

#endif