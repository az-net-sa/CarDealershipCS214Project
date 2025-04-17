#ifndef PROCESSORDERS_H 
#define PROCESSORDERS_H

void processOrder(int buyerID ,int carID);

void processPreOrder(int buyerID , int carID );

void checkOrders(int id);

class order{
    private:
    int orderID;
    int buyerID;
    int carID;
    std::string status;
    public:
    order(int orderID, int buyerID, int carID, std::string status){
        this -> orderID = orderID;
        this -> buyerID = buyerID;
        this -> carID = carID;
        this -> status = status;
    }
    order(){
        this -> orderID = 0;
        this -> buyerID = 0;
        this -> carID = 0;
        this -> status = "";
    }
    void setOrderID(int orderID){
        this -> orderID = orderID;
    }
    void setBuyerID(int buyerID){
        this -> buyerID = buyerID;
    }
    void setCarID(int carID){
        this -> carID = carID;
    }
    void setStatus(std::string status){
        this -> status = status;
    }
    int getOrderID(){
        return this -> orderID;
    }
    int getBuyerID(){
        return this -> buyerID;
    }
    int getCarID(){
        return this -> carID;
    }
    std::string getStatus(){
        return this -> status;
    }
    void display(){
        std::cout << "Order ID: " << this -> orderID << std::endl;
        std::cout << "Buyer ID: " << this -> buyerID << std::endl;
        std::cout << "Car ID: " << this -> carID << std::endl;
        std::cout << "Status: " << this -> status << std::endl;
    }
};

// class preOrder{}; 

// class orderStack{}; // Add Orders as stack from book

// class orderQueue{}; // Add Pre Orders as priority queues from book and the internet

#endif