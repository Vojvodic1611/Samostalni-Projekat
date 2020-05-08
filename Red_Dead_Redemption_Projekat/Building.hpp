#ifndef BUILDING_HPP_INCLUDED
#define BUILDING_HPP_INCLUDED
#include <iostream>
#include "Dinstring.hpp"
#include "NPC.hpp"
#include "List.hpp"

enum BuildingType {PUB = 1, HOTEL, STABLE, GENERAL_STORE};

class Building{
private:
    BuildingType type;
    DinString Name;
    List <NPC> npc;
public:
    Building(){
        type = PUB;
        Name = "Random PUB";
        npc.add(1, NPC());
    }
    Building(BuildingType a, DinString b, List<NPC> c){
        type = a;
        Name = b;
        npc = c;
    }
    BuildingType getBuildingType()const{
        return type;
    }
    DinString getBuildingName()const{
        return Name;
    }
    List <NPC> getBuildingNPC()const{
        return npc;
    }
    void setBuildingType(const BuildingType T){
        type = T;
    }
    void setBuildingName(const DinString n){
        Name = n;
    }
    void setBuildingNPC(const List <NPC> N){
        npc =N;
    }
    void writeBuildingNPCs(){
        if(npc.size() == 0){
            cout << "There are no NPCs in this building!" << endl;
        }
        else{
            int i;
            NPC N;
            for(i = 1; i <= npc.size(); ++i){
                npc.read(i, N);
                cout << N << endl;
            }
        }
    }
    friend ostream& operator << (ostream&out, Building &B){
        out << "Buidling type : " << B.getBuildingType() << endl;
        out << "Buidling name : " << B.getBuildingName() << endl;
        B.writeBuildingNPCs();

        return out;
    }
};

#endif // BUILDING_HPP_INCLUDED
