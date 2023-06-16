#include "DogRepositoryFiles.h"
#include <iostream>
#include <fstream>

DogRepoFiles::DogRepoFiles(string _file_name) : file_name(_file_name) { this->loadFile(); }

void DogRepoFiles::saveFile()
{
    ofstream file;
    file.open(this->file_name);

    if (file.is_open())
    {
        vector<Dog> dogs = this->getAll();

        for (auto dog : dogs)
        {
            string line = dog.getBreed() + "," + dog.getName() + "," + to_string(dog.getAge()) + "," + dog.getPhotoLink();
            file << line << endl;
        }
        file.close();
    }
    else
    {
        throw DogRepoFilesException("File not opened!");
    }
}

vector<string> split(string str, char seperator)
{
    int i = 0;
    int startIndex = 0, endIndex = 0;
    vector <string> strings;
    while (i <= str.length())
    {
        if (str[i] == seperator || i == str.length())
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings.push_back(subStr);
            startIndex = endIndex + 1;
        }
        i++;
    }
    return strings;
}

void DogRepoFiles::loadFile()
{
    ifstream file;
    file.open(this->file_name);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            vector<string> words = split(line, ',');

            string breed = words[0];
            string name = words[1];
            int age = stoi(words[2]);
            string link = words[3];

            Dog dog{ breed, name, age, link };

            this->DogRepository::addDog(dog);

        }
        file.close();
    }
    else
    {
        throw DogRepoFilesException("File not opened!");
    }
}

void DogRepoFiles::saveListCSV()
{

    ofstream csvfile;

    csvfile.open("list.csv");

    csvfile << "Breed,Name,Age,PhotoLink\n";

    vector<Dog> list = this->getAdoptionList();
    for (int i = 0; i < list.size(); i++)
    {
        string line = list[i].getBreed() + "," + list[i].getName() + "," + to_string(list[i].getAge()) + "," + list[i].getPhotoLink() + "\n";
        csvfile << line;
    }
    csvfile.close();

}

void DogRepoFiles::saveListHTML()
{
    ofstream htmlfile;

    htmlfile.open("list.html");

    htmlfile << "<!DOCTYPE html><html><head><title>Adoption list</title></head> <body> <table border=\"1\" <tr> <td>Breed</td> <td>Name</td> <td>Age</td> <td>PhotoLink</td></tr>";

    vector<Dog> list = this->getAdoptionList();
    for (int i = 0; i < list.size(); i++)
    {
        string line = "<tr><td>" + list[i].getBreed() + " </td><td>" + list[i].getName() + " </td><td>" + to_string(list[i].getAge()) + " </td><td>" + list[i].getPhotoLink() + "</td></tr>";
        htmlfile << line;
    }

    htmlfile << "</table></body></html>";

    htmlfile.close();

}

void DogRepoFiles::addDog(const Dog& new_dog)
{
    this->DogRepository::addDog(new_dog);
    this->saveFile();
}

void DogRepoFiles::removeDog(string link)
{
    this->DogRepository::removeDog(link);
    this->saveFile();
}

void DogRepoFiles::updateDog(string link, const Dog& newDog)
{
    this->DogRepository::updateDog(link, newDog);
    this->saveFile();
}
void DogRepoFiles::addDogToList(Dog new_dog, int data) {

    this->DogRepository::addDogToList(new_dog);
    if (data == 1)
    {
        this->saveListCSV();
    }
    else
        if (data == 2)
        {
            this->saveListHTML();
        }
}

string DogRepoFilesException::message()
{
    return this->exception;
}

DogRepoFiles::~DogRepoFiles() = default;