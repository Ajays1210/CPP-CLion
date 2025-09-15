#ifndef RESTAURANTMANAGEMENTSYSTEM_ORDER_H
#define RESTAURANTMANAGEMENTSYSTEM_ORDER_H

#include "MenuItem.h"
#include <vector>

class Order {
private:
    int id;
    int tableNumber;
    std::vector<MenuItem> items;
    std::string status; // e.g., "Pending", "Served", "Paid"

public:
    Order(int id, int tableNumber);

    int getId() const;
    int getTableNumber() const;
    std::string getStatus() const;
    void setStatus(const std::string& newStatus);

    void addItem(const MenuItem& item);
    double calculateTotal() const;
    void display() const;
};

#endif //RESTAURANTMANAGEMENTSYSTEM_ORDER_H