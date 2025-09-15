#include "MenuItem.h"
#include <iostream>
#include <iomanip>

MenuItem::MenuItem(int id, std::string name, double price)
    : id(id), name(std::move(name)), price(price) {}

int MenuItem::getId() const { return id; }
std::string MenuItem::getName() const { return name; }
double MenuItem::getPrice() const { return price; }

void MenuItem::display() const {
    std::cout << "  ID: " << std::setw(3) << id
              << " | " << std::setw(20) << std::left << name
              << " | $" << std::fixed << std::setprecision(2) << price << std::endl;
}