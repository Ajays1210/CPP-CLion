#include "Table.h"
#include <iostream>

Table::Table(int number) : tableNumber(number), isOccupied(false), orderId(-1) {}

int Table::getTableNumber() const { return tableNumber; }
bool Table::getIsOccupied() const { return isOccupied; }
int Table::getOrderId() const { return orderId; }

void Table::occupy(int newOrderId) {
    isOccupied = true;
    orderId = newOrderId;
}

void Table::vacate() {
    isOccupied = false;
    orderId = -1;
}

void Table::displayStatus() const {
    std::cout << "  Table " << tableNumber
              << " -> Status: " << (isOccupied ? "Occupied (Order #" + std::to_string(orderId) + ")" : "Available")
              << std::endl;
}