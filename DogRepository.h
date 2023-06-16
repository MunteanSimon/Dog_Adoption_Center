#pragma once
#include "domain.h"
#include "validators.h"
#include <vector>
#include <string>
#include <algorithm>

class DogRepoException : public DogException
{
private:
    string exception;
public:
    DogRepoException(string exception = "Default DogRepo Exception") : exception(exception) {};
    string message();
};


class DogRepository
{
private:
    vector<Dog> repo_vector;
    vector<Dog> adoption_list;
    int data_option;

public:
    //Default constructor
    DogRepository();

    //Setup data with real photo links
    int setup_data();

    //Add the new dog given as parameter to the repository
    virtual void addDog(const Dog& new_dog);

    //Finds dog by link
    virtual Dog findDogByLink(string link);

    //Remove a dog given by the link to the photo
    virtual void removeDog(string link);

    //Update the breed of a dog
    virtual void updateDog(string link, const Dog& newDog);
    //Returns all the dogs in the repository
    vector<Dog> getAll();

    //Returns the length of the repository
    int getLength();

    //
    vector<Dog> getAdoptionList();

    //
    virtual void addDogToList(Dog new_dog);

    int getDataOption();
    void setDataOption(int data);

    ~DogRepository();
};