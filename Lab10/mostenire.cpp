#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

class Bird
{
public:
    virtual void Fly() = 0 ;
    virtual void Sound() = 0;
};

class Parrot: public Bird
{
public:
    std::vector<std::string> wordsVector;

    Parrot(std::vector<std::string> wordsVector)
    : wordsVector(wordsVector)
    { };

    void virtual Fly()
    {
        std::cout<<"\nThe parrot can fly 25 Km.\n" ;
    };

    void virtual Sound()
    {
        std::cout<<"\nSound: UUUUU";
    };

    void DisplayWords()
    {
        std::cout<<"\nParrot knows to spell:"
        for (int i = 0; i <wordsVector.size(); i++) 
        {
                std::cout << wordsVector[i] << "\n";
        };
    };
};

class Chicken: public Bird
{
public:
    static int chickenCount;
    int distance;

    Chicken()
    {
        if(chickenCount >= 30) 
        {
            throw std::exception("No more chickens.");
        };
        chickenCount ++;
    };

    void virtual Fly()
    {
        if(distance < 10)
            std::cout<<"The bird is not a chicken.";
    };

    void virtual Sound()
    {
        std::cout<<"Sound::CHCH.";
    };

    void SellChicken(Bird &bird)
    {
        std::cout<<"Chicken sold.";
    };
}

class Ostrich : public Bird {
private:
    int nrOfChickens = 0;
    static Ostrich* ostrich;
    Ostrich() {};

public:
    static Ostrich* getInstance() 
    {
        if (!ostrich)
            ostrich = new Ostrich();
        return ostrich;
    };

    Ostrich& operator+(const Chicken& c) 
    {
        nrOfChickens++;
        Chicken::chickenCount--;
        
        return *this;    
    };

    void virtual Fly() 
    {
         cout << "This bird can not fly.";
    };

    void virtual Sound() 
    {
        cout << "HHFHG";
    };

    int getNrOfChickens() 
    {
        return nrOfChickens;
    };
};

int Chicken::count = 0;

int main() {
    Chicken *chicken1 = new Chicken();
    *Ostrich::getInstance() + *chicken1;

    cout << Ostrich::getInstance()->getNrOfChickens()<< "\n";
    cout << Chicken::chickenCount << "\n";

    Ostrich::getInstance()->Fly();
    Ostrich::getInstance()->Sound();
    
    std::vector<std::string> wordsVector;
    wordsVector.push_back("Ha1");
    wordsVector.push_back("ha2");
    wordsVector.push_back("HAH3");
    wordsVector.push_back("Har4");

    Parrot *parrot = new Parrot(wordsVector);
    parrot->Fly();
    parrot->Sound();
    parrot->DisplayWords();

    Chicken *chicken = new Chicken();

    chicken->SellChicken(*parrot);

    chicken->Fly();
    chicken->Sound();

    delete chicken1;

    return 0;
}