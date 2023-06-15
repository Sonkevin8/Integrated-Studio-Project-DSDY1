// School-Lunch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Student names: Scott Tutone, 

#include <iostream>
#include <string>

using namespace std;

struct user {                                                                                       //user defined variable specifically for this project for the login and registration entries as well as seperating admin users from the students

    string username;
    string password;
    int age = 0;
    bool admin = false;

    user(string username_entered, string password_entered, int age_entered, bool admin_entered) {       //Constructor to be used to easily instantiate and declare new object variables of user defined type.
        username = username_entered;
        password = password_entered;
        age = age_entered;
        admin = admin_entered;
    };
};

int main()
{
    cout << "Welcome to the school lunch system" << endl;
    cout << "----------------------------------" << endl;

    char initial_input = '\n';

    user entries[5];                                                                                 //Able to store entities so a person may logout and sign in as a different user

    cout << endl << "For this program up to five users may register and log in " << endl;
    cout << "Would you like to login (L/l) or register (R/r)? ";
    
    cin >> initial_input;
    
    initial_input = tolower(initial_input);

    while (initial_input != 'l' && initial_input != 'r') {
        cin.clear();
        cin.ignore();
        cout << "Please enter in a valid input ";
        cin >> initial_input;
    }
    if (initial_input == 'l') {
        
    }
    else if (initial_input == 'r') {                                                                            
        
        string name;
        string password;
        int age;
        bool admin = false;
        
        cout << endl << "To create a new account please enter in the follwoing details " << endl;
        cout << endl << "Enter in your username: ";
        cin.ignore(1,'\n');                                                                                      //Since using the cin functions results in leftover of '\n' in the buffer the getline function reads it as done and skips past it 
        getline(cin, name);                                                                                      //Therefore this ignore function will ignore the newline character allowing the user to input the data they need to
        
        cout << "Please enter in a strong password: ";
        getline(cin, password);                                                                                  //getline function used as it also will include the spaces for user inputs
        
        cout << "Please enter in your age: ";
        while (!(cin >> age) || age<0)
        {
            cout << "ERROR: a valid number must be entered: ";
            cin.clear();
            cin.ignore(123, '\n');
        }


    }
   
    
    return 0;
}

