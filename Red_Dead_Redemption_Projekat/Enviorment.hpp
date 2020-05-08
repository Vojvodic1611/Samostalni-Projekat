#include <iostream>
#include "List.hpp"
#include "Animal.hpp"
#ifndef ENVIORMENT_HPP_INCLUDED
#define ENVIORMENT_HPP_INCLUDED

class Enviorment{
private:
    int temperature;
    List <Animal> animals;
public:
    Enviorment(){
        temperature = 20;
        animals.add(1, Animal());
        animals.add(2, Animal());
    }
    Enviorment(int t, List <Animal> A){
        temperature = t;
        animals = A;
    }
    int getTemperature()const{
        return temperature;
    }
    List <Animal> getEnviormentAnimals()const{
        return animals;
    }
    void setTemperature(const int T){
        temperature = T;
    }
    void setEnviormentAnimals(const List <Animal> A){
        animals = A;
    }
    void writeEnviormentAnimals(){
        if(animals.size() == 0){
            cout << "No animals in this enviorment!" << endl;
        }
        else{
            Animal A;
            int i;
            for(i = 1; i <= animals.size(); ++i){
                animals.read(i, A);
                cout << A << endl;
            }
        }
    }
    friend ostream& operator << (ostream&out, Enviorment &E){
        E.writeEnviormentAnimals();
        out << "Enviorment temperature : " << E.getTemperature() << endl;
        return out;
    }
};

#endif // ENVIORMENT_HPP_INCLUDED
