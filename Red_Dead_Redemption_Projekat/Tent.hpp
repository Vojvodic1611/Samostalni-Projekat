#include <iostream>
#include "NPC.hpp"
#ifndef TENT_HPP_INCLUDED
#define TENT_HPP_INCLUDED

class Tent{
private:
    int level;
    NPC owner;
public:
    Tent(){
        level = 1;
        owner = NPC();
    }
    Tent(int i, NPC bojan){
        level = i;
        owner = bojan;
    }
    int getTentLVL()const{
        return level;
    }
    NPC getTentOwner(){
        return owner;
    }
    DinString getOwnerName()const{
        return owner.getNPCName();
    }
    friend ostream& operator << (ostream&out, Tent &T){
        out << "Tent LeveL = " << T.getTentLVL()<< endl;
        out << "Tent Owner = " << T.getOwnerName() << endl;
        return out;
    }
};

#endif // TENT_HPP_INCLUDED
