#pragma once
#include "DogRepository.h"
#include "validators.h"

class DogRepoFilesException : public DogException
{
private:
    string exception;
public:
    DogRepoFilesException(string exception = "Default RepoFilesException") : exception(exception) {};
    string message();
};

class DogRepoFiles : public DogRepository
{
private:
    string file_name;
public:
    DogRepoFiles(string _file_name = "default.txt");

    void saveFile();
    void loadFile();

    void saveListCSV();
    void saveListHTML();


    void addDog(const Dog& new_dog);
    void removeDog(string link);
    //Update the trench size of the trench coat having the link recieved as parameter
    void updateDog(string link, const Dog& newDog);

    void addDogToList(Dog new_dog, int data);

    ~DogRepoFiles();
};