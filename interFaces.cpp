#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "interFaces.h"
#include "orderACar.h" // This inclaude orderACarInterface(int id) , checkOrders() , checkOrders()
/*
# TO DO:
# ADD USER INTERFACE
# For admin: updateCar() , checkOrders() , updateUsersInterFace(Done!) , updateAdmins() , logout()
# For user: orderACarInterface(Almost Done) , checkOrders() , logout()
*/

void updateUsersInterFace(){
    std::cout << "You chose to update or check users." << std::endl;
    while (1){ // Add an infinite loop to keep asking for input until user exits
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. get users info" << std::endl;
    std::cout << "2. add new user" << std::endl;
    std::cout << "3. delete user" << std::endl;
    std::cout << "4. update user" << std::endl;
    std::cout << "Or you can choose 0 to exit" << std::endl;
    std::cout << "Please enter your choice: " << std::endl;
    int option;
    std::cin >> option;
    switch (option) {
        // Add do while to keep asking for input until he exits
        case 1:
            std::cout << "You chose to get users info." << std::endl;
            // getUsersInfo();
            break;
        case 2:
            std::cout << "You chose to add new user." << std::endl;
            // addNewUser();
            break;
        case 3:
            std::cout << "You chose to delete user." << std::endl;
            // deleteUser();
            break;
        case 4:
            std::cout << "You chose to update user." << std::endl;
            // updateUser();
            break;
        case 0:
            std::cout << "Exiting..." << std::endl;
            return;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
        }
    }   
}

void updateAdminsInterFace(){
    std::cout << "You chose to update or check admins." << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. get admins info" << std::endl;
    std::cout << "2. add new admin" << std::endl;
    std::cout << "3. delete admin" << std::endl;
    std::cout << "4. update admin" << std::endl;
    std::cout << "Or you can choose 0 to exit" << std::endl;
    std::cout << "Please enter your choice: " << std::endl;
    int option;
    std::cin >> option;
    switch (option) {
        // Add do while to keep asking for input until he exits
        case 1:
            std::cout << "You chose to get admins info." << std::endl;
            // getAdminsInfo();
            break;
        case 2:
            std::cout << "You chose to add new admin." << std::endl;
            // addNewAdmin();
            break;
        case 3:
            std::cout << "You chose to delete admin." << std::endl;
            // deleteAdmin();
            break;
        case 4:
            std::cout << "You chose to update admin." << std::endl;
            // updateAdmin();
            break;
        case 0:
            std::cout << "Exiting..." << std::endl;
            return;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
}

void updateCarInterFace(){
    std::cout << "You chose to update or check cars." << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. get cars info" << std::endl;
    std::cout << "2. add new car" << std::endl;
    std::cout << "3. delete car" << std::endl;
    std::cout << "4. update car" << std::endl;
    std::cout << "Or you can choose 0 to exit" << std::endl;
    std::cout << "Please enter your choice: " << std::endl;
    int option;
    std::cin >> option;
    switch (option) {
        // Add do while to keep asking for input until he exits
        case 1:
            std::cout << "You chose to get cars info." << std::endl;
            // getCarsInfo();
            break;
        case 2:
            std::cout << "You chose to add new car." << std::endl;
            // addNewCar();
            break;
        case 3:
            std::cout << "You chose to delete car." << std::endl;
            // deleteCar();
            break;
        case 4:
            std::cout << "You chose to modify car." << std::endl;
            // modifyCar();
            break;
        case 0:
            std::cout << "Exiting..." << std::endl;
            return;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
}



void adminInterFase(int Id){
    std::string name;
    Json::Value admins;
    std::ifstream admins_file("admins.json", std::ifstream::binary);
    admins_file >> admins;
    int i;
    for ( i = 0 ; i < admins.size() ; i++){
        if (admins[i]["id"].asInt() == Id) {
            name = admins[i]["name"].asString();
            break;
        }
    }
    std::cout << "Welcome " << name << "!" << std::endl;
    std::cout << "You are logged in as an admin." << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    int previlege = admins[i]["previlege"].asInt();

    std::cout << "choose the number of one of the following options:" << std::endl;
    std::cout << "1. update or check cars" << std::endl; // add , delete, update  , get info
    if (previlege > 2) {
        std::cout << "2. check orders And pre orders" << std::endl; // approve , cansel, update , refund , get Coustomer info
    }
    if (previlege > 4) {
        std::cout << "3. update or check users" << std::endl; // add , delete, update , get info
    }
    if (previlege == 7) {
        std::cout << "4. update or check admins" << std::endl; // add , delete, update , get info
    }
    std::cout << "Or you can choose 0 to exit" << std::endl;
    std::cout << "Please enter your choice: " << std::endl;

    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            std::cout << "You chose to update or check cars." << std::endl;
            updateCarInterFace();
            break;
        case 2:
        if (previlege > 2) {
            std::cout << "You chose to check orders and pre orders." << std::endl;
            checkOrders(0); // 0 for admin
        } else {
            std::cout << "invaled option" << std::endl;
        }
        case 3:
        if (previlege > 4) {
            std::cout << "You chose to update or check users." << std::endl;
            updateUsersInterFace();
        } else {
            std::cout << "invaled option" << std::endl;
        }
        break;
        case 4:
            if (previlege == 7) {
                std::cout << "You chose to update or check admins." << std::endl;
                updateAdminsInterFace();
            } else {
                std::cout << "Invalid option." << std::endl;
            }
            break;
        case 0:
            std::cout << "Exiting..." << std::endl;
            return;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
}
void userInterFase(int id){
    std::string name;
    Json::Value users;
    std::ifstream users_file("users.json", std::ifstream::binary);
    users_file >> users;
    int i;
    for (i = 0 ; i < users.size() ; i++){
        if (users[i]["id"].asInt() == id) {
            break;
        }
    }
    name = users[i]["name"].asString();
    std::cout << "Welcome " << name << "!" << std::endl;
    std::cout << "You are logged in as a user." << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "choose the number of one of the following options:" << std::endl;
    std::cout << "1. check cars" << std::endl; // get info
    std::cout << "2. check orders And pre orders" << std::endl; // get info
    std::cout << "Or you can choose 0 to logout" << std::endl;
    std::cout << "Please enter your choice: " << std::endl;

    int choice = 0;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "You chose to check cars." << std::endl;
            orderACarInterface(id);
            break;
        case 2:
            std::cout << "You chose to check orders and pre orders." << std::endl;
            checkOrders(id);
            break;
        case 0:
            std::cout << "Exiting..." << std::endl;
            return;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
}