#ifndef HORSE_HPP_INCLUDED
#define HORSE_HPP_INCLUDED
#include "Interactions.hpp"
#include "List.hpp"
#include "Animal.hpp"

class Horse : public Animal{
private:
    List <Interactions> interactions;
    List <Weapon> weapons;
public:
    Horse() : Animal(){
        interactions.add(1, Interactions());
        interactions.add(2, Interactions());
        interactions.add(3, Interactions());
        weapons.add(1, Weapon());
    }
    Horse(List <Interactions> I, List <Weapon> W, bool a, bool b, int p, int q, List <Consumables> R) : Animal(a, b, p, q , R){
        if (a){
            a = false;
        }
        if (b){
            b = false;
        }
        interactions = I;
        weapons = W;
    }
    void pet_horse(){
        hp += 10;
        stamina += 10;
    }
    List <Interactions> getHorseInteractions()const{
        return interactions;
    }
    List <Weapon> getHorseWeapons()const{
        return weapons;
    }
    void setHorseInteractions(const List <Interactions> I){
        interactions = I;
    }
    void setHorseWeapons(const List <Weapon> W){
        weapons = W;
    }
    void writeHorseWeapons(){
        if(weapons.size() == 0){
            cout << "Horse has no weapons!" << endl;
        }
        else{
            Weapon W;
            int i;
            for (i = 1; i <= weapons.size(); ++i){
                weapons.read(i, W);
                cout << W << endl;
            }
        }
    }
    void writeHorseInteractions(){
        if(interactions.size() == 0){
            cout << "Horse has no interactions!" << endl;
        }
        else{
            Interactions I;
            int i;
            for (i = 1; i <= interactions.size(); ++i){
                interactions.read(i, I);
                cout << I << endl;
            }
        }
    }
    friend ostream& operator << (ostream&out, Horse &H){
        H.writeHorseWeapons();
        H.writeHorseInteractions();
        return out;
    }

};


#endif // HORSE_HPP_INCLUDED
