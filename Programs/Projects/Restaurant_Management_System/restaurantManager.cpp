#include "RestaurantManager.h"
#include <iostream>
#include <limits>

RestaurantManager::RestaurantManager() : nextMenuItemId(1), nextOrderId(1) {
    initialize();
}

void RestaurantManager::initialize() {
    // Pre-populate some menu items
    menu.emplace_back(nextMenuItemId++, "Burger", 8.99);
    menu.emplace_back(nextMenuItemId++, "Pizza", 12.50);
    menu.emplace_back(nextMenuItemId++, "Salad", 6.75);
    menu.emplace_back(nextMenuItemId++, "Soda", 1.99);

    // Initialize tables
    for (int i = 1; i <= 10; ++i) {
        tables.emplace_back(i);
    }
}

void RestaurantManager::run() {
    int choice;
    do {
        std::cout << "\n===== Restaurant Management System =====\n";
        std::cout << "1. View Menu\n";
        std::cout << "2. View Table Status\n";
        std::cout << "3. Take New Order\n";
        std::cout << "4. View Active Orders\n";
        std::cout << "5. Process Payment\n";
        std::cout << "6. Add New Menu Item\n";
        std::cout << "7. Exit\n";
        std::cout << "======================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: viewMenu(); break;
            case 2: viewTableStatus(); break;
            case 3: takeOrder(); break;
            case 4: viewActiveOrders(); break;
            case 5: processPayment(); break;
            case 6: addMenuItem(); break;
            case 7: std::cout << "Exiting system. Goodbye!\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void RestaurantManager::viewMenu() {
    std::cout << "\n--- Restaurant Menu ---\n";
    for (const auto& item : menu) {
        item.display();
    }
    std::cout << "-----------------------\n";
}

void RestaurantManager::viewTableStatus() {
    std::cout << "\n--- Table Status ---\n";
    for (const auto& table : tables) {
        table.displayStatus();
    }
    std::cout << "--------------------\n";
}

void RestaurantManager::takeOrder() {
    int tableNumber;
    std::cout << "Enter table number: ";
    std::cin >> tableNumber;

    Table* table = findTableByNumber(tableNumber);
    if (!table) {
        std::cout << "Invalid table number.\n";
        return;
    }
    if (table->getIsOccupied()) {
        std::cout << "Table is already occupied.\n";
        return;
    }

    Order newOrder(nextOrderId, tableNumber);
    int itemId;
    while (true) {
        viewMenu();
        std::cout << "Enter menu item ID to add (or 0 to finish): ";
        std::cin >> itemId;
        if (itemId == 0) break;

        MenuItem* item = findMenuItemById(itemId);
        if (item) {
            newOrder.addItem(*item);
            std::cout << "Added " << item->getName() << " to the order.\n";
        } else {
            std::cout << "Invalid item ID.\n";
        }
    }
    
    if (newOrder.calculateTotal() > 0) {
        table->occupy(nextOrderId);
        orders.push_back(newOrder);
        std::cout << "\nOrder #" << nextOrderId << " created for Table #" << tableNumber << ".\n";
        nextOrderId++;
    } else {
        std::cout << "\nOrder cancelled as no items were added.\n";
    }
}

void RestaurantManager::viewActiveOrders() {
    std::cout << "\n--- Active Orders ---\n";
    bool found = false;
    for (const auto& order : orders) {
        if (order.getStatus() != "Paid") {
            order.display();
            std::cout << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No active orders.\n";
    }
    std::cout << "---------------------\n";
}

void RestaurantManager::processPayment() {
    int orderId;
    std::cout << "Enter Order ID to process payment: ";
    std::cin >> orderId;
    
    int orderIndex = findOrderIndexById(orderId);
    if (orderIndex != -1) {
        if (orders[orderIndex].getStatus() == "Paid") {
            std::cout << "Order #" << orderId << " has already been paid.\n";
            return;
        }
        
        orders[orderIndex].display();
        std::cout << "Confirm payment for $" << orders[orderIndex].calculateTotal() << "? (y/n): ";
        char confirm;
        std::cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            orders[orderIndex].setStatus("Paid");
            Table* table = findTableByNumber(orders[orderIndex].getTableNumber());
            if (table) {
                table->vacate();
            }
            std::cout << "Payment processed. Table #" << orders[orderIndex].getTableNumber() << " is now available.\n";
        } else {
            std::cout << "Payment cancelled.\n";
        }
    } else {
        std::cout << "Order ID not found.\n";
    }
}

void RestaurantManager::addMenuItem() {
    std::string name;
    double price;

    std::cout << "Enter new item name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    
    std::cout << "Enter item price: ";
    std::cin >> price;

    if (std::cin.fail() || price < 0) {
        std::cout << "Invalid price.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    menu.emplace_back(nextMenuItemId++, name, price);
    std::cout << "New menu item '" << name << "' added successfully.\n";
}

MenuItem* RestaurantManager::findMenuItemById(int id) {
    for (auto& item : menu) {
        if (item.getId() == id) {
            return &item;
        }
    }
    return nullptr;
}

Table* RestaurantManager::findTableByNumber(int number) {
    for (auto& table : tables) {
        if (table.getTableNumber() == number) {
            return &table;
        }
    }
    return nullptr;
}

int RestaurantManager::findOrderIndexById(int id) {
    for (int i = 0; i < orders.size(); ++i) {
        if (orders[i].getId() == id) {
            return i;
        }
    }
    return -1;
}