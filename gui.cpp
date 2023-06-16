#include "gui.h"
#include <QMessageBox>
#include "ui_gui.h"
#include "utils.h"

gui::gui(DogService service, QWidget *parent)
    : QMainWindow(parent), service(service)
{
    ui.setupUi(this);
    ui.userButtonsStackedWidget->setCurrentIndex(0);
}

gui::~gui()
{}


void gui::handleDisplay()
{
    vector<Dog> dogs = this->service.getAll();
    ui.coatsList->clear();
    for (auto dog : dogs)
    {
        ui.coatsList->addItem(QString::fromStdString(dog.toString()));
    }
}

void gui::handleShowInternalList()
{
    vector<Dog> dogs = this->service.getAdoptionList();
    ui.shoppingBasketList->clear();
    for (auto dog : dogs)
    {
        ui.shoppingBasketList->addItem(QString::fromStdString(dog.toString()));
    }
}

void gui::handleStartUser()
{
    ui.shoppingBasketList->clear();
    ui.userButtonsStackedWidget->setCurrentIndex(1);
    int data = ui.savingOptionBox->currentIndex() + 1;
    this->service.setDataOption(data);
    vector<Dog> dogs = this->service.getAll();
    for (auto dog : dogs)
    {
        if (dog.getPhotoLink() != "")
        {
            ui.shoppingBasketList->addItem(QString::fromStdString(dog.toString()));
        }
    }
}

void gui::handleAddDog()
{
    Dog dog;
    int age;
    string breed, name, link;
    QString sstring = ui.colourLineEdit->text();
    if (sstring.isEmpty())
    {

        return;
    }
    else
    {
        breed = sstring.toStdString();
    }
    sstring = ui.priceLineEdit->text();
    if (sstring.isEmpty())
    {
        return;
    }
    else
    {
        name = sstring.toStdString();
    }
    sstring = ui.quantityLineEdit->text();
    if (sstring.isEmpty())
    {
        return;
    }
    else
    {
        age = sstring.toInt();
    }
    sstring = ui.linkLineEdit->text();
    if (sstring.isEmpty())
    {
        return;
    }
    else
    {
        link = sstring.toStdString();
    }

    dog = { breed,name,age,link };
    try
    {
        this->service.addDog(dog);
        QMessageBox::information(this, "Added successfully", "Dog added successfully", QMessageBox::Ok);
        ui.colourLineEdit->clear();
        ui.priceLineEdit->clear();
        ui.quantityLineEdit->clear();
        ui.linkLineEdit->clear();
        this->handleDisplay();
    }
    catch (DogException& ex)
    {
        //QMessageBox::information(this, "Error", ex.message().c_str(), QMessageBox::Ok);
    }

}

void gui::handleDeleteDog()
{
    QString sstring = ui.linkLineEdit->text();
    if (sstring.isEmpty())
    {
        //QMessageBox::information(this, "Error", "Link field is empty", QMessageBox::Ok);
        return;
    }
    try
    {
        this->service.removeDog(sstring.toStdString());
        //QMessageBox::information(this, "Deleted successfully", "Trench was deleted successfully", QMessageBox::Ok);
        ui.linkLineEdit->clear();
        this->handleDisplay();
    }
    catch (DogException& ex)
    {
        //QMessageBox::information(this, "Error", ex.message().c_str(), QMessageBox::Ok);
    }
}

void gui::handleUpdateDog()
{
    QString sstring = ui.linkLineEdit->text();
    if (sstring.isEmpty())
    {
        //QMessageBox::information(this, "Error", "Link field is empty", QMessageBox::Ok);
        return;
    }

    string link = sstring.toStdString();
    string succesMessage = "Updated successfully ";
    string errorMessage = "Not updated ";
    int succes = 0, errors = 0;

    Dog currentDog = this->service.findDogByLink(link);
    string new_breed = currentDog.getBreed();
    string new_name = currentDog.getName();
    int new_age = currentDog.getAge();
    string new_link = currentDog.getPhotoLink();


    sstring = ui.colourLineEdit->text();
    if (!sstring.isEmpty())
    {
        new_breed = sstring.toStdString();
    }

    sstring = ui.priceLineEdit->text();
    if (!sstring.isEmpty())
    {
        new_name = sstring.toStdString();
    }

    sstring = ui.quantityLineEdit->text();
    if (!sstring.isEmpty())
    {
        new_age = sstring.toInt();
    }

    try
    {
        this->service.updateDog(link, new_breed, new_name, new_age, new_link);
        //QMessageBox::information(this, "Success", "Update done", QMessageBox::Ok);
        this->handleDisplay();
    }
    catch (DogException& ex)
    {
        //QMessageBox::information(this, "Error",ex.message().c_str(), QMessageBox::Ok);
    }
}

void gui::handleSeeImage()
{
    if (ui.shoppingBasketList->selectedItems().size() > 0)
    {
        string obj = ui.shoppingBasketList->currentItem()->text().toStdString();
        vector<string> atr = tokenize(obj, ',');
        string link = "start " + atr[3];
        system(link.c_str());
    }
}

void gui::handleAddToList()
{
    string obj = ui.shoppingBasketList->currentItem()->text().toStdString();
    vector<string> atr = tokenize(obj, ',');
    Dog dog{ atr[0], atr[1], stoi(atr[2]), atr[3] };
    int data_option = ui.savingOptionBox->currentIndex();
    this->service.addDogToList(dog, this->service.getDataOption());
    //QMessageBox::information(this, "Added to list", "Added to list successfully!", QMessageBox::Ok);
}

void gui::handleShowList()
{
    if (this->service.getDataOption() == 1)
    {
        system("start list.csv");
    }
    else
    {
        system("start list.html");
    }
}