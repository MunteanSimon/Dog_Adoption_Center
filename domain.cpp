#include "domain.h"
#include <sstream>
Dog::Dog()
    : breed(""), name(""), age(0), photo_link("")
{
}

Dog::Dog(string _breed, string _name, int _age, string _photo_link)
    : breed(_breed), name(_name), age(_age), photo_link(_photo_link)
{
}

Dog::Dog(const Dog& dog)
    : breed(dog.breed), name(dog.name), age(dog.age), photo_link(dog.photo_link)
{
}

string Dog::getBreed() const
{
    return this->breed;
}

string Dog::getName() const
{
    return this->name;
}

int Dog::getAge() const
{
    return this->age;
}

string Dog::getPhotoLink() const
{
    return this->photo_link;
}

void Dog::setBreed(string new_breed)
{
    this->breed = new_breed;
}

void Dog::setName(string new_name)
{
    this->name = new_name;
}

void Dog::setAge(int new_age)
{
    this->age = new_age;
}

void Dog::setPhotoLink(string new_photo_link)
{
    this->photo_link = new_photo_link;
}

string Dog::toString()
{
    stringstream string;
    string << this->breed << "," << this->name << "," << this->age << "," << this->photo_link << "\n";
    return string.str();
}