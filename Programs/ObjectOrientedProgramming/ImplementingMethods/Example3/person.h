#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& name, int age);
    void introduce() const;

private:
    std::string name;
    int age;
};

#endif // PERSON_H