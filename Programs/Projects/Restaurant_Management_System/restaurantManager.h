#ifndef RESTAURANTMANAGEMENTSYSTEM_RESTAURANTMANAGER_H
#define RESTAURANTMANAGEMENTSYSTEM_RESTAURANTMANAGER_H

#include "MenuItem.h"
#include "Table.h"
#include "Order.h"
#include <vector>

class RestaurantManager {
private:
    std::vector<MenuItem> menu;
    std::vector<Table> tables;
    std::vector<Order> orders;
    int nextMenuItemId;
    int nextOrderId;

    void initialize(); // Helper to pre-populate menu and tables

public:
    RestaurantManager();
    void run();

private:
    // Menu Functions
    void viewMenu();
    void addMenuItem();

    // Order Functions
    void takeOrder();
    void viewActiveOrders();
    void processPayment();

    // Table Functions
    void viewTableStatus();
    
    // Helper functions
    MenuItem* findMenuItemById(int id);
    Table* findTableByNumber(int number);
    int findOrderIndexById(int id);
};

#endif //RESTAURANTMANAGEMENTSYSTEM_RESTAURANTMANAGER_H