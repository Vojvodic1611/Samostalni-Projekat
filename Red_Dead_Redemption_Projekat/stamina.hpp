#include <iostream>
#ifndef STAMINA_HPP_INCLUDED
#define STAMINA_HPP_INCLUDED

class Stamina{
private:
    int stamina;
    int MAX_stamina;
    int stamina_core;
    int MAX_stamina_core;
public:
    Stamina(){
        stamina = 100;
        MAX_stamina = 100;
        stamina_core = 100;
        MAX_stamina_core = 100;
    }
    Stamina(int a, int b, int c, int d){
        stamina = a;
        MAX_stamina = b;
        stamina_core = c;
        MAX_stamina_core = d;
    }
    Stamina(const Stamina &S){
        stamina = S.stamina;
        MAX_stamina = S.MAX_stamina;
        stamina_core = S.stamina_core;
        MAX_stamina_core = S.MAX_stamina_core;
    }

    int getStamina(){
        return Stamina;
    }
    int getMaxStamina(){
        return MAX_stamina;
    }
    int getStaminaCore(){
        return stamina_core;
    }
    int getMaxStaminaCore(){
        return MAX_stamina_core;
    }
};

#endif // STAMINA_HPP_INCLUDED
