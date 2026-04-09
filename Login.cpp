#include<iostream>
#include<fstream>
#include"Login.h"

using namespace std;

Login::Login(){

}
Login::Login(string username, string password){
    this->username = username;
    this->password = password;
}
string Login::get_username() const{
    return username;
}

string Login::get_password() const{
    return password;
}

string Login::get_role() const{
    return role;
}

string Login::get_id() const{
    return id;
}
void Login::login(string* data)
{
    string username;
    string password;
    try
    {
        cout << "Enter Username: ";
        cin >> username;
        if (!is_valid_input_username(username))
        {
            throw invalid_argument("Username must be an alphanumeric character and username must start or end with an alphanumeric character and username length must be greater than 3 and less than 20.");
        }
        cout << "Enter Password: ";
        cin >> password;
        if (!is_valid_input_password(password))
        {
            throw invalid_argument("Password length must be greater than 8 and must contain at least one alphabet, one number and one special character symbol.");
        }
        Login l(username, password);

        bool flag = l.login_validation();
        if (!flag)
        {
            cout << "Username and password are Incorrect" << endl;
        }
        else{
            data[0] = l.get_id();
            data[1] = l.get_role();
        }
    }
    catch (const exception &e){
        cerr << "Exception: " << e.what() << endl;
    }
}

bool Login::is_valid_input_username(const string &input)
{

    if (input.empty())
    {
        return false;
    }

    for (char ch : input)
    {

        if (!isalnum(ch) && ch != '_' && ch != '-')
        {
            return false;
        }
    }

    if (!isalnum(input.front()) || !isalnum(input.back()))
    {
        return false;
    }

    if (input.length() < 4 || input.length() > 19)
    {
        return false;
    }

    return true;
}

bool Login::is_valid_input_password(const string &input)
{
    bool hasCharacter = false;
    bool hasNumber = false;
    bool hasSpecialCharacter = false;

    if (input.length() < 8)
    {
        return false;
    }

    for (char ch : input)
    {
        if (isalpha(ch))
        {
            hasCharacter = true;
        }
        else if (isdigit(ch))
        {
            hasNumber = true;
        }
        else if (ispunct(ch))
        {
            hasSpecialCharacter = true;
        }
    }

    return hasCharacter && hasNumber && hasSpecialCharacter;
}

bool Login::login_validation()
{

    fstream log("Login.txt");
    string id, name, pass, role;
    while (log >> id >> name >> pass >> role)
    {
        if ((name == username) && (pass == password))
        {
            this->role = role;
            this->id = id;
            return true;
        }
    }
    throw runtime_error("User not found in the database.");
}

Login::~Login()
{
}