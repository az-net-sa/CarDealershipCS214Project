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


class preOrder{
    private:
    int orderID;
    int buyerID;
    int carID;
    int queuePosition;
    public:
    preOrder(int orderID, int buyerID, int carID, int queuePosition){
        this -> orderID = orderID;
        this -> buyerID = buyerID;
        this -> carID = carID;
        this -> queuePosition = queuePosition;
    }   
    preOrder(){
        this -> orderID = 0;
        this -> buyerID = 0;
        this -> carID = 0;
        this -> queuePosition = 0;
    }
    int getOrderID(){
        return this -> orderID;
    }
    int getOrderPosition(){
        return this -> queuePosition;
    }
    void setOrderPosition(int queuePosition){
        this -> queuePosition = queuePosition;
    }
    void reduceOrderPosition(){
        this -> queuePosition--;
    }
    void reduceOrderPosition(int queuePosition){ // This is called overloading
        this -> queuePosition -= queuePosition;
    }
}; 

class preOrdersPriorityQueues{
    int carID;
    preOrder preOrders[100]; 
    int usedSpace;
    public:
    preOrdersPriorityQueues(int carID){
        this -> carID = carID;
        this -> usedSpace = 0;
    }
    void addPreOrder(preOrder preOrder){
        this -> preOrders[usedSpace] = preOrder;
        this -> usedSpace++;
    }
    int getNextPreOrder(){ // This will return the order ID of the pre order that will be satisfied next
        if (this -> usedSpace == 0){
            std::cout << "No pre orders for this car!" << std::endl;
            return -1;
        } 
        if (this -> usedSpace == 1){
            int orderID = preOrders[0].getOrderID();
            this -> usedSpace--;
            return orderID;
        }
        int min = 9999999; // the lowest queue position
        int orderID = -2; // the order ID of the pre order that will be satisfied next
        int minIndex = -1; // index of the pre order with the lowest queue position
        for (int i = 0; i < this -> usedSpace; i++) {
            if (preOrders[i].getOrderPosition() < min) {
                min = preOrders[i].getOrderPosition();
                orderID = preOrders[i].getOrderID();
                minIndex = i;
            }
        }
        // Remove the pre order with the lowest queue position
        for (int i = minIndex; i < this -> usedSpace - 1; i++) {
            preOrders[i] = preOrders[i + 1];
        }
        this -> usedSpace--;
        std::cout << "The next pre order to be satisfied is: " << orderID << std::endl;
        return orderID;
    }

    void importPreOrdersFromDataBase(){
        Json::Value preOrders;
        std::ifstream orders_file("orders.json", std::ifstream::binary);
        orders_file >> preOrders;
        int preOrdersCount = 0;
        for (int i = 0; i < preOrders.size(); i++) {
            if (preOrders[i]["carID"].asInt() == carID && preOrders[i]["status"].asString() == "pre order") {
                preOrder preOrder(preOrders[i]["orderID"].asInt(), preOrders[i]["buyerID"].asInt(), preOrders[i]["carID"].asInt(), preOrders[i]["orderInQueue"].asInt());
                std::cout << "Importing pre order: " << preOrders[i]["orderID"].asInt() << "buyer ID: " << preOrders[i]["buyerID"].asInt() << "car ID: " << preOrders[i]["carID"].asInt() << "queue position: " << preOrders[i]["orderInQueue"].asInt() << std::endl;
                addPreOrder(preOrder);
            }
        }
        std::cout << "Pre orders imported successfully!" << std::endl;
        std::cout << "Pre orders count: " << usedSpace << std::endl;
    }
        
}; // Add Pre Orders as priority queues from book and the internet

#endif