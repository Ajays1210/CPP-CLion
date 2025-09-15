#ifndef RESTAURANTMANAGEMENTSYSTEM_TABLE_H
#define RESTAURANTMANAGEMENTSYSTEM_TABLE_H

class Table {
private:
    int tableNumber;
    bool isOccupied;
    int orderId;

public:
    Table(int number);

    int getTableNumber() const;
    bool getIsOccupied() const;
    int getOrderId() const;

    void occupy(int newOrderId);
    void vacate();
    void displayStatus() const;
};

#endif //RESTAURANTMANAGEMENTSYSTEM_TABLE_H