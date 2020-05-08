#include <iostream>
#ifndef BEING_HPP_INCLUDED
#define BEING_HPP_INCLUDED
#include "Consumables.hpp"
#include "List.hpp"

class Being{
protected:
    int hp;
    int stamina;
    List <Consumables> consumables;
public:
    void operator~(){
        ~Being();
    }
    Being(){
        hp = 100;
        stamina = 100;
        consumables.add(1, Consumables());
    }
    Being(int a, int b, List <Consumables> C){
        hp = a;
        stamina = b;
        consumables = C;
    }
    Being(Being &B){
        hp = B.hp;
        stamina = B.stamina;
        consumables = B.consumables;
    }

    void kill(){
        hp = 0;
        stamina = 0;
        ~Being();
    }
    int getHP()const{
        return hp;
    }
    int getST()const{
        return stamina;
    }
    List <Consumables> getListConsumables()const{
        return consumables;
    }
    void setHP(const int H){
        hp = H;
    }
    void setST(const int S){
        stamina = S;
    }
    void setConsumables(const List <Consumables> C){
        consumables = C;
    }
    void Loot(){
        consumables.empty();
    }

};

#endif // BEING_HPP_INCLUDED
