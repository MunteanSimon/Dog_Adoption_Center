#include "DogRepository.h"
#include <cstdlib>
#include <iostream>

DogRepository::DogRepository()
    :repo_vector(), adoption_list(), data_option()
{

}

int DogRepository::setup_data()
{
    Dog dog1{ "ciobanesc", "max", 5, "https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.taramulanimalelor.com%2Fcaini%2Fcum-sa-alegi-un-pui-de-ciobanesc-german%2F&psig=AOvVaw0W2oPIfUhdjLt26NpfoqmO&ust=1649680073560000&source=images&cd=vfe&ved=0CAoQjRxqFwoTCMj0mrW_ifcCFQAAAAAdAAAAABAD" };
    Dog dog2{ "husky", "rex", 7, "https://www.google.com/url?sa=i&url=https%3A%2F%2Fbucuriacasei.ro%2Fhusky-siberian-de-vanzare%2F&psig=AOvVaw2bEN1Ygtg4UlxlrbbnoFIq&ust=1649680153873000&source=images&cd=vfe&ved=0CAoQjRxqFwoTCKC59c2_ifcCFQAAAAAdAAAAABAE" };
    Dog dog3{ "chihuahua", "albert", 15, "https://www.google.com/imgres?imgurl=http%3A%2F%2Fbazavan.ro%2Fwp-content%2Fuploads%2F2022%2F01%2FChihuahua-....jpg&imgrefurl=http%3A%2F%2Fbazavan.ro%2F2022%2F01%2Fde-ce-nu-citesc-comentariile-din-social-media-teoria-cu-chihuahua-care-latra%2F&tbnid=zjh1u2vX_QwsWM&vet=12ahUKEwiwkNLbv4n3AhUMuKQKHf2YCggQMygHegUIARDIAQ..i&docid=hEqq-12n6kOYVM&w=2000&h=1333&q=chihuahua&ved=2ahUKEwiwkNLbv4n3AhUMuKQKHf2YCggQMygHegUIARDIAQ" };
    Dog dog4{ "akita", "chris", 20, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fupload.wikimedia.org%2Fwikipedia%2Fcommons%2Fthumb%2Fa%2Fa7%2FAkita_Inu_dog.jpg%2F1200px-Akita_Inu_dog.jpg&imgrefurl=https%3A%2F%2Fro.wikipedia.org%2Fwiki%2FAkita_Inu&tbnid=pMrfEPGjOCezXM&vet=12ahUKEwj-vdKKwYn3AhUIOewKHX2ACkUQMygAegUIARC4AQ..i&docid=wRSql48lAZzkOM&w=1200&h=801&q=akita&ved=2ahUKEwj-vdKKwYn3AhUIOewKHX2ACkUQMygAegUIARC4AQ" };
    Dog dog5{ "bulldog", "charles", 18, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.akc.org%2Fwp-content%2Fuploads%2F2017%2F11%2FBulldog-standing-in-the-grass.jpg&imgrefurl=https%3A%2F%2Fwww.akc.org%2Fdog-breeds%2Fbulldog%2F&tbnid=C9fl2GfPDpaGVM&vet=12ahUKEwjD-9ySwYn3AhWOm6QKHbcMDPUQMygAegUIARDAAQ..i&docid=ISExTh4czljBKM&w=729&h=486&q=bulldog&ved=2ahUKEwjD-9ySwYn3AhWOm6QKHbcMDPUQMygAegUIARDAAQ" };
    Dog dog6{ "golden retriever", "carlos", 35, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.megapet.ro%2Fcontinut%2Fupload%2F%2FGolden-Retriever.jpg&imgrefurl=https%3A%2F%2Fwww.megapet.ro%2Fblog%2Fcaini%2Fsugestii-si-idei%2Fstii-cum-sa-alegi-hrana-potrivita-pentru-golden-retreiver-aici-iti-explicam%2F&tbnid=te7nmJFkZcin2M&vet=12ahUKEwid06GnwYn3AhUXtqQKHWzxCckQMygBegUIARDGAQ..i&docid=RPlgwSNbC0wNLM&w=1200&h=797&q=golden%20retriever&ved=2ahUKEwid06GnwYn3AhUXtqQKHWzxCckQMygBegUIARDGAQ" };
    Dog dog7{ "labrador", "remus", 26, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fstatic.impact.ro%2Funsafe%2F970x546%2Fsmart%2Ffilters%3Acontrast(5)%3Aformat(webp)%3Aquality(90)%2Fhttps%3A%2F%2Fwww.impact.ro%2Fwp-content%2Fuploads%2F2020%2F05%2FC%25C3%25A2t-cost%25C4%2583-de-fapt-un-labrador-cu-pedigree-%25C3%25AEn-Rom%25C3%25A2nia-1024x675.jpg&imgrefurl=https%3A%2F%2Fwww.impact.ro%2Fcat-costa-de-fapt-un-labrador-cu-pedigree-in-romania-40659.html&tbnid=6_0-18xb6-XzlM&vet=12ahUKEwiri9S0wYn3AhVpwAIHHR41BwoQMygCegUIARC7AQ..i&docid=TiJTDwrtTIBaQM&w=970&h=546&q=labrador&ved=2ahUKEwiri9S0wYn3AhVpwAIHHR41BwoQMygCegUIARC7AQ" };
    Dog dog8{ "boxer", "sebastian", 29, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.purina.ro%2Fsites%2Fdefault%2Ffiles%2Fstyles%2Fnppe_breed_selector_500%2Fpublic%2Fbreed_library%2Fboxer.jpg%3Fitok%3DlMJkx-bH&imgrefurl=https%3A%2F%2Fwww.purina.ro%2Fcaini%2Frase-de-caini%2Fboxer&tbnid=d8EcY3kiw8vQSM&vet=12ahUKEwiV-4_BwYn3AhXThaQKHTVxCdUQMygAegUIARDAAQ..i&docid=AzShOidLp1UjEM&w=500&h=473&q=boxer&ved=2ahUKEwiV-4_BwYn3AhXThaQKHTVxCdUQMygAegUIARDAAQ" };
    Dog dog9{ "pomeranian", "lewis", 32, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.cutzucutzu.com%2Fwp-content%2Fuploads%2F2020%2F05%2Fpui-de-pomeranian-scaled.jpg&imgrefurl=https%3A%2F%2Fwww.cutzucutzu.com%2Frase-caini%2Fcat-costa-un-pomeranian%2F&tbnid=FXAcqo0iEDOVyM&vet=12ahUKEwiO4LvLwYn3AhWNmKQKHU3ABdgQMygCegUIARDDAQ..i&docid=GiRGFPdlswsZXM&w=1150&h=689&q=pomeranian&ved=2ahUKEwiO4LvLwYn3AhWNmKQKHU3ABdgQMygCegUIARDDAQ" };
    Dog dog10{ "beagle", "george", 22, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.zooplus.ro%2Fghid%2Fwp-content%2Fuploads%2F2021%2F07%2Fdespre-beagle-1024x682.jpg&imgrefurl=https%3A%2F%2Fwww.zooplus.ro%2Fghid%2Fcaini%2Frase-de-caini%2Fbeagle&tbnid=cl1X-fp7VxSJyM&vet=12ahUKEwj-ptfSwYn3AhWJG-wKHSC1BMQQMygBegUIARDDAQ..i&docid=y6P7Z3Fx3FWc4M&w=1024&h=682&q=beagle&ved=2ahUKEwj-ptfSwYn3AhWJG-wKHSC1BMQQMygBegUIARDDAQ" };
    this->repo_vector.push_back(dog1);
    this->repo_vector.push_back(dog2);
    this->repo_vector.push_back(dog3);
    this->repo_vector.push_back(dog4);
    this->repo_vector.push_back(dog5);
    this->repo_vector.push_back(dog6);
    this->repo_vector.push_back(dog7);
    this->repo_vector.push_back(dog8);
    this->repo_vector.push_back(dog9);
    this->repo_vector.push_back(dog10);
    return 0;
}

int DogRepository::getDataOption() {
    return this->data_option;
}

void DogRepository::setDataOption(int data) {
    this->data_option = data;
}

class checkLink
{
private:
    string _link;
public:
    checkLink(string link) : _link(link) {}

    bool operator()(Dog dog)
    {
        return this->_link == dog.getPhotoLink();
    }
};

Dog DogRepository::findDogByLink(string link)
{
    vector<Dog>::iterator it = find_if(this->repo_vector.begin(), this->repo_vector.end(), checkLink(link));
    if (it != this->repo_vector.end())
    {
        return *it;
    }
    return Dog();
}

void DogRepository::addDog(const Dog& new_dog)
{
    this->repo_vector.push_back(new_dog);
}

void DogRepository::removeDog(string link)
{
    Dog dog;
    int len = this->repo_vector.size();
    int position_to_delete = 0;
    for (int i = 0; i < len; i++)
    {
        dog = this->repo_vector[i];
        if (dog.getPhotoLink() == link)
        {
            position_to_delete = i;
            break;
        }
    }
    this->repo_vector.erase(repo_vector.begin() + position_to_delete);
}

void DogRepository::updateDog(string link, const Dog& newDog)
{
    int len = this->repo_vector.size();
    for (int i = 0; i < len; i++)
    {
        if (repo_vector[i].getPhotoLink() == link)
        {
            repo_vector[i] = newDog;
            return;
        }
    }
}
vector<Dog> DogRepository::getAll()
{
    vector<Dog> copy_repo_vector = this->repo_vector;
    return copy_repo_vector;
}

int DogRepository::getLength()
{
    return this->repo_vector.size();
}

vector<Dog> DogRepository::getAdoptionList()
{
    vector<Dog> copy_adoption_list = this->adoption_list;
    return copy_adoption_list;
}

void DogRepository::addDogToList(Dog new_dog)
{
    this->adoption_list.push_back(new_dog);
}

string DogRepoException::message() {
    return this->exception;
}

DogRepository::~DogRepository() = default;