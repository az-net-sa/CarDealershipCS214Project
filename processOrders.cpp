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
    // now add the order to the orders database
    Json::Value orders;
    std::ifstream orders_file("orders.json", std::ifstream::binary);
    orders_file >> orders;
    Json::Value new_order;
    new_order["buyerID"] = buyerID;
    new_order["carID"] = carID;
    new_order["status"] = "processing";
    new_order["orderID"] = orders[orders.size() - 1]["orderID"].asInt() + rand() % 1000 + 1;
    orders.append(new_order);
    std::ofstream orders_file_out("orders.json");
    orders_file_out << orders;
    std::cout << "Order processed successfully!" << std::endl;
    std::cout << "Your order ID is: " << new_order["orderID"].asInt() << std::endl;
    std::cout << "Your order status is: " << new_order["status"].asString() << std::endl;
    std::cout << "Your car ID is: " << new_order["carID"].asInt() << std::endl;
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
    if (buyerID == 0)
    {
      // admin
      std::cout << "You choosed to check all orders!" << std::endl;
    } else {
      // user
      std::cout << "You choosed to check your orders!" << std::endl;
    }

    
}