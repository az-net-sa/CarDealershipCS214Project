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

}

void addNewCar(){

}

void deleteCar(int carID){

}

void modifyCar(int carID){ // if the car has no quantity, and there is someone who pre ordered it, his order should be move to the orders list, and the queue should be updated

}

void updateCarStocks(int carID){ // TO DO!
    // This function will list all the cars
    // and ask the user to enter the car ID and the new quantity
    // And then use Priority Queue to satisfy the pre orders
    // And then update the cars.json file with the new quantity
    // And then update the orders.json file with the new orders getting changed! 

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