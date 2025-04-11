#include <iostream>
#include <fstream> 
#include <string>
#include <jsoncpp/json/json.h>
#include <string.h>
#include "interFaces.h"
/* helphull sourses:
https://www.w3schools.com/CPP/cpp_files.asp
https://stackoverflow.com/questions/32205981/reading-json-files-in-c
*/
/*
TO DO:
USER INTERFACE, DONE!
*/ 
int adminLogin(){ // this returns the admin id or 0 if the admin is not found
    Json::Value admins;
    std::ifstream admins_file("admins.json", std::ifstream::binary);
    admins_file >> admins;
    std::cout << "Welcome to the admin login page!" << std::endl;
    while (1)
    {
    std::cout << "Please enter your username: , Or you can inter 0 to go back to the previous page" << std::endl;
    std::string username;
    std::cin >> username;
    bool found = false;
    if (username == "0") {
        std::cout << "Going back to the previous page..." << std::endl;
        return 0;
    }
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
}}

int userLogin(){  // this returns the user id or 0 if the admin is not found
    Json::Value users;
        std::ifstream users_file("users.json", std::ifstream::binary);
        users_file >> users;
        std::cout << "Welcome to the user login page!" << std::endl;
        while (1)
        {
        std::cout << "Please enter your username: , Or you can inter 0 to go back to the previous page" << std::endl;
        std::string username;
        std::cin >> username;
        if (username == "0") {
            std::cout << "Going back to the previous page..." << std::endl;
            return 0;
        }
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
        }}

int createUser(){
    std::cout << "Creating a new user..." << std::endl;
    Json::Value users;
    std::ifstream users_file("users.json", std::ifstream::binary);
    users_file >> users;
    Json::Value new_user;
    bool duplicate = true;
    std::string name;
    while (duplicate)
    {
        std::cout << "Please enter your name: , Or you can inter 0 to go back to the previous page" << std::endl;
        std::cin >> name;
        if (name == "0") {
            std::cout << "Going back to the previous page..." << std::endl;
            return 0;
        }
        duplicate = false;
        for (int i = 0 ; i < users.size() ; i++){
            if (users[i]["name"].asString() == name) {
                std::cout << "This name is already taken, please choose another one." << std::endl;
                duplicate = true;
                break;
            }
        }     
    }
    
 
    std::cout << "Please enter your password: " << std::endl;
    std::string password;
    std::cin >> password;
    new_user["password"] = password;
    int newID = users[users.size() - 1]["id"].asInt() + rand() % 1000 + 1;
    new_user["id"] = newID;
    users.append(new_user);
    std::ofstream users_file_out("users.json");
    users_file_out << users;
    std::cout << "User created successfully!" << std::endl;
    return newID;
}


int main() {
    std::cout << "Welcome to the Car Dealership System!" << std::endl;
    std::cout << "This is a system to manage car orders and pre-orders." << std::endl;
    std::cout << "You can order a car, check your orders, and manage your account." << std::endl;
    while (1)
    {
        std::cout << "Please choose your role: user or admin. ,  Or you can inter 0 to exit the program, Don't worry All data is saved" << std::endl;
        std::string user_type;
        std::cin >> user_type;
        if (user_type == "admin" || user_type == "Admin" || user_type == "ADMIN") {
            int Id = adminLogin();
            if (Id != 0) 
                adminInterFase(Id);
        } else if (user_type == "user" || user_type == "User" || user_type == "USER") {
            std::cout << "Is it your first time here? inter yes or no" << std::endl;
            std::string first_time;
            std::cin >> first_time;
            if (first_time == "yes" || first_time == "y" || first_time == "Y" || first_time == "Yes") {
                std::cout << "Welcome to the system!" << std::endl;
                std::cout << "Would you like to create an account?" << std::endl;
                std::string create_account;
                std::cin >> create_account;
                if (create_account == "yes") {
                    userInterFase( createUser() );
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
        } else if (user_type == "0") {
            std::cout << "Exiting the program..." << std::endl;
            return 0;
        } else {
            std::cout << "Invalid user type." << std::endl;
        }
    }
   }