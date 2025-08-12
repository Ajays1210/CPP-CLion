#include "Mystring.h"

int main() {
    Mystring test1;
    Mystring test2{"Max"};
    Mystring test3{test2};

    test1.display();
    test2.display();
    test3.display();

    return 0;
}