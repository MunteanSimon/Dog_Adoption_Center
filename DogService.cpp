#include "DogService.h"
#include "validators.h"
#include <iostream>


DogService::DogService(DogRepoFiles _repo, DogValidator _validator)
    : repository(_repo), validator(_validator)
{
}

int DogService::setup_data()
{
    return this->repository.setup_data();
}

void DogService::addDog(const Dog& new_dog)
{

    if (this->repository.findDogByLink(new_dog.getPhotoLink()).getPhotoLink() == "")
    {
        this->validator.validate_dog(new_dog);
        this->repository.addDog(new_dog);
    }
    else
    {
        throw(DogServiceException("Duplicated Dog!\n"));
    }
}

void DogService::removeDog(string link_to_delete)
{
    if (this->repository.findDogByLink(link_to_delete).getPhotoLink() != "")
    {
        this->repository.removeDog(link_to_delete);
    }
    else
    {
        throw DogServiceException("Non existing Dog !\n");
    }
}

Dog DogService::findDogByLink(string link)
{
    return this->repository.findDogByLink(link);
}

void DogService::updateDog(string link, string new_breed, string new_name, int new_age, string new_link)
{
    Dog oldDog = this->repository.findDogByLink(link);
    Dog newDog = Dog(new_breed, new_name, new_age, new_link);
    this->repository.updateDog(link, newDog);
}

vector<Dog> DogService::getAll()
{
    return this->repository.getAll();
}

int DogService::getRepositoryLength()
{
    return repository.getLength();
}


vector<Dog> DogService::getAdoptionList()
{
    return this->repository.getAdoptionList();
}

void DogService::addDogToList(Dog new_dog, int data)
{
    return this->repository.addDogToList(new_dog, data);
}

int DogService::getDataOption() {
    return this->repository.getDataOption();
}

void DogService::setDataOption(int data) {
    this->repository.setDataOption(data);
}

string DogServiceException::message()
{
    return this->exception;
}