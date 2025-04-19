#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "orderACar.h"
#include "processOrders.h"
#include "interFaces.h"
#include "adminActions.h"
#include "orderACar.h"


void printUsersInfo(){

}

void addNewUser(){

}

void deleteUser(int UserID){
    
}

void updateUser(int UserID){

}

// Admins
void printAdminsInfo(){

}

void addNewAdmin(){

}

void deleteAdmin(int adminID){

}

void updateAdmin(int adminID){

}

// Cars
void printCarsInfo(){
    carLinklist cars;
    cars.importCarsFromDataBase();
    cars.listAll();
}

void addNewCar(){

}

void deleteCar(int carID){

}

void modifyCar(int carID){ // if the car has no quantity, and there is someone who pre ordered it, his order should be move to the orders list, and the queue should be updated

}

void updateCarStocks(int carID , int addedStock){ // TO DO!
    // This will first check if the car already have stocks
    // If it does, just add the new quantity to the old one
    // If it does not, check if there is a pre order for this car
    // If there is, move the pre order to the orders list using priority queue
    // and then set the new quantity after satsfaying preorders for the car
    // If there is not, just set the new quantity for the car
    carLinklist cars;
    cars.importCarsFromDataBase();
    if (!cars.checkIfIdExists(carID)) {
        std::cout << "Car ID does not exist!" << std::endl;
    } else if (cars.CheckIfCarAvailable(carID)) { // if there is alrady a stock for the car, there is no need to check for pre orders
        cars.increaseCarQuantity(carID , addedStock);
    } else { // now check for pre orders
        Json::Value orders;
        std::ifstream orders_file("orders.json", std::ifstream::binary);
        int preOrdersCount = 0;
        orders_file >> orders;
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i]["carID"].asInt() == carID && orders[i]["status"].asString() == "pre order") {
                preOrdersCount++;
            }
        if (preOrdersCount = 0){
            // now we have to set the new quantity for the car
            cars.increaseCarQuantity(carID , addedStock);
        } else if (preOrdersCount >= addedStock){
            for (int i = 0; i < orders.size(); i++) {
                }
            }
        }

    }
}

// Orders
void printOrdersInfo(){

}
void deleteOrder(int orderID){

}
void printPreOrdersInfo(){

}
void fulfillPreOrder(int preOrderID){
    
}