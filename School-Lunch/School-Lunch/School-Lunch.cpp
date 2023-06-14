// School-Lunch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Student names: Scott Tutone, 

#include <iostream>
#include <ctype.h>

using namespace std;

struct user {
    
    string username;
    string password;
    int age = 0;
    bool admin;
};

int main()
{
    cout << "Welcome to the school lunch system" << endl;
    cout << "----------------------------------" << endl;

    char initial_input = '\n';

    cout << endl << "Would you like to login (L/l) or register (R/r)? ";
    cin >> initial_input;
    tolower(initial_input);

    while (initial_input != 'l' && initial_input != 'r') {
        cin.clear();
        cin.ignore();
        cout << "Please enter in a valid input ";
        cin >> initial_input;
    }
    /*
    if (initial_input == ) {
    
    }
    else if () {
    
    }
    */
    
    return 0;
}

