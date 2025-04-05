#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "interFaces.h"


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
            // updateCar();
            break;
        case 2:
        if (previlege > 2) {
            std::cout << "You chose to check orders and pre orders." << std::endl;
            // checkOrders();
        } else {
            std::cout << "invaled option" << std::endl;
        }
        case 3:
        if (previlege > 4) {
            std::cout << "You chose to update or check users." << std::endl;
            // updateUser();
        } else {
            std::cout << "invaled option" << std::endl;
        }
        break;
        case 4:
            if (previlege == 7) {
                std::cout << "You chose to update or check admins." << std::endl;
                // updateAdmin();
            } else {
                std::cout << "Invalid option." << std::endl;
            }
            break;
        case 0:
            std::cout << "Exiting..." << std::endl;
            // logout();
            break;
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
}