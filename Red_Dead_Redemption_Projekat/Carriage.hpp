#include <iostream>
#include "List.hpp"
#include "Horse.hpp"
#include "Consumables.hpp"
#ifndef CARRIAGE_HPP_INCLUDED
#define CARRIAGE_HPP_INCLUDED

class Carriage{
private:
    List <Horse> horses;
    List <Consumables> consumables;
public:
    Carriage(){
        horses.add(1, Horse());
        consumables.add(1, Consumables());
        consumables.add(2, Consumables());
    }
    Carriage(List <Horse> H, List <Consumables> C){
        horses = H;
        consumables = C;
    }
    List <Horse> getCarriageHorses()const{
        return horses;
    }
    List <Consumables> getCarriageConsumables()const{
        return consumables;
    }
    void setCarriageHorses(const List <Horse> H){
        horses = H;
    }
    void setCarriageConsumables(const List <Consumables> C){
        consumables = C;
    }
    void writeCarriageHorses(){
        if(horses.size() == 0){
            cout << "No horses on the carriage!" << endl;
        }
        else{
            Horse H;
            int i;
            for (i = 1; i <= horses.size(); ++i){
                horses.read(1, H);
                cout << H << endl;
            }
        }
    }
    void writeCarriageConsumables(){
        if(consumables.size() == 0){
            cout << "No consumables on the carriage!" << endl;
        }
        else{
            Consumables C;
            int i;
            for (i = 1; i <= consumables.size(); ++i){
                consumables.read(1, C);
                cout << C << endl;
            }
        }
    }
    friend ostream& operator << (ostream&out, Carriage &C){
        C.writeCarriageConsumables();
        C.writeCarriageHorses();
        return out;
    }
};

#endif // CARRIAGE_HPP_INCLUDED
