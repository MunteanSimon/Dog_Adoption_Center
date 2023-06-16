#include "gui.h"
#include <cassert>
#include <QtWidgets/QApplication>
#include "domain.h"
#include "DogRepository.h"
#include "DogRepositoryFiles.h"
#include "DogService.h"
#include "validators.h"
#include "FakeService.h"

void testFake1()
{
    FakeRepository frepository;
    DogValidator validator;
    DogService dogService{ frepository, validator };
    Dog newDog{ "1", "2", 3, "4" };

    dogService.addDog(newDog);

    assert(frepository.getLength() >= 1);
}

void testFake2()
{
    FakeRepository frepository;
    DogValidator validator;
    DogService dogService{ frepository, validator };
    Dog existingDog{ "1", "2", 3, "4" };
    Dog newDog{ "5", "6", 7, "4" };

    frepository.addDog(existingDog);

    try {
        dogService.addDog(newDog);
        assert(false);
    }
    catch (const DogServiceException& e) {
        assert(e.what() == std::string("Duplicated Dog!\n"));
    }
}


int main(int argc, char* argv[]) {
    testFake1();
    testFake2();
    QApplication a(argc, argv);
    DogRepoFiles repo{ "d:/file_input.txt" };
    DogValidator validator;
    DogService service{ repo,validator };
    gui button{ service };
    button.show();
    return a.exec();
}
