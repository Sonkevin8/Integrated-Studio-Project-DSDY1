// School-Lunch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Student names: Scott Tutone, 

#include <iostream>
#include <string>

using namespace std;

struct user {                                                                                       //user defined variable specifically for this project for the login and registration entries as well as seperating admin users from the students

    string username;
    string password;
    int age;
    bool admin = false;

    user(string username_entered, string password_entered, int age_entered, bool admin_entered) {       //Constructor to be used to easily instantiate and declare new object variables of user defined type.
        username = username_entered;
        password = password_entered;
        age = age_entered;
        admin = admin_entered;
    };

    user() {                           //default constructor
        username = " ";
        password = " ";
        age = -1;
        admin = false;
    }
};

// beverage menu

struct food {                          // food structure declaration and constructors
    
    string name;
    float price;
    int count;

    food(string n, float p) {           
        name = n;
        price = p;
        count = 0;
    }
};

struct beverage {                    // beverage structure declaration and constructors
    string name;
    float price;
    int count;

    beverage(string n, float p) {
        name = n;
        price = p;
        count = 0;
    }
};

int main()                                                                             //welcome menu
{
    bool run = true;          //THis will ensuer multiple iterations of the program can be run at the same time
    
    user entries[5] = { user(), user(), user(), user(), user() };                                                   //Up to five users may login and register with the program in any given instance of the program

    while (run) {
        
        cout << "Welcome to the school lunch system" << endl;
        cout << "----------------------------------" << endl;

        char initial_input = '\n';
                                                                              
        cout << endl << "To utulise this you program you must have an account" << endl;
        cout << "Up to five users can log in at a time. " << endl;
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
            
            if (entries[0].age == -1) {                                                                              //If there are no users currently registered to the system user should not be able to login
                cout << endl <<"There are no users currently registered in the program! " << endl;
                cout << "Please create an account to get started" << endl << endl;
            }
            else {
                cout <<"Age: " << entries[0].age << endl;
                cout <<"Username: " << entries[0].username << endl;
                cout <<"Password " << entries[0].password << endl;
                cout <<"Admin? " << entries[0].admin << endl;
            }

        }
        else if (initial_input == 'r') {

            string name;
            string password;
            int age;
            char occupation = '\n';
            bool admin = false;

            cout << endl << "To create a new account please enter in the following details " << endl;
            cout << endl << "Enter in your username: ";
            cin.ignore(1, '\n');                                                                                      //Since using the cin functions results in leftover of '\n' in the buffer the getline function reads it as done and skips past it 
            getline(cin, name);                                                                                      //Therefore this ignore function will ignore the newline character allowing the user to input the data they need to

            cout << "Please enter in a strong password: ";
            getline(cin, password);                                                                                  //getline function used as it also will include the spaces for user inputs

            cout << "Please enter in your age: ";
                
            while (!(cin >> age) || age < 0)                                                                          //input handler to catch unwanted inputs
            {
                cout << "ERROR: a valid number must be entered: ";
                cin.clear();
                cin.ignore(123, '\n');
            }

            cout << "Are you a student or a teacher at this institution (s/t): ";

            cin >> occupation;

            while (!cin >> occupation && occupation != 's' && occupation != 't') {

                cout << "Please enter in a valid input specified within the brackets" << endl;
                cin.clear();
                cin.ignore();
            }

            if (occupation == 's') {
                admin = false;
            }
            else if (occupation == 't') {
                admin = true;
            }

            user entry1 = user(name, password, age, admin);                                                           //creating a new user defined variable.            
            
            int iteration = 0;

            while (iteration < 5)                                                                                               //As the list is a static list we can use a while loop to iterate through the array and find an empty spot to store the information
            {   
                if (entries[iteration].age == -1) {
                    
                    entries[iteration] = entry1;
                    break;
                }
                else {
                    iteration++;
                }
            }
         
            cout << "Account has been successfully created! PLease login and access our menu" << endl << endl;
        }

    }
    return 0;
}



