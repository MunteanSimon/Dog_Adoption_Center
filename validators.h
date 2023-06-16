#pragma once
#include <string>
#include "domain.h"
using namespace std;


class DogException : public exception
{
private:
    string exception;
public:
    DogException(string exception = "Default Exception") : exception(exception) {};

    virtual string message();
};


class DogValidator
{
public:
    static void validate_dog(const Dog& t);
};
