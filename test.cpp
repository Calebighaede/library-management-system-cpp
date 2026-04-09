#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int main(){
    string s = "KLK Vamsi|20546569";

    stringstream ss(s);

    string name;
    string id;

    getline(ss,name,'|');
    getline(ss,id);

    cout<<name<<endl<<id;
}