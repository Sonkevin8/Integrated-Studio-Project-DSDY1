#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Food {
    string name;
    float price;
    int count;

    Food(string n, float p) {
        name = n;
        price = p;
        count = 0;
    }

    Food() {
        name = "Empty";
        price = 0;
        count = 0;
    }
};

struct Beverage {
    
    string name;
    float price;
    int count;

    Beverage(string n, float p) {
        name = n;
        price = p;
        count = 0;
    }
    
    Beverage() {
        name = "Empty";
        price = 0;
        count = 0;
    }
};

struct Fruit {
    string name;
    float price;
    int count;

    Fruit(string n, float p) {
        name = n;
        price = p;
        count = 0;
    }
    Fruit() {
        name = "Empty";
        price = 0;
        count = 0;
    }
};

struct PackageMeal {
    string name;
    Food main_course;
    Beverage drink;
    Fruit side;

    PackageMeal(string n, Food f, Beverage b, Fruit s) {
        name = n;
        main_course = f;
        drink = b;
        side = s;
    }

    PackageMeal() {
        name = "Empty";
        main_course = Food();
        drink = Beverage();
        side = Fruit();
    }
};

struct User {
    string username;
    string password;
    int age;
    bool admin;
    PackageMeal meal;

    User(string username_entered, string password_entered, int age_entered, bool admin_entered) {
        username = username_entered;
        password = password_entered;
        age = age_entered;
        admin = admin_entered;
    };

    User() {
        username = "";
        password = "";
        age = -1;
        admin = false;
        meal = PackageMeal();
    }
};

int main() {
    
    bool run = true;
    vector<User> users = { User() };

    vector<PackageMeal> menu = {
        PackageMeal("Package 1", Food("Burger", 5.99), Beverage("Coke", 1.99), Fruit("Apple", 0.99)),
        PackageMeal("Package 2", Food("Pizza", 7.99), Beverage("Sprite", 1.99), Fruit("Banana", 0.99)),
        PackageMeal("Package 3", Food("Chicken Sandwich", 6.99), Beverage("Fanta", 1.99), Fruit("Orange", 0.99))
    };

    while (run) {
        cout << "Welcome to the school lunch system" << endl;
        cout << "----------------------------------" << endl;

        int vec_size = users.size();
        int initial_input = 0;

        cout << endl << "To utilize this program, you must have an account." << endl;
        cout << "Would you like to:" << endl;
        cout << "1) Login" << endl;
        cout << "2) Register" << endl;
        cout << "3) Exit" << endl;

        cin >> initial_input;

        while (initial_input != 1 && initial_input != 2 && initial_input != 3) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid input: ";
            cin >> initial_input;
        }

        if (initial_input == 1) {
            if (users[0].age == -1) {
                cout << "Error: There are no accounts registered. Please create an account to continue." << endl << endl;
            }
            else {
                int user_selection = -1;
                int option = 1;

                cout << '\n' << "Please select an account by entering the corresponding number to log into the system: " << endl;

                    for (int index = 0; index < vec_size; index++) {
                        if (users[index].age != -1) {
                            cout << option << ") Username: " << users[index].username << endl;
                            option++;
                        }
                    }
                cout << option << ") Go back to the menu " << endl;

                while (!(cin >> user_selection) || user_selection > option || user_selection < 1) {
                    cout << "Invalid input. Please enter a valid input: ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }

                if (user_selection == option) {
                    cout << '\n' << endl;
                }
                else {
                    int user_account = user_selection - 1;
                    string user_password;
                    int password_attempts = 0;

                    cout << users[user_account].username << ", please enter your password: ";
                    cin >> user_password;

                    while (user_password != users[user_account].password) {
                        if (password_attempts == 2) {
                            cout << "You have reached the maximum number of attempts allowed. Returning to the menu." << '\n' << endl;
                                break;
                        }
                        else {
                            password_attempts++;
                            cout << "The password you have entered does not match the data within our systems." << endl;
                            cout << "Please enter your password: ";
                            cin >> user_password;
                        }
                    }

                    if (user_password == users[user_account].password) {
                        int user_menu_selection = 0;
                        int menu_options = 1;

                        cout << endl << "Welcome back, " << users[user_account].username << "!" << endl;

                        bool stay_logged_in = true;

                        while (stay_logged_in) {
                            cout << "Would you like to:" << endl << endl;
                            cout << menu_options << ") Place an order" << endl;
                            menu_options++;
                            cout << menu_options << ") View lunch Cart" << endl;
                            menu_options++;
                            cout << menu_options << ") Logout" << endl;

                            if (users[user_account].admin) {
                                menu_options++;
                                cout << menu_options << ") Edit Menu" << endl;
                            }

                            while (!(cin >> user_menu_selection) || user_menu_selection < 1 || user_menu_selection > menu_options) {
                                cout << "Error: You have entered an invalid input. Please enter a valid input: ";
                                cin.clear();
                                cin.ignore();
                                cin >> user_menu_selection;
                            }

                            if (user_menu_selection == 1) {
                                cout << "Button 1 is working!" << endl;
                                menu_options = 1;
                            }
                            else if (user_menu_selection == 2) {
                                cout << "Button 2 is working!" << endl;
                                menu_options = 1;
                            }
                            else if (user_menu_selection == 3) {
                                cout << "Logging out..." << endl;
                                stay_logged_in = false;
                                menu_options = 1;
                            }
                            else if (user_menu_selection == 4 && users[user_account].admin) {
                                cout << "Button 4 is working!" << endl;
                                menu_options = 1;
                            }
                        }
                    }
                }
            }
        }
        else if (initial_input == 2) {
            string name;
            string password;
            int age = 0;
            char occupation = '\n';
                bool admin = false;

            cout << endl << "To create a new account, please enter the following details: " << endl;
            cout << endl << "Enter your username: ";
            cin.ignore(1, '\n');
                getline(cin, name);

            cout << "Please enter a strong password: ";
            getline(cin, password);

            cout << "Please enter your age: ";

            while (!(cin >> age) || age < 0) {
                cout << "ERROR: A valid number must be entered: ";
                cin.clear();
                cin.ignore(123, '\n');
            }

            cout << "Are you a student or a teacher at this institution (s/t)?: ";

            while (!(cin >> occupation) && occupation != 's' && occupation != 't') {
                cout << "Please enter a valid input specified within the brackets." << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }

            if (occupation == 's') {
                admin = false;
            }
            else if (occupation == 't') {
                admin = true;
            }

            User entry = User(name, password, age, admin);

            if (users[0].age == -1) {
                users[0] = entry;
            }
            else {
                users.push_back(entry);
            }

            cout << "Account has been successfully created! Please login to access our menu." << endl << endl;
        }
        else if (initial_input == 3) {
            run = false;
        }
    }

    return 0;
}