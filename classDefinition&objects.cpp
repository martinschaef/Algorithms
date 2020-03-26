#include <string> // enable program to use C++ string data type
#include <iostream>
using namespace std;

#ifndef PARASITE_H
#define PARASITE_H

class Parasite {
    
    float reproductionRate; // rate of reproduction, in %
    float resistance;       // resistance against drugs, in %
    
public:
    Parasite(float newReproductionRate, float newResistance);
    
    float getReproductionRate();
    float getResistance();    
    
    Parasite* reproduce(float immunity);
    bool survive(float immunity);        
};

#endif



#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
    
    float immunity;       // degree of immunity, in %
    unsigned int numParasiteCells; // number of parasites   

public:
    Animal(float initImmunity, int initNumViruses);

    float getImmunity();
    int getParasiteNumber();
    
    void takeDrug();    
};

#endif



Parasite::Parasite(float newReproductionRate, float newResistance) {
    reproductionRate = newReproductionRate;
    resistance = newResistance;
    cout << "Parasite is born with " << reproductionRate*100 << "% reproduction rate, and "
         << resistance*100 << "% resistance" << endl;
}
Define access methods for encapsulated fileds
float Parasite::getReproductionRate(){
    return reproductionRate;
}
float Parasite::getResistance(){
    return resistance;
}

Animal::Animal(float initImmunity, int initNumParasiteCells) :
                 numParasiteCells(initNumParasiteCells), immunity(initImmunity)
{
    cout << "Animal has " << numParasiteCells << " parasites, and "
         << immunity*100 << "% immunity" << endl;
}
Define access methods for encapsulated fileds
float Animal::getImmunity(){
    return immunity;
}
int Animal::getParasiteNumber(){
    return numParasiteCells;
}
{
    // Create a parasite with 10% reporoduction and 20% resistance rate
    Parasite p{0.1, 0.2};
    // Create an animal with 30% immunity rate and 10 parasites
    Animal a{0.3, 10};
    
    cout << "This parasite has reporoduction rate: " << p.getReproductionRate()*100
         << "%, and resistance rate: " << p.getResistance()*100 << endl;
    
    cout << "This animal has immunity rate: " << a.getImmunity()*100
         << "%, and " << a.getParasiteNumber() << " parasites"<< endl;
}
    
    
    
    
    

#ifndef PARASITE_H
#define PARASITE_H

class Parasite {
    
    float reproductionRate; // rate of reproduction, in %
    float resistance;       // resistance against drugs, in %
    
public:
    Parasite(float newReproductionRate, float newResistance);
    
    float getReproductionRate();
    float getResistance();    
    
    Parasite* reproduce(float immunity);
    bool survive(float immunity);        
};

#endif
Parasite.cpp
#include "Parasite.h"
#include <iostream>
using namespace std;

Parasite::Parasite(float newReproductionRate, float newResistance) {
    reproductionRate = newReproductionRate;
    resistance = newResistance;
    cout << "Parasite is born with " << reproductionRate*100 << "% reproduction rate, and "
         << resistance*100 << "% resistance" << endl;
}

float Parasite::getReproductionRate(){
    return reproductionRate;
}

float Parasite::getResistance(){
    return resistance;
}
Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
    
    float immunity;       // degree of immunity, in %
    unsigned int numParasiteCells; // number of parasites   

public:
    Animal(float initImmunity, int initNumViruses);

    float getImmunity();
    int getParasiteNumber();
    
    void takeDrug();    
};

#endif
Animal.cpp
#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal(float initImmunity, int initNumParasiteCells) :
                 numParasiteCells(initNumParasiteCells), immunity(initImmunity)
{
    cout << "Animal has " << numParasiteCells << " parasites, and "
         << immunity*100 << "% immunity" << endl;
}

float Animal::getImmunity(){
    return immunity;
}

int Animal::getParasiteNumber(){
    return numParasiteCells;
}
Simulation.cpp
#include "Parasite.h"
#include "Animal.h"
#include <iostream>
using namespace std;

int main(){
    // Create a parasite with 10% reporoduction and 20% resistance rate
    Parasite p{0.1, 0.2};
    // Create an animal with 30% immunity rate and 10 parasites
    Animal a{0.3, 10};
    
    cout << "This parasite has reporoduction rate: " << p.getReproductionRate()*100
         << "%, and resistance rate: " << p.getResistance()*100 << endl;
    
    cout << "This animal has immunity rate: " << a.getImmunity()*100
         << "%, and " << a.getParasiteNumber() << " parasites"<< endl;

    return 0;
}
Compilation
Using GCC C++ compiler, compile and run the simulation program with following commands:

g++ -std=c++14 -o simulation Animal.cpp Parasite.cpp Simulation.cpp
./simulation
