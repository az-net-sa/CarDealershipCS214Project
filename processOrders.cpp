#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "orderACar.h"
#include "processOrders.h"


void processOrder(int buyerID ,int carID){
    std::cout << "You choosed to process your order!" << std::endl;
    // now we have to reduce the car quantity in the database and set an order and save the new quantity and the order details in there DBs
}

void processPreOrder(int buyerID , int carID){
    std::cout << "You choosed to process your pre order!" << std::endl;
    // now we have to set a pre order and save the buyer place in the queue and the pre order details in there DBs
}

void checkOrders(int id){
    std::cout << "You choosed to check your orders!" << std::endl;
}