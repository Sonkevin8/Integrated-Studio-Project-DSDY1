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

vector<Food> menu = {
    {"Sandwiches", 3.99},
    {"Fries", 2.49},
    {"Burgers", 4.99},
    {"Fruits", 1.99}
};



vector<Beverage> beverages = {
    {"Soda", 1.49},
    {"Water", 0.99},
    {"Juice", 1.99},
    {"Coffee", 2.49}
};

struct User {                                                                                                           //Class for the users to login 
    string username;
    string password;
    int age;
    bool admin;                                                                                                         //This bool will give more functionality for  administrative users i.e teachers

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
    }
};

void showMenu();
void editMenu();

int main() {
    
    bool run = true;
    vector<User> users = { User() };

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
                                cout << endl << "Place your order: " << endl;
                                showMenu();

                                int order_choice = 0;
                                cout << endl << "Enter your choice: ";
                                cin >> order_choice;

                                int order_qty = 0;
                                cout << "Enter quantity: ";
                                cin >> order_qty;

                                if (order_choice >= 1 && order_choice <= menu.size()) {
                                    Food f = menu[order_choice - 1];
                                    f.count = order_qty;

                                    cout << endl << f.name << " x " << order_qty << " added to the cart." << endl;

                                }
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
                                editMenu();
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


void showMenu() {                                                                                                         //Food menu code
    cout << "------------------------" << endl;
    cout << "        FOOD MENU        " << endl;
    cout << "------------------------" << endl;



    int i = 1;
    for (auto item : menu) {
        cout << i << ". " << item.name << " ($" << item.price << ")" << endl;
        i++;
    }
    cout << endl;



    cout << "------------------------" << endl;
    cout << "      BEVERAGE MENU      " << endl;
    cout << "------------------------" << endl;



    i = 1;
    for (auto item : beverages) {
        cout << i << ". " << item.name << " ($" << item.price << ")" << endl;
        i++;
    }
}

void editMenu() {
    int menuChoice;
    cout << "Menu Options:" << endl;
    cout << "1. Add item" << endl;
    cout << "2. Remove item" << endl;

    cin >> menuChoice;

    while (menuChoice != 1 && menuChoice != 2) {
        cout << "Invalid input. Please enter a valid menu choice: ";
        cin.clear();
        cin.ignore();
        cin >> menuChoice;
    }

    if (menuChoice == 1) {

        int menuType;
        cout << "Menu Type:" << endl;
        cout << "1. Food" << endl;
        cout << "2. Beverage" << endl;
        cin >> menuType;

        while (menuType != 1 && menuType != 2) {
            cout << "Invalid input. Please enter a valid menu type: ";
            cin.clear();
            cin.ignore();
            cin >> menuType;
        }

        string itemName;
        float itemPrice;

        cout << "Enter the name of the new item: ";
        cin.ignore();
        getline(cin, itemName);

        cout << "Enter the price of the new item: $";
        cin >> itemPrice;

        if (menuType == 1) {
            Food newFood(itemName, itemPrice);
            menu.push_back(newFood);
            cout << "Food item added successfully!" << endl;
            cout << "Added item to Food Menu: " << newFood.name << " ($" << newFood.price << ")" << endl;
        }
        else if (menuType == 2) {
            Beverage newBeverage(itemName, itemPrice);
            beverages.push_back(newBeverage);
            cout << "Beverage item added successfully!" << endl;
            cout << "Added item to Beverage Menu: " << newBeverage.name << " ($" << newBeverage.price << ")" << endl;
        }
    }
    else if (menuChoice == 2) {
        int menuType;
        cout << "Menu Type:" << endl;
        cout << "1. Food" << endl;
        cout << "2. Beverage" << endl;
        cin >> menuType;

        while (menuType != 1 && menuType != 2) {
            cout << "Invalid input. Please enter a valid menu type: ";
            cin.clear();
            cin.ignore();
            cin >> menuType;
        }

        if (menuType == 1) {
            

            if (!menu.empty()) {
                cout << "Current Food Menu:" << endl;

                int i = 1;
                for (auto item : menu) {
                    cout << i << ". " << item.name << " ($" << item.price << ")" << endl;
                    i++;
                }

                cout << "Enter the number of the item you want to remove: ";

                int itemNumber;
                cin >> itemNumber;

                if (itemNumber >= 1 && itemNumber <= menu.size()) {
                    Food removedFood = menu[itemNumber - 1];
                    menu.erase(menu.begin() + itemNumber - 1);
                    cout << "Food item removed successfully!" << endl;
                    cout << "Removed item from Food Menu: " << removedFood.name << " ($" << removedFood.price << ")" << endl;
                }
                else {
                    cout << "Invalid item number. No item removed." << endl;
                }
            }
            else {
                cout << "The food menu is empty. No item removed." << endl;
            }
        }
        else if (menuType == 2) {
            

            if (!beverages.empty()) {
                cout << "Current Beverage Menu:" << endl;

                int i = 1;
                for (auto item : beverages) {
                    cout << i << ". " << item.name << " ($" << item.price << ")" << endl;
                    i++;
                }

                cout << "Enter the number of the item you want to remove: ";

                int itemNumber;
                cin >> itemNumber;

                if (itemNumber >= 1 && itemNumber <= beverages.size()) {
                    Beverage removedBeverage = beverages[itemNumber - 1];
                    beverages.erase(beverages.begin() + itemNumber - 1);
                    cout << "Beverage item removed successfully!" << endl;
                    cout << "Removed item from Beverage Menu: " << removedBeverage.name << " ($" << removedBeverage.price << ")" << endl;
                }
                else {
                    cout << "Invalid item number. No item removed." << endl;
                }
            }
            else {
                cout << "The beverage menu is empty. No item removed." << endl;
            }
        }
    }
}
