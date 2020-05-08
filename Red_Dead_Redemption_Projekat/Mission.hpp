#include <iostream>
#include "List.hpp"
#include "NPC.hpp"
#include "Weapon.hpp"
#include "Consumables.hpp"
#ifndef MISSION_HPP_INCLUDED
#define MISSION_HPP_INCLUDED

class Mission{
private:
    List <NPC> npcs;
    List <Weapon> weapon_reward;
    List <Consumables> consumable_reward;
public:
    Mission(){
        npcs.add(1, NPC());
        weapon_reward.add(1, Weapon());
        consumable_reward.add(1, Consumables());
    }

    Mission(List <NPC> N, List <Weapon> W, List <Consumables> C){
        npcs = N;
        weapon_reward = W;
        consumable_reward = C;
    }
    List <NPC> getMissionNPCs()const{
        return npcs;
    }
    List <Weapon> getMissionWeapons()const{
        return weapon_reward;
    }
    List <Consumables> getMissionConsumables()const{
        return consumable_reward;
    }
    void setMissionNPCs(const List <NPC> N){
        npcs =  N;
    }
    void setMissionWeapons(const List <Weapon> W){
        weapon_reward = W;
    }
    void setMissionConsumables(const List <Consumables> C){
        consumable_reward = C;
    }
    void writeMissionNPCs(){
        if(npcs.size() == 0){
            cout << "There are no NPCs in the game." << endl;
        }
        else{
            cout << "NPCs in the game : " << endl;
            cout << "---------------------" << endl;
            int i;
            NPC N;
            for(i = 0; i <= npcs.size(); ++i){
                npcs.read(i, N);
                cout << "NPC : " << N << endl;
            }
            cout << "---------------------" << endl;
        }
    }
    void writeMissionWeapons(){
        if(weapon_reward.size() == 0){
            cout << "No weapons!" << endl;
        }
        else{
            cout << "Weapons : " << endl;
            cout << "------------------" << endl;
            Weapon W;
            int i;
            for (i = 0; i <= weapon_reward.size(); ++i){
                weapon_reward.read(i, W);
                cout << W << endl;
            }
            cout << "------------------" << endl;
            cout << endl;
        }
    }
    void writeMissionConsumables(){
        if(consumable_reward.size() == 0){
            cout << "No consumables on the carriage!" << endl;
        }
        else{
            Consumables C;
            int i;
            for (i = 1; i <= consumable_reward.size(); ++i){
                consumable_reward.read(1, C);
                cout << C << endl;
            }
        }
    }
    friend ostream& operator << (ostream&out, Mission &M){
        M.writeMissionConsumables();
        M.writeMissionNPCs();
        M.writeMissionWeapons();
        return out;
    }
};

#endif // MISSION_HPP_INCLUDED
