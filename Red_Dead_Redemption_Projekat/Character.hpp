#include <iostream>
#include "Dialogue.hpp"
#include "Weapon.hpp"
#include "Outfit.hpp"
#include "List.hpp"
#include "Consumables.hpp"
#include "Being.hpp"
#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

class Character : public Being{
protected:
    List <Dialogue> dialogue;
    List <Weapon> weapons;
    List <Outfit> clothes;
public:
    Character() : Being(){
        dialogue.add(1, Dialogue("Howdy partner!"));
        weapons.add(1, Weapon());
        clothes.add(1, Outfit());
    }
    Character(List <Dialogue> D, List <Weapon> W, List <Outfit> O, int p, int q, List <Consumables> r) : Being(p, q, r){
        dialogue = D;
        weapons = W;
        clothes = O;
    }
    Character(Character &C, Being &B) : Being(B){

        dialogue = C.dialogue;
        weapons = C.weapons;
        clothes = C.clothes;
    }
    List <Dialogue> getCharacterDialogues()const{
        return dialogue;
    }
    List <Weapon> getCharacterWeapons()const{
        return weapons;
    }
    List <Outfit> getCharacterClothes()const{
        return clothes;
    }
    void setCharacterWeapons(const List <Weapon> W){
        weapons = W;
    }
    void setCharacterDialogues(const List <Dialogue> D){
        dialogue = D;
    }
    void setCharacterOutfit(const List <Outfit> O){
        clothes = O;
    }

    void writeCharacterWeapons(){
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
    void writeCharacterDialogue(){
        if(dialogue.size() == 0){
            cout << "No Dialogues!" << endl;
        }
        else{
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << "Dialogue : " << endl;
            Dialogue D;
            int i;
            for (i = 0; i <= dialogue.size(); ++i){
                dialogue.read(i, D);
                cout << D << endl;
            }
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << endl;
            cout << endl;
        }
    }

    void writeCharacterOutfit(){
        if(clothes.size() == 0){
            cout << "No Clothes!" << endl;
        }
        else{
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << "Clothes : " << endl;
            Outfit C;
            int i;
            for (i = 0; i <= dialogue.size(); ++i){
                clothes.read(i, C);
                cout << C << endl;
            }
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << endl;
            cout << endl;
        }
    }

};

#endif // CHARACTER_HPP_INCLUDED
