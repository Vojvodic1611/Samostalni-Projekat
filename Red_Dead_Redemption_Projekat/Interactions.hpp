#include <iostream>
#include "List.hpp"
#include "Dialogue.hpp"
#ifndef INTERACTIONS_HPP_INCLUDED
#define INTERACTIONS_HPP_INCLUDED

enum InteractionType{GREETING = 1, ANTAGONIZATION, ROBBERY, CUSTOM};

class Interactions{
private:
    InteractionType type;
    Dialogue Possible_Dialogue;
public:
    Interactions(){
        type = GREETING;
        Dialogue HELP("Hey there mister!");

    }
    Interactions(InteractionType a, Dialogue b){
        type = a;
        Possible_Dialogue = b;
    }
    Interactions(Interactions &I){
        type = I.type;
        Possible_Dialogue = I.Possible_Dialogue;
    }
    InteractionType getInteractionType()const{
        return type;
    }
    void setInteractionType(const InteractionType I){
        type = I;
    }
    DinString getInteractionDialogue()const{
        return Possible_Dialogue.getDialogue();
    }
    friend ostream& operator << (ostream&out, Interactions &I){
        out << "Interaction type : " << I.getInteractionType() << endl;
        out << "Interaction dialogue : " << I.getInteractionDialogue() << endl;
        return out;
    }
};

#endif // INTERACTIONS_HPP_INCLUDED
