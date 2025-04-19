#ifndef ADMINACTIONS_H
#define ADMINACTIONS_H
#include <string>
#include <iostream>
// classes
class user{
    private:
        int id;
        std::string name;
        std::string password;
    public:
        user() : id(0), name(""), password("") {}
        user(int id, std::string name, std::string password)
            : id(id), name(name), password(password) {}
        void display() {
            std::cout << "User ID: " << id << ", Name: " << name << std::endl;
        }
        int getID() {
            return id;
        }
        std::string getName() {
            return name;
        } 
};



class admin{
    private:
        int id;
        std::string name;
        std::string password;
    public:
        admin() : id(0), name(""), password("") {}
        admin(int id, std::string name, std::string password)
            : id(id), name(name), password(password) {}
        void display() {
            std::cout << "Admin ID: " << id << ", Name: " << name << std::endl;
        }
        int getID() {
            return id;
        }
        std::string getName() {
            return name;
        } 
};
// Users
void printUsersInfo();

void addNewUser();

void deleteUser(int UserID);

void updateUser(int UserID);

// Admins
void printAdminsInfo();

void addNewAdmin();

void deleteAdmin(int adminID);

void updateAdmin(int adminID);

// Cars
void printCarsInfo();

void addNewCar(); 

void deleteCar(int carID);

void modifyCar(int carID); // if the car has no quantity, and there is someone who pre ordered it, his order should be move to the orders list, and the queue should be updated

void updateCarStocks(int carID , int addedStock);
void printOrdersInfo();
void deleteOrder(int orderID);
void printPreOrdersInfo();
void fulfillPreOrder(int preOrderID);


#endif