#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Food {                                                                                                           //user defined variable for food                                               
    string name;
    double price;
    int count;

    Food(string n, double p) {
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

struct Beverage {                                                                                                         //Struct menu for beverages                           
    
    string name;
    double price;
    int count;

    Beverage(string n, double p) {
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


struct LunchCart {
    
    Food food_cart;
    Beverage drink_cart;
    float total_price;

    LunchCart() {
        food_cart = Food();
        drink_cart = Beverage();
        total_price = 0;
    }

    LunchCart(Food main, Beverage drink, float price) {
        
        food_cart = main;
        drink_cart = drink;
        total_price = price;
    }
};


vector<Food> food_menu = {                                                                                                     //Global Variable for food and beverages which can be accessed anywhere within the code file
    {"Sandwiches", 3.99},
    {"Fries", 2.49},
    {"Burgers", 4.99},
    {"Fruits", 1.99}
};



vector<Beverage> beverages_menu = {
    {"Soda", 1.49},
    {"Water", 0.99},
    {"Juice", 1.99},
    {"Coffee", 2.49}
};


struct User {                                                                                                           //Class for the users to login 
    
    string username;
    string password;
    int age;
    LunchCart items;
    bool admin;                                                                                                         //This bool will give more functionality for  administrative users i.e teachers

    User(string username_entered, string password_entered, int age_entered, bool admin_entered) {
        username = username_entered;
        password = password_entered;
        age = age_entered;
        admin = admin_entered;
        items = LunchCart();
    };

    User() {
        username = "";
        password = "";
        age = -1;
        admin = false;
    }
};

void showMenu();                                                                                                           //Initialise seperate functions so that the compiler knows that it exists and we can put the methods for these functions below the main
void editMenu();

int main() {
    
    bool run = true;                                                                                                       //Catch for the outer loop
    vector<User> users = { User() };                                                                                       //Declaring vactor of user defined variable for users so that many people may register and log in for any given instance of the program running

    while (run) {
        cout << "Welcome to the school lunch system" << endl;
        cout << "----------------------------------" << endl;

        size_t vec_size = users.size();
        int initial_input = 0;

        cout << endl << "To utilize this program, you must have an account." << endl;
        cout << "Would you like to:" << endl;
        cout << "1) Login" << endl;
        cout << "2) Register" << endl;
        cout << "3) Exit" << endl;

        cin >> initial_input;

        while (initial_input != 1 && initial_input != 2 && initial_input != 3) {                                            //Input handler to catch the majority of unwanted inputs
            cin.clear();
            cin.ignore( 123, '\n');
            cout << "Please enter a valid input: ";
            cin >> initial_input;
        }
     

        if (initial_input == 1) {                                                                                                                       //if statments to catch each input the user may select
            
            if (users[0].age == -1) {                                                                                                                   //Because we initilaised the user within the vector it will have a default value of negative one allowing the compiler to know there are no users currently registered
                cout << "Error: There are no accounts registered. Please create an account to continue." << endl << endl;                                       
            }
            else {                                                                                                                                      //The user has selected a valid account that is registered with the system and so the program continues
                int user_selection = -1;
                int option = 1;

                cout << '\n' << "Please select an account by entering the corresponding number to log into the system: " << endl;

                    for (int index = 0; index < vec_size; index++) {                                                                                     //Iterating through the vector to list all possible users that can log into the program, also utilising a loop that iterates so it counts the number of users currently registered
                        if (users[index].age != -1) {
                            cout << option << ") Username: " << users[index].username << endl;
                            option++;
                        }
                    }
                cout << option << ") Go back to the menu " << endl;                                                                                      //Giving the user the option of going back If they havent created an account                                                                            

                while (!(cin >> user_selection) || user_selection > option || user_selection < 1) {
                    cout << "Invalid input. Please enter a valid input: ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }

                if (user_selection == option) {                                                                                                             
                    cout << '\n' << endl;
                }
                else {                                                                                                                                     //Once a account has been selected they will be asked to enter the coressponding password for the user
                    int user_account = user_selection - 1;
                    string user_password;
                    int password_attempts = 0;

                    cout << users[user_account].username << ", please enter your password: ";                                                                     
                    cin >> user_password;

                    while (user_password != users[user_account].password) {                                                                                //Gives the user multiple attempts, if the maximum has been reached they are returned into the menu which avoids the case in which an account is selected and user doesnt know the password leaving them trapped in the loop
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

                    if (user_password == users[user_account].password) {                                                                                    //If the password is correct it will welcome them back 
                        
                        int user_menu_selection = 0;
                        int menu_options = 1;

                        cout << endl << "Welcome back, " << users[user_account].username << "!" << endl;

                        bool stay_logged_in = true;

                        while (stay_logged_in) {                                                                                                            //Second loop for when the user logs in and registers, allowing them to select mutiple options
                            cout << "Would you like to:" << endl << endl;
                            cout << menu_options << ") Place an order" << endl;
                            menu_options++;
                            cout << menu_options << ") View lunchcart?" << endl;
                            menu_options++;
                            cout << menu_options << ") Logout" << endl;

                            if (users[user_account].admin) {                                                                                                //Additional option which will only show up if the user is an adminisrtator i.e an educator at the facility
                                menu_options++;
                                cout << menu_options << ") Edit Menu" << endl;
                            }

                            while (!(cin >> user_menu_selection) || user_menu_selection < 1 || user_menu_selection > menu_options) {                        //Input handler 
                                cout << "Please enter a valid input: ";
                                cin.clear();
                                cin.ignore(123, '\n');
                            }

                            if (user_menu_selection == 1) {                                                                                                 //Option will allow users to select items from the menu to order
                                
                                cout << endl << "Place your Food order" << endl;
                                showMenu();

                                int order_choice = 0;
                                cout << endl << "Enter your choice: ";
           
                                while ((!(cin >> order_choice)) || order_choice <= 0 || order_choice > food_menu.size()) {
                                    cout << "Please place in a valid order! ";
                                    cin.clear();
                                    cin.ignore(123, '\n');
                                }
                                if (order_choice == 0) {
                                    cout << "No food item added to the cart." << endl;
                                }
                                
                                int order_qty = 0;
                                cout << "Enter quantity: ";
                                while (!(cin >> order_qty) || order_qty < 0) {
                                    cout << "Please enter in a valid quantity: ";
                                }
                                Food f = Food();
                                
                                if (order_choice >= 1 && order_choice <= food_menu.size()) {
                                    f = food_menu[order_choice - 1];
                                    f.count = order_qty;
                                    cout << endl << f.name << " x " << order_qty << " added to the cart." << endl;
                                }
                                float food_cost = f.price * f.count;
                             
                                cout << endl << "Place your Beverage order or enter 0 for none " << endl;
                                cout << endl << "Enter your choice: ";
                                
                                while (!(cin >> order_choice) || order_choice<=0 || order_choice > beverages_menu.size()) {
                                    cout << "Please place in a valid order: ";
                                }
                                cout << "Enter quantity: ";
                                
                                while (!(cin >> order_qty) || order_qty < 0) {
                                    cout << "please enter in a valid quantity: ";
                                }

                                Beverage b = Beverage();
              
                                if (order_choice == 0) {
                                    cout << "No food item added to the cart." << endl;
                                }
                                else if (order_choice >= 1 && order_choice <= beverages_menu.size()) {
                                    b = beverages_menu[order_choice - 1];
                                    b.count = order_qty;

                                    cout << endl << b.name << " x " << order_qty << " added to the cart." << endl;
                                }
                                float drink_cost = b.count * b.price;
                                users[user_account].items = (LunchCart(f, b, (drink_cost+food_cost)));
                                menu_options = 1;                                                                                                        //At the end of each selection statment menu options has to be reset to a value of 1 or else the program will continue to climb and climb
                            }
                            else if (user_menu_selection == 2) {

                                if (users[user_account].items.total_price == 0) {
                                    cout << "It appears you have nothing in your lunch cart. PLease order something and it will show here" << endl;
                                }
                                else {
                                    cout << '\n' << "Food item(s): " << users[user_account].items.food_cart.name << " x" << users[user_account].items.food_cart.count << endl;
                                    cout << "Beverage item(s): " << users[user_account].items.drink_cart.name << " x" << users[user_account].items.drink_cart.count << endl;
                                    cout << "Total Price: $" << users[user_account].items.total_price << '\n' << endl;
                                }
                                menu_options = 1;
                            }
                            else if (user_menu_selection == 3) {
                                cout << "Logging out..." << endl;
                                stay_logged_in = false;
                                menu_options = 1;
                            }
                            else if (user_menu_selection == 4 && users[user_account].admin) {                                                                //Option will call seperate function which allows the admin to remove and add items to the menu
                                editMenu();
                                menu_options = 1;
                            }
                        }
                    }
                }
            }
        }
        else if (initial_input == 2) {                                                                                                                      //If the user selects registration they will hit this block of code
            string name;
            string password;                                                                                                                                //Initialising variables which will be used for the code
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

            while (!(cin >> occupation) || occupation != 's' && occupation != 't') {                                                                        //input handler 
                cout << "Please enter a valid input specified within the brackets." << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }

            if (occupation == 's') {                                                                                                                        //If the user is a student they do not get admin priveldges
                admin = false;
            }
            else if (occupation == 't') {                                   
                admin = true;
            }

            User entry = User(name, password, age, admin);                                                                                                  //Using the information gathered from the user an user entity is created using the constructor

            if (users[0].age == -1) {                                                                                                                       //if the vector list is initially empty then it will be inserted at the front 
                users[0] = entry;
            }
            else {
                users.push_back(entry);                                                                                                                     //If there are already valid users registered to the system new users will be added to the back
            }

            cout << "Account has been successfully created! Please login to access our menu." << endl << endl;                                              //Letting user know the system has logged their information and they are ready to log in
        }   
        else if (initial_input == 3) {                                                                                                                      //If the user decideds to exit the program the while loop is killed by changing run to false
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
    for (auto& item : food_menu) {
        cout << i << ". " << item.name << " ($" << item.price << ")" << endl;
        i++;
    }
    cout << endl;



    cout << "------------------------" << endl;
    cout << "      BEVERAGE MENU      " << endl;
    cout << "------------------------" << endl;



    i = 1;
    for (auto& item : beverages_menu) {
        cout << i << ". " << item.name << " ($" << item.price << ")" << endl;
        i++;
    }
}

void editMenu() {
    
    int menuChoice;                                                                                                     //initilising variable to store user input
    cout << "Menu Options:" << endl;
    cout << "1. Add item" << endl;
    cout << "2. Remove item" << endl;

    cin >> menuChoice;

    while (menuChoice != 1 && menuChoice != 2) {                                                                        //Input handler to check bad inputs 
        cout << "Invalid input. Please enter a valid menu choice: ";
        cin.clear();
        cin.ignore(123, '\n');
        cin >> menuChoice;
    }

    if (menuChoice == 1) {                                                                                              //Selection statement whjich catches if the user wishes to add or remove items 

        int menuType;
        cout << "Menu Type:" << endl;
        cout << "1. Food" << endl;
        cout << "2. Beverage" << endl;
        cin >> menuType;

        while (menuType != 1 && menuType != 2) {                                                                        //Input handler 
            cout << "Invalid input. Please enter a valid menu type: ";
            cin.clear();
            cin.ignore(123, '\n');
            cin >> menuType;
        }

        string itemName;
        float itemPrice;

        cout << "Enter the name of the new item: ";                                                                    
        cin.ignore();
        getline(cin, itemName);

        cout << "Enter the price of the new item: $";
        cin >> itemPrice;

        if (menuType == 1) {                                                                                               //Nested slection statment for the user should they choose to change either food or beverages
            Food newFood(itemName, itemPrice);
            food_menu.push_back(newFood);
            cout << "Food item added successfully!" << endl;
            cout << "Added item to Food Menu: " << newFood.name << " ($" << newFood.price << ")" << endl;
        }
        else if (menuType == 2) {
            Beverage newBeverage(itemName, itemPrice);
            beverages_menu.push_back(newBeverage);
            cout << "Beverage item added successfully!" << endl;
            cout << "Added item to Beverage Menu: " << newBeverage.name << " ($" << newBeverage.price << ")" << endl;
        }
    }
    else if (menuChoice == 2) {                                                                                            //selection statement if they want to change the drinks
        int menuType;
        cout << "Menu Type:" << endl;
        cout << "1. Food" << endl;
        cout << "2. Beverage" << endl;
        cin >> menuType;

        while (menuType != 1 && menuType != 2) {                                                                        //Input handler to catch bad inputs 
            cout << "Invalid input. Please enter a valid menu type: ";
            cin.clear();
            cin.ignore(123, '\n');
            cin >> menuType;
        }

        if (menuType == 1) {                                                                                            
            

            if (!food_menu.empty()) {
                cout << "Current Food Menu:" << endl;

                int i = 1;
                for (auto& item : food_menu) {
                    cout << i << ". " << item.name << " ($" << item.price << ")" << endl;
                    i++;
                }

                cout << "Enter the number of the item you want to remove: ";

                int itemNumber;
                cin >> itemNumber;

                if (itemNumber >= 1 && itemNumber <= food_menu.size()) {
                    Food removedFood = food_menu[itemNumber - 1];
                    food_menu.erase(food_menu.begin() + itemNumber - 1);
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
            

            if (!beverages_menu.empty()) {
                cout << "Current Beverage Menu:" << endl;

                int i = 1;
                for (auto& item : beverages_menu) {
                    cout << i << ". " << item.name << " ($" << item.price << ")" << endl;
                    i++;
                }

                cout << "Enter the number of the item you want to remove: ";

                int itemNumber;
                cin >> itemNumber;

                if (itemNumber >= 1 && itemNumber <= beverages_menu.size()) {
                    Beverage removedBeverage = beverages_menu[itemNumber - 1];
                    beverages_menu.erase(beverages_menu.begin() + itemNumber - 1);
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
