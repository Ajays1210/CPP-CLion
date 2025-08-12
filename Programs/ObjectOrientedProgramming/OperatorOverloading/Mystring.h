//
// Created by ajays on 11-07-2025.
//

#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring {
private:
    char *str;
public:
    Mystring();                                 //No-args constructor
    Mystring(const char *s);                    //Overloaded constructor
    Mystring(const Mystring &source);           //Copy constructor
    ~Mystring();                                //Destructor

    void display() const;                       //Display method
    int getStrLength() const;                   //Getters
    const char *getStr() const;
};

#endif //MYSTRING_H
