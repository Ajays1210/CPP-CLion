#include <iostream>

class Box {
private:
    int length;
    int width;

public:
    Box (int len, int wid) : length(len), width(wid) {}

    int getLength() const {
        return length;
    }

    int getWidth() const {
        return width;
    }

    Box operator+(const Box& other) {

        int newLength = this->length + other.length;
        int newWidth = this->width + other.width;

        return Box(newLength, newWidth);
    }

    Box operator-(const Box& other) {
        int newLength = this->length - other.length;
        int newWidth = this->width - other.width;

        return Box(newLength, newWidth);
    }

    Box operator*(int multiplier) {
        return Box(this->length * multiplier, this->width * multiplier);
    }
};

int main() {
    Box box1(5, 2);
    Box box2(6, 5);

    Box box3 = box1 + box2;

    std::cout << "Box 3 Length: " << box3.getLength() << std::endl;
    std::cout << "Box 3 Width: " << box3.getWidth() << std::endl;

    Box box4 = box1 - box2;

    std::cout << "Box 4 Length: " << box4.getLength() << std::endl;
    std::cout << "Box 4 Width: " << box4.getWidth() << std::endl;

    Box box5 = box1 * 3;

    std::cout << "Box 5 Length: " << box5.getLength() << std::endl;
    std::cout << "Box 5 Width: " << box5.getWidth() << std::endl;

    return 0;
}