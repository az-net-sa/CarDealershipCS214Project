#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "orderACar.h"

class Car{
    private:
        int id;
        std::string make;
        std::string model;
        std::string color;
        int price;
        int year;
        int quantity;
    public:
        // Constructor
        Car() : id(0), make(""), model(""), color(""), price(0), year(0), quantity(0) {}
        Car(int id, std::string make, std::string model, std::string color, int price, int year, int quantity)
            : id(id), make(make), model(model), color(color), price(price), year(year), quantity(quantity) {}
        void display() {
            std::cout << "Car ID: " << id << ", Name: " << make << " " <<  model
                      << ", Color: " << color << ", Price: " << price
                      << ", Year: " << year << ", Quantity: " << quantity << std::endl;
        }
};

class carLinklist {
private:
struct node
{
Car data;
node* link;
} *p;
public:
carLinklist();
~carLinklist();
void listAll();
void removeCar(int id);
void addCar(Car car);
void importCarsFromDataBase();
};

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
void carLinklist::addCar(Car car) {
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
        addCar(car);
    }
}


bool orderACar(int buyerID){ // true if order is seccessful
    carLinklist cars;
    cars.importCarsFromDataBase();
    std::cout << "You choosed to Order a new car!\n... listing cars:" << std::endl;
    cars.listAll();
    return false;
}

void checkOrders(int id){
    std::cout << "You choosed to check your orders!" << std::endl;
}
