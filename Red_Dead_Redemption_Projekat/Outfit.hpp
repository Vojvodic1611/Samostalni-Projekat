#include <iostream>
#include "Dinstring.hpp"
#ifndef OUTFIT_HPP_INCLUDED
#define OUTFIT_HPP_INCLUDED

enum outfitPart {HAT = 1, VEST, SHIRT, PANTS, SHOES};

class Outfit{
private:
    outfitPart type;
    DinString name;
public:
    Outfit(){
        type = HAT;
        name = "Beautiful hat";
    }
    Outfit(outfitPart a, DinString b){
        type = a;
        name = b;
    }
    outfitPart getOutfitType()const{
        return type;
    }
    DinString getOutfitName()const{
        return name;
    }
    void setOutfitType(const outfitPart O){
        type = O;
    }
    void setOutfitName(const DinString N){
        name = N;
    }

    friend ostream& operator<<(ostream&out, Outfit &O){
        int temp = O.getOutfitType();
        switch(temp){
            case 1: out << "Outfit Part : HAT" << endl; break;
            case 2: out << "Outfit Part : VEST" << endl; break;
            case 3: out << "Outfit Part : SHIRT" << endl; break;
            case 4: out << "Outfit Part : PANTS" << endl; break;
            case 5: out << "Outfit Part : SHOES" << endl; break;
            default : out << "Outfit Part : HAT" << endl; break;
        }
        out << "Name : " << O.getOutfitName() << endl;


        return out;
    }
};

#endif // OUTFIT_HPP_INCLUDED
