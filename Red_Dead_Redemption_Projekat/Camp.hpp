#include <iostream>
#include "List.hpp"
#include "Tent.hpp"
#include "Dinstring.hpp"
#ifndef CAMP_HPP_INCLUDED
#define CAMP_HPP_INCLUDED

class Camp{
private:
    DinString LocationName;
    List <Tent> tents;
public:
    Camp(){
        LocationName = "Horseshoe Overlook";
        tents.add(1, Tent());
        tents.add(2, Tent());
        tents.add(3, Tent());
    }
    Camp(DinString name1, List <Tent> T){
        LocationName = name1;
        tents = T;
    }
    DinString getCampLocationName()const{
        return LocationName;
    }
    List <Tent> getCampTents()const{
        return tents;
    }
    void setCampLocationName(const DinString N){
        LocationName = N;
    }
    void setCampTents(const List <Tent> T){
        tents = T;
    }
    void writeCampTents(){
        if(tents.size() == 0){
            cout << "There are no tents in the camp!" << endl;
        }
        else{
            Tent T;
            int i;
            for(i = 1; i <= tents.size(); ++i){
                tents.read(1, T);
                cout << T << endl;
            }
        }
    }
    friend ostream& operator << (ostream&out, Camp &C){
        out << "Camp location name : " << C.getCampLocationName() << endl;
        C.writeCampTents();
        return out;
    }
};

#endif // CAMP_HPP_INCLUDED
