#include <iostream>
#include <fstream> 
#include <string>
#include <jsoncpp/json/json.h>
#include <string.h>
/* helphull sourses:
https://www.w3schools.com/CPP/cpp_files.asp
https://stackoverflow.com/questions/32205981/reading-json-files-in-c

*/
int adminLogin(){ // this returns the admin id or 0 if the admin is not found
    Json::Value admins;
    std::ifstream admins_file("admins.json", std::ifstream::binary);
    admins_file >> admins;
    std::cout << "Please enter your username: " << std::endl;
    std::string username;
    std::cin >> username;
    bool found = false;
    for (int i = 0 ; i < admins.size() ; i++){
        if (admins[i]["name"].asString() == username) {
        std::cout << "Found!" << std::endl; 
        found = true; 
        std::cout << "Please enter your password: " << std::endl;
        std::string password;
        std::cin >> password;
        if (admins[i]["password"].asString() == password) {
            std::cout << "Welcome " << username << "!" << std::endl;
            std::cout << "You are logged in as an admin." << std::endl;
            return admins[i]["id"].asInt();
        } else {
            std::cout << "Incorrect password." << std::endl;
           
        }

    } }
    if (!found) {
            std::cout << "name not Found" << std::endl;
        }
        return 0;
}

int userLogin(){  // this returns the user id or 0 if the admin is not found
    Json::Value users;
            std::ifstream users_file("users.json", std::ifstream::binary);
            users_file >> users;
            std::cout << "Please enter your username: " << std::endl;
            std::string username;
            std::cin >> username;
            bool found = false;
            for (int i = 0 ; i < users.size() ; i++){
                if (users[i]["name"].asString() == username) {
                std::cout << "Found!" << std::endl; 
                found = true; 
                std::cout << "Please enter your password: " << std::endl;
                std::string password;
                std::cin >> password;
                if (users[i]["password"].asString() == password) {


                    return users[i]["id"].asInt();
                } else {
                    std::cout << "Incorrect password." << std::endl;
                }
    
            } }
            if (!found) {
                    std::cout << "name not Found" << std::endl;
                }
                    return 0;
}

void createUser(){
    std::cout << "Creating a new user..." << std::endl;
}
void createAdmin(){
    std::cout << "Creating a new admin..." << std::endl;
}
void deleteUser(){
    std::cout << "Deleting a user..." << std::endl;
}
void deleteAdmin(){
    std::cout << "Deleting an admin..." << std::endl;
}
void updateUser(){
    std::cout << "Updating a user..." << std::endl;
}
void updateAdmin(){
    std::cout << "Updating an admin..." << std::endl;
}

void adminInterFase(int Id){
    std::string name;
    Json::Value admins;
    std::ifstream admins_file("admins.json", std::ifstream::binary);
    admins_file >> admins;
    for (int i = 0 ; i < admins.size() ; i++){
        if (admins[i]["id"].asInt() == Id) {
            name = admins[i]["name"].asString();
            break;
        }
    }
    std::cout << "Welcome " << name << "!" << std::endl;
    std::cout << "You are logged in as an admin." << std::endl;
}

void userInterFase(int id){
    std::string name;
    Json::Value users;
    std::ifstream users_file("users.json", std::ifstream::binary);
    users_file >> users;
    for (int i = 0 ; i < users.size() ; i++){
        if (users[i]["id"].asInt() == id) {
            name = users[i]["name"].asString();
            break;
        }
    }
    std::cout << "Welcome " << name << "!" << std::endl;
    std::cout << "You are logged in as a user." << std::endl;
}
int main() {
    
    std::cout << "Hello!" << std::endl << "Are you a user or an admin?" << std::endl;
    std::string user_type;
    std::cin >> user_type;
    if (user_type == "admin") {
        int Id = adminLogin();
        if (Id != 0) {
            adminInterFase(Id);
        } else {
            std::cout << "Invalid admin credentials." << std::endl;
        }
    } else if (user_type == "user") {
        std::cout << "Is it your first time here? inter yes or no" << std::endl;
        std::string first_time;
        std::cin >> first_time;
        if (first_time == "yes") {
            std::cout << "Welcome to the system!" << std::endl;
            std::cout << "Would you like to create an account?" << std::endl;
            std::string create_account;
            std::cin >> create_account;
            if (create_account == "yes") {
                createUser();
            } else if (create_account == "no") {
                std::cout << "No proplem, You can create an account later." << std::endl;
            } else {
                std::cout << "Invalid input." << std::endl;
            }
        } else if (first_time == "no") {
            std::cout << "Welcome back!" << std::endl;
            int Id = userLogin();
            if (Id != 0) {
                userInterFase(Id);
            } else {
                std::cout << "Invalid user credentials." << std::endl;
            }
        } else {
            std::cout << "Invalid input." << std::endl;
        }

        
    } else {
        std::cout << "Invalid user type." << std::endl;
    }
    }
 
