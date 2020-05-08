#include <iostream>
#include "List.hpp"
#include "Building.hpp"
#include "Weapon.hpp"
#include "Consumables.hpp"
#include "Interactions.hpp"
#ifndef SHOP_HPP_INCLUDED
#define SHOP_HPP_INCLUDED

class Shop : Building{
private:
    List <Weapon> weapons;
    List <Consumables> consumables;
    List <Interactions> interactions;
public:
    Shop() : Building(){
        weapons.add(1, Weapon());
        weapons.add(1, Weapon());
        weapons.add(1, Weapon());
        consumables.add(1, Consumables());
        consumables.add(1, Consumables());
        consumables.add(1, Consumables());
        interactions.add(1, Interactions());
        interactions.add(2, Interactions());
    }
    Shop(List <Weapon> W, List <Consumables> C, List <Interactions> I, BuildingType a, DinString b, List <NPC> c) : Building(a, b, c){
        weapons = W;
        consumables = C;
        interactions = I;
    }
    void sell_weapon(int n){
        weapons.remove(n);
    }
    void sell_consumable(int n){
        consumables.remove(n);
    }
    List <Weapon> getShopWeapons()const{
        return weapons;
    }
    List <Consumables> getShopConsumables()const{
        return consumables;
    }
    List <Interactions> getShopInteractions()const{
        return interactions;
    }
    void setShopWeapons(const List <Weapon> W){
        weapons = W;
    }
    void setShopConsumables(const List <Consumables> C){
        consumables = C;
    }
    void setShopInteractions(const List <Interactions> I){
        interactions = I;
    }
    void writeShopInteractions(){
        if(interactions.size() == 0){
            cout << "No interactions!" << endl;
        }
        else{
            int i;
            Interactions I;
            for (i = 1; i <= interactions.size(); ++i){
                interactions.read(1, I);
                cout<< I << endl;
            }
        }
    }
    void writeShopWeapons(){
        if(weapons.size() == 0){
            cout << "No weapons!" << endl;
        }
        else{
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << "Weapons : " << endl;
            Weapon W;
            int i;
            for (i = 0; i <= weapons.size(); ++i){
                weapons.read(i, W);
                cout << W << endl;
            }
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << endl;
            cout << endl;
        }
    }
    void writeShopConsumables(){
        if(consumables.size() == 0){
            cout << "No Consumables!" << endl;
        }
        else{
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << "Consumables : " << endl;
            Consumables C;
            int i;
            for (i = 0; i <= consumables.size(); ++i){
                consumables.read(i, C);
                cout << C << endl;
            }
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << endl;
            cout << endl;
        }
    }
    friend ostream& operator << (ostream&out, Shop &S){
        S.writeShopWeapons();
        S.writeShopConsumables();
        S.writeShopInteractions();
        return out;
    }
};

#endif // SHOP_HPP_INCLUDED
