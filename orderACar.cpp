#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "orderACar.h"
#include "processOrders.h"
#include "adminActions.h"

/*
helpfull sourses:
the linked list book slides

*/

/*
TO DO:
USER INTERFACE

*/

carLinklist::carLinklist() {
    p = NULL;
}
carLinklist::~carLinklist() {
    node* current = p;
    while (current != NULL) {
        node* next = current->link;
        delete current;
        current = next;
    }
}
void carLinklist::listAll() {
    node* current = p;
    while (current != NULL) {
        current->data.display();
        current = current->link;
    }
}
void carLinklist::appendCar(Car car) {
    node* newNode = new node;
    newNode->data = car;
    newNode->link = NULL;
    if (p == NULL) {
        p = newNode;
    } else {
        node* current = p;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = newNode;
    }
}

void carLinklist::importCarsFromDataBase() {
    Json::Value cars;
    std::ifstream cars_file("cars.json", std::ifstream::binary);
    cars_file >> cars;
    for (int i = 0; i < cars.size(); i++) {
        Car car(cars[i]["id"].asInt(), cars[i]["make"].asString(), cars[i]["model"].asString(),
                cars[i]["color"].asString(), cars[i]["price"].asInt(), cars[i]["year"].asInt(),
                cars[i]["quantity"].asInt());
            appendCar(car);
    }
}


bool carLinklist::checkIfIdExists(int id) {
    node *temp;
    temp = p;
    while (temp != NULL)
    {
    if (temp -> data.getID() == id)
        return true;;
    
    temp = temp -> link;
    }
    return false;
}

bool carLinklist::CheckIfCarAvailable(int id) {
    if (!checkIfIdExists(id))
    {
        std::cout << "wrong id!" << std::endl;
        return false;
    }
    node *temp;
    temp = p;
    while (temp != NULL)
    {
    if (temp -> data.getID() == id)
    {
    // now we have found the car
    // check if it is available
    if (temp -> data.isAvailable())
    {
    return true;

    } else
    {
    return false;
    }
    break;
    }
    temp = temp -> link;
    }
    return false;
}
void carLinklist::exportCarsToDataBase(){
    Json::Value cars;
    node* current = p;
    while (current != NULL) {
        Json::Value car;
        car["id"] = current->data.getID();
        car["make"] = current->data.getMake();
        car["model"] = current->data.getModel();
        car["color"] = current->data.getColor();
        car["price"] = current->data.getPrice();
        car["year"] = current->data.getYear();
        car["quantity"] = current->data.getQuantity();
        cars.append(car);
        current = current->link;
    }
    std::ofstream cars_file("cars.json");
    cars_file << cars;
    cars_file.close();
}

bool carLinklist::removeCar(int id){
    bool found = false;
    if (!checkIfIdExists(id))
    {
        std::cout << "Car ID does not exist!" << std::endl;
        return false;
    }
    node *old, *temp;
    temp = p;
    while (temp != NULL)
    {
    if (temp -> data.getID()  == id)
    {
    found = true;
    if (temp == p)
    p = temp -> link;

    else
    old -> link = temp -> link;
    delete temp;
    std::cout << "Car removed!" << std::endl;
    exportCarsToDataBase();
    return true;
    }
    else
    {
    old = temp;
    temp = temp -> link;
    }
    }
    if (found)
    {
    std::cout << "Car removed!" << std::endl;
    exportCarsToDataBase();
    return true;
    }
    std::cout << "Car not found!" << std::endl;
    return false;
    
} // Need to clean up the function

Car carLinklist::getCar(int id) {
    node *temp;
    temp = p;
    while (temp != NULL)
    {
        if (temp -> data.getID() == id)
        {
            return temp -> data;
        }
        temp = temp -> link;
    }
    std::cout << "Car not found!" << std::endl;
    return Car();
}

void carLinklist::increaseCarQuantity(int id, int quantity) {
    node *temp;
    temp = p;
    while (temp != NULL)
    {
        if (temp -> data.getID() == id)
        {
            temp -> data.increaseQuantity(quantity);
            return;
        }
        temp = temp -> link;
    }
    std::cout << "Car not found!" << std::endl;
}
void carLinklist::reduceCarQuantity(int id) {
    node *temp;
    temp = p;
    while (temp != NULL)
    {
        if (temp -> data.getID() == id)
        {
            temp -> data = --temp -> data;
            return;
        }
        temp = temp -> link;
    }
    std::cout << "Car not found!" << std::endl;
}

bool orderACarInterface(int buyerID){ // true if order is seccessful
    carLinklist cars;
    cars.importCarsFromDataBase(); // Move cars data from disk to memory
    std::cout << "You choosed to Order a new car!\n... listing cars:" << std::endl;
    while (1)
    {
        printCarsInfo();
        std::cout << "Please enter the car ID you want to order: , or you can inter 0 to cancel " << std::endl;
    int carID;
    std::cin >> carID;
    if (carID == 0)
    {
        std::cout << "Cancelling..." << std::endl;
        return false;
    }
    /* check if the car is available */
    if (!cars.checkIfIdExists(carID))
        std::cout << "Car ID does not exist!" << std::endl;
    else {

    if (cars.CheckIfCarAvailable(carID))
    {
    // now we have to reduce the car quantity in the database and set an order
    processOrder(buyerID ,carID);
    std::cout << "Order is set!" << std::endl;
        // Order details are saved in the database
        return true;
    } else
    {
    // now we have to set a pre order
        std::cout << "Car is not available! You can set a pre order!" << std::endl;
        std::cout << "Do you want to set a pre order? (y/n)" << std::endl;
        std::string answer;
        std::cin >> answer;
        if (answer == "y" || answer == "Y" || answer == "Yes" || answer == "yes")
        {
            processPreOrder(buyerID ,carID);
            std::cout << "Pre order is set! We will contact you soon when it's Available" << std::endl;
            // Pre order details are saved in the database
            return true;
        } else
        {
            std::cout << "Pre order is not set!" << std::endl;
        }
    }}
    }
}