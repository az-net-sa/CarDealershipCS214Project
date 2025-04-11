#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "orderACar.h"
#include "processOrders.h"


void processOrder(int buyerID ,int carID){
    std::cout << "You choosed to process your order!" << std::endl ;
    // now we have to reduce the car quantity in the database and set an order and save the new quantity and the order details in there DBs
    carLinklist cars;
    cars.importCarsFromDataBase();
    if (cars.checkIfIdExists(carID))
    {
    cars.reduceCarQuantity(carID);
    cars.exportCarsToDataBase();

    } else
    {
        std::cout << "Car ID does not exist!" << std::endl;
        return; 
    }
}

void processPreOrder(int buyerID , int carID){
    std::cout << "You choosed to process your pre order!" << std::endl;
    // now we have to set a pre order and save the buyer place in the queue and the pre order details in there DBs

    // use queue datastructure to save the buyer place in the queue
}

void checkOrders(int buyerID){
    std::cout << "You choosed to check your orders!" << std::endl;
}