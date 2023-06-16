#pragma once

#include <QtWidgets/QMainWindow>
#include <QMainWindow>
#include "ui_gui.h"
#include "DogService.h"

class gui : public QMainWindow
{
    Q_OBJECT

public:
    gui(DogService service, QWidget *parent = nullptr);
    ~gui();

private:
    Ui::guiClass ui;
    DogService service;
private slots:
    void handleDisplay();
    void handleShowInternalList();
    void handleStartUser();
    void handleAddDog();
    void handleDeleteDog();
    void handleUpdateDog();
    void handleSeeImage();
    void handleAddToList();
    void handleShowList();
};
