#pragma once
#include "DogRepositoryFiles.h"
#include "DogRepository.h"
#include "validators.h"

class DogServiceException : public DogException
{
private:
    string exception;
public:
    DogServiceException(string exception = "Default Service Exception") : exception(exception) {};
    string message() override;
};

class DogService
{
private:
    DogRepoFiles repository;
    DogValidator validator;


public:

    //Default constructor
    DogService(DogRepoFiles _repo, DogValidator _validator);

    //Calls the setup data from repository
    int setup_data();

    //Adds a new dog by calling the repository
    void addDog(const Dog& new_dog);

    //Removes a dog by a given link
    void removeDog(string link_to_delete);

    //Returns the trench having the given link
    Dog findDogByLink(string link);

    //
    void updateDog(string link, string new_breed, string new_name, int new_age, string new_link);

    //Get all the dogs in the repo
    vector<Dog> getAll();

    //Gets the number of elements in repository
    int getRepositoryLength();

    //Returns the dogs in the adoption list
    vector<Dog> getAdoptionList();

    //Adds a dog to the adoption list
    void addDogToList(Dog new_dog, int data);

    int getDataOption();
    void setDataOption(int data);
};