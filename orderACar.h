#ifndef ORDERACAR_H
#define ORDERACAR_H

bool orderACarInterface(int buyerID);
void checkOrders(int id);


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
        bool isAvailable() {
            return quantity > 0;
        }
        int getID() {
            return id;
        }
        std::string getMake() {
            return make;
        }
        std::string getModel() {
            return model;
        }
        std::string getColor() {
            return color;
        }
        int getPrice() {
            return price;
        }
        int getYear() {
            return year;
        }
        int getQuantity() {
            return quantity;
        }
        Car operator--() {
            quantity--;
            return *this;
        } // No real need for this operator, just flexing
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
bool removeCar(int id);
void appendCar(Car car);
void importCarsFromDataBase();
void exportCarsToDataBase();
bool CheckIfCarAvailable(int id);
bool checkIfIdExists(int id);
Car getCar(int id);
void reduceCarQuantity(int id);
};

class Order{
    private:
        int id;
        int carID;
        int buyerID;
        std::string status;
    public:
        Order(int id, int carID, int buyerID, std::string status)
            : id(id), carID(carID), buyerID(buyerID), status(status) {}
        void display() {
            std::cout << "Order ID: " << id << ", Car ID: " << carID
                      << ", Buyer ID: " << buyerID << ", Status: " << status << std::endl;
        }
        int getID() {
            return id;
        }
        int getCarID() {
            return carID;
        }
        int getBuyerID() {
            return buyerID;
        }
        std::string getStatus() {
            return status;
        }
        void setStatus(std::string newStatus) {
            status = newStatus;
        }  
};

class preOrder{
    private:
        int id;
        int carID;
        int buyerID;
        int queuePosition;
        std::string status;
    public:
        preOrder(int id, int carID, int buyerID, std::string status)
            : id(id), carID(carID), buyerID(buyerID), status(status) {}
        void display() {
            std::cout << "Pre Order ID: " << id << ", Car ID: " << carID
                      << ", Buyer ID: " << buyerID << ", Status: " << status << std::endl;
        }
        int getID() {
            return id;
        }
        int getCarID() {
            return carID;
        }
        int getBuyerID() {
            return buyerID;
        }
        std::string getStatus() {
            return status;
        }
        int getQueuePosition() {
            return queuePosition;
        }
        void setQueuePosition(int newQueuePosition) {
            queuePosition = newQueuePosition;
        }
        preOrder operator--() {
            queuePosition--;
            return *this;
        } // No real need for this operator, just flexing
        void setStatus(std::string newStatus) {
            status = newStatus;
        }
};
#endif