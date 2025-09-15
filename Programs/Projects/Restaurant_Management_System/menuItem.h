#ifndef RESTAURANTMANAGEMENTSYSTEM_MENUITEM_H
#define RESTAURANTMANAGEMENTSYSTEM_MENUITEM_H

#include <string>

class MenuItem {
private:
    int id;
    std::string name;
    double price;

public:
    MenuItem(int id, std::string name, double price);

    int getId() const;
    std::string getName() const;
    double getPrice() const;

    void display() const;
};

#endif //RESTAURANTMANAGEMENTSYSTEM_MENUITEM_H