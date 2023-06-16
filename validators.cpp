#include "validators.h"

string DogException::message()
{
    return this->exception;
}

void DogValidator::validate_dog(const Dog& dog)
{
    string errors;

    if (dog.getBreed().size() == 0)
    {
        errors.append("Breed can't be empty\n");
    }
    if (dog.getName().size() == 0)
    {
        errors.append("Name can't be empty\n");
    }
    if (dog.getAge() <= 0)
    {
        errors.append("Invalid age\n");
    }
    if (dog.getPhotoLink().size() == 0)
    {
        errors.append("Photo Link can't be empty\n");
    }
    if (errors.size() != 0)
    {
        throw DogException(errors);
    }
}