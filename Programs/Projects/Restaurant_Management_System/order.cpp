#include "Order.h"
#include <iostream>
#include <iomanip>

Order::Order(int id, int tableNumber)
    : id(id), tableNumber(tableNumber), status("Pending") {}

int Order::getId() const { return id; }
int Order::getTableNumber() const { return tableNumber; }
std::string Order::getStatus() const { return status; }
void Order::setStatus(const std::string& newStatus) { status = newStatus; }

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}

double Order::calculateTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.getPrice();
    }
    return total;
}

void Order::display() const {
    std::cout << "--- Order #" << id << " for Table #" << tableNumber << " ---" << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "Items:" << std::endl;
    for (const auto& item : items) {
        std::cout << "  - " << std::setw(20) << std::left << item.getName()
                  << " $" << std::fixed << std::setprecision(2) << item.getPrice() << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Total: $" << std::fixed << std::setprecision(2) << calculateTotal() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}