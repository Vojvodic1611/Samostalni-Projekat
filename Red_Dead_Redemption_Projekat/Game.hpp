#include <iostream>
#include "Player.hpp"
#include "List.hpp"
#include "Dinstring.hpp"
#include "Town.hpp"
#include "Camp.hpp"
#include "Enviorment.hpp"
#include "Story.hpp"
#include "NPC.hpp"
#include "Carriage.hpp"
#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

class Game{
private:
    Player player;
    List <Town> towns;
    List <NPC> npcs;
    List <Camp> camps;
    List <Enviorment> enviorments;
    List <Carriage> carriages;
    Story story;
public:
    Game(){
        player = Player();
        towns.add(1, Town());
        towns.add(2, Town());
        towns.add(3, Town());
        camps.add(1, Camp());
        enviorments.add(1, Enviorment());
        enviorments.add(2, Enviorment());
        enviorments.add(3, Enviorment());
        carriages.add(1, Carriage());
        story = Story();
    }

    Game(Player p, List <Town> T, List <NPC> N, List <Camp> C, List <Enviorment> E, List <Carriage> C1, Story s){
        player = p;
        towns = T;
        npcs = N;
        camps = C;
        enviorments = E;
        carriages = C1;
        story = s;
    }

    List <Town> getGameTowns()const{
        return towns;
    }
    List <NPC> getGameNPCs()const{
        return npcs;
    }
    List <Camp> getGameCamps()const{
        return camps;
    }
    List <Carriage> getGameCarriages()const{
        return carriages;
    }

    void setGameTowns(const List <Town> T){
        towns = T;
    }
    void setGameNPCs(const List <NPC> N){
        npcs = N;
    }
    void setGameCamps(const List <Camp> C){
        camps = C;
    }
    void setGameCarriages(const List <Carriage> c){
        carriages = c;
    }
    void writeGameTowns(){
        if(towns.size() == 0){
            cout << "There are no Towns in the game." << endl;
        }
        else{
            cout << "Towns in the game : " << endl;
            cout << "---------------------" << endl;
            int i;
            Town T;
            for(i = 0; i <= towns.size(); ++i){
                towns.read(i, T);
                cout << "Town : " << T << endl;
            }
            cout << "---------------------" << endl;
        }
    }
    void writeGameNPCs(){
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
    void writeGameCamps(){
        if(camps.size() == 0){
            cout << "There are no camps in the game." << endl;
        }
        else{
            cout << "Camps in the game : " << endl;
            cout << "---------------------" << endl;
            int i;
            Camp C;
            for(i = 0; i <= camps.size(); ++i){
                camps.read(i, C);
                cout << "Camp : " << C << endl;
            }
            cout << "---------------------" << endl;
        }
    }
    void writeGameEnviorments(){
        if(enviorments.size() == 0){
            cout << "There are no enviorments in the game." << endl;
        }
        else{
            cout << "Enviorments in the game : " << endl;
            cout << "---------------------" << endl;
            int i;
            Enviorment E;
            for(i = 0; i <= enviorments.size(); ++i){
                enviorments.read(i, E);
                cout << "Enviorment : " << E << endl;
            }
            cout << "---------------------" << endl;
        }
    }
    void writeGameCarriages(){
        if(carriages.size() == 0){
            cout << "There are no carriages in the game." << endl;
        }
        else{
            cout << "Carriages in the game : " << endl;
            cout << "---------------------" << endl;
            int i;
            Carriage C;
            for(i = 0; i <= carriages.size(); ++i){
                carriages.read(i, C);
                cout << "Carriages : " << C << endl;
            }
            cout << "---------------------" << endl;
        }
    }
    friend ostream& operator << (ostream&out, Game &G){
        out << G.player << endl;
        G.writeGameCamps();
        G.writeGameCarriages();
        G.writeGameEnviorments();
        G.writeGameNPCs();
        G.writeGameTowns();
        out << G.story << endl;
        return out;
    }
};


#endif // GAME_HPP_INCLUDED
