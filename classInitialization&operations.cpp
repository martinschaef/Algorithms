#include <string> // enable program to use C++ string data type
#include <iostream>
using namespace std;

#ifndef PARASITE_H
#define PARASITE_H

#include <iostream>
using namespace std;

class Parasite {

    friend ostream& operator<<(ostream&, Parasite*);

    float reproductionRate; // rate of reproduction, in %
    float resistance;       // resistance against drugs, in %

public:
    Parasite(float newReproductionRate, float newResistance);
    ~Parasite();

    float getReproductionRate();
    float getResistance();

    Parasite* reproduce(float immunity);
    bool survive(float immunity);
};

#endif

#include "Parasite.h"

Parasite::Parasite(float newReproductionRate, float newResistance) {
    reproductionRate = newReproductionRate;
    resistance = newResistance;
    cout << "Parasite is born with " << reproductionRate*100 << "% reproduction rate, and "
         << resistance*100 << "% resistance" << endl;
}

Parasite::~Parasite() {
    cout << "Parasite object is deleted" << endl;
}

float Parasite::getReproductionRate(){
    return reproductionRate;
}

float Parasite::getResistance(){
    return resistance;
}

ostream& operator<<(ostream& output, Parasite* p) {
    output << "This parasite has reporoduction rate: " << p->getReproductionRate()*100
         << "%, and resistance rate: " << p->getResistance()*100 << endl;
    return output;
}

#ifndef ANIMAL_H
#define ANIMAL_H

#include "Parasite.h"
#include <iostream>
#include <vector>
using namespace std;

class Animal {

    friend ostream& operator<<(ostream&, Animal*);

    float immunity;       // degree of immunity, in %
    vector<Parasite* > parasites; // collection of parasites

public:
    Animal(float initImmunity, int initNumViruses);
    ~Animal();

    // overloaded operator
    Parasite* operator[](int);

    float getImmunity();
    int getParasiteNumber();

    void takeDrug();
};

#endif


#include "Animal.h"

Animal::Animal(float initImmunity, int initNumParasiteCells) : immunity(initImmunity) {
    // create parasite object in the animal object
    for (int i=0; i<initNumParasiteCells; ++i)
        parasites.push_back( new Parasite{0.1, 0.1} );
    cout << "Animal object is created" << endl;
}

Animal::~Animal() {
    // delete parasite objects fromthe animal object
    for (int i=0; i<getParasiteNumber(); ++i)
        delete parasites[i];
    parasites.resize(0);
    cout << "Animal object is deleted" << endl;
}

Parasite* Animal::operator[](int i) {
    // check it index within the range
    if(i >= 0 && i < getParasiteNumber())
        return parasites[i];
    return nullptr;
}

float Animal::getImmunity() {
    return immunity;
}

int Animal::getParasiteNumber() {
    return parasites.size();
}

ostream& operator<<(ostream& output, Animal* a) {
    output << "This animal has immunity rate: " << a->getImmunity()*100
           << "%, and " << a->getParasiteNumber() << " parasites"<< endl;
    return output;
}


#include "Parasite.h"
#include "Animal.h"
#include <iostream>
using namespace std;

int main(){
    // Create an animal with 30% immunity rate and 10 parasites
    Animal* animal = new Animal{0.3, 5};

    cout << animal; // print animal object
    cout << "Animal has parasites:" << endl;
    for (int i=0; i < animal->getParasiteNumber(); i++){
        cout << (*animal)[i]; // print parasite objects
    }

    // Destroy parasite object
    delete animal;

    return 0;
}
// Compilation
// Using GCC C++ compiler, compile and run the simulation program with following commands:
// g++ -std=c++14 -o simulation Animal.cpp Parasite.cpp Simulation.cpp