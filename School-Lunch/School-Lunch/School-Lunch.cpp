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
    
    const int size = 5;
    user entries[size] = { user(), user(), user(), user(), user() };                                                   //Up to five users may login and register with the program in any given instance of the program

    while (run) {
        
        cout << "Welcome to the school lunch system" << endl;
        cout << "----------------------------------" << endl;

        char initial_input = '\n';
                                                                              
        cout << endl << "To utulise this you program you must have an account" << endl;
        cout << "Up to five users can log in at a time. " << endl;
        cout << "Would you like to" << endl;
        cout << "a) Login (L/l)" << endl;
        cout << "b) Register (R/r)" << endl;
        cout << "c) Exit (E/e)" << endl;

        cin >> initial_input;

        initial_input = tolower(initial_input);

        while (initial_input != 'l' && initial_input != 'r' && initial_input != 'e') {
            cin.clear();
            cin.ignore();
            cout << "Please enter in a valid input ";
            cin >> initial_input;
        }
        if (initial_input == 'l') {
            
            if (entries[0].age == -1) {                                                                                                     //If there are no users currently registered to the system user should not be able to login
                cout << "Error, there are no accounts registered. PLease create an account to continue" << endl << endl;
            }
            else {
                
                int user_selection;
                int option = 1;
                
                cout << '\n' << "Please select an account by selecting the number on the left to log into the system with; " << endl;

                for (int index = 0; index < size; index++) {

                    if (entries[index].age != -1) {
                        cout << option <<") Username: " << entries[index].username << endl;
                        option++;
                    }
                }
                cout << option << ") Go back to menu " << endl;

                while (!(cin >> user_selection) || user_selection > (option-1) || user_selection < 1 ) {                                   //Input validator to ensure user selects a valid option
                    cout << "Invalid input. PLease enter in a valid input: ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                if (user_selection == option) {                                                                                             //If the users decides to go back then by catching this option the program will go back to the main menu.
                }
                else {
                    int user_account = user_selection - 1;                                                                                   //Since options starts at index 1, any user option that is selected will actually be indexed one less in the system
                    string user_password;
                    int password_attempts = 0;
                   
                    cout << entries[user_account].username <<" please enter in your password: ";
                    
                    cin >> user_password;

                    while (user_password != entries[user_account].password) {
                        
                        if (password_attempts == 3) {
                            break;
                        }
                        else {

                            password_attempts++;
                            cout << "The password you have enetered does not match the data withihn our systems. " << endl;
                            cout << "Please enter in your password: ";
                            cin >> user_password;
                        }
                    }

                    if (user_password == entries[user_account].password) {                                                              //Once registration and login has been completed the user is presented with a menu based on whether or not they have admin authority
                        
                        int user_menu_selection = '\n';

                        cout << endl << "Welcome back " << entries[user_account].username << endl;
                        cout << "Would you like to: " << endl << endl;
                        cout << "1) Place an order" << endl;
                        cout << "2) View lunch Cart" << endl;
                        cout << "4)Logout" << "\n" << endl;

                        cin >> user_menu_selection;

                    }
                    else if (password_attempts == 3) {
                        cout << "Sorry you have reached maximum number of attempts, returning to menu. " << endl << endl;
                    }

                }

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
        else if (initial_input == 'e') {
            run = false;
        }
    }
    return 0;
}



