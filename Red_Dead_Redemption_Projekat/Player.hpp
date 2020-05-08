#include <iostream>
#include "List.hpp"
#include "Actions.hpp"
#include "Character.hpp"
#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

class Player : public Character{
private:
    int LvL;
    List <Action> actions;
    bool smelly;//ovo postoji zato sto u igrici bukvalno ima mogucnost da se kupate i onda ako se ne kupate dovoljno dugo ljudi pored kojih prolazite komentarisu kako smrdite i meni je to bilo interesantno
public:
    Player() : Character(){
        LvL = 0;
        smelly = false;
        actions.add(1, Action());
    }
    Player(int a, bool b, List <Action> A, List <Dialogue> k, List <Weapon> l, List <Outfit> D, int p, int q, List <Consumables> C) : Character( k, l , D, p ,q , C ){
        LvL = a;
        smelly = b;
        actions = A;
    }
    bool addAction(Action &A){
        return actions.add(actions.size()+1, A);

    }
    void writeActions(){
        if(actions.size() == 0){
            cout << "No Actions!" << endl;
        }
        else{
            Action A;
            int i;
            for(i = 1; i <= actions.size(); ++i){
                actions.read(i, A);
                cout << A << endl;
            }
        }
    }
    void Player_LvL_UP(){
        LvL += 1;
    }
    bool Shower(){
        if(smelly){
            return false;
        }
        else{
            return true;
        }
    }
    void Dobro_delo(){
        int a = actions.size();
        actions.add(a+1, Action("Dobro delo", 10));
    }
    void Lose_delo(){
        int a = actions.size();
        actions.add(a+1, Action("Lose delo", -10));
    }
    void Buy_Weapon(Weapon W){
        int a = weapons.size();
        weapons.add(a + 1, W);
    }

    int getPlayerLVL()const{
        return LvL;
    }

    List <Action> getPlayerActions(){
        return actions;
    }
    bool getPlayerSmelly()const{
        return smelly;
    }
    void setPlayerLvL(const int L){
        LvL = L;
    }

    void setPlayerActions(const List <Action> A){
        actions = A;
    }
    void setPlayerSmelly(const bool S){
        smelly = S;
    }

    friend ostream& operator <<(ostream&out, Player& p){
        out << "PLAYER : " << endl;
        out << "-----------" << endl;
        out << "Player Level = "<< p.getPlayerLVL()<< endl;
        out << "Player is smelly = ";
        if(p.getPlayerSmelly()){
            out << "Yes he is!" << endl;
        }
        out << "No he is not!" << endl;
        p.writeActions();
        p.writeCharacterWeapons();
        p.writeCharacterDialogue();
        p.writeCharacterOutfit();
        out << "-----------" << endl;
        out << "-----------" << endl;
        out <<endl;
        return out;
    }

    friend bool operator==(Player &P1, Player &P2){
        if(P1.getPlayerLVL() != P2.getPlayerLVL() ||  P1.getPlayerSmelly() != P2.getPlayerSmelly()){
            return false;
        }
        else {
            return true;
        }
    }

    friend bool operator<(Player &P1, Player &P2){
        if(P1.getPlayerLVL() < P2.getPlayerLVL()){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator>(Player &P1, Player &P2){
        if(P1.getPlayerLVL() > P2.getPlayerLVL()){
            return true;
        }
        else{
            return false;
        }
    }
    friend bool operator!=(Player &P1, Player &P2){
        if(P1.getPlayerLVL() != P2.getPlayerLVL() ||  P1.getPlayerSmelly() != P2.getPlayerSmelly()){
            return true;
        }
        else {
            return false;
        }
    }


};


#endif // PLAYER_HPP_INCLUDED
