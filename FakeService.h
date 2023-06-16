#pragma once
#include "DogRepositoryFiles.h"


class FakeRepository : public DogRepoFiles
{

public:
    FakeRepository();

    Dog findDogByLink(string link) override;

};