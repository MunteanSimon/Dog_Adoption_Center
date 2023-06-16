#pragma once
#include <string>
using namespace std;

class Dog {
private:
    string breed;
    string name;
    int age;
    string photo_link;

public:

    //Default constructor
    Dog();
    //Parametrized constructor
    Dog(string, string, int, string);
    //Copy constructor
    Dog(const Dog& dog);

    //Get the breed of the dog
    string getBreed() const;
    //Get the name of the dog
    string getName() const;
    //Get the age of the dog
    int getAge() const;
    //Get the photographer link
    string getPhotoLink() const;

    //Set the current breed to a new one
    void setBreed(string new_breed);
    //Set the current name to a new one
    void setName(string new_name);
    //Set the current age to a new one
    void setAge(int new_age);
    //Set the current photo link to a new one
    void setPhotoLink(string new_photo_link);

    string toString();
};