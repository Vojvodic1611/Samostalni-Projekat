#include <iostream>
#ifndef HEALTH_HPP_INCLUDED
#define HEALTH_HPP_INCLUDED

class Health{
private:
    int HP;
    int MAX_HP;
    int health_core;
    int max_health_core;
public:
    Health(){
        HP = 100;
        MAX_HP = 100;
        health_core = 100;
        max_health_core = 100;
    }
    Health(int HP1, int MAX_HP1, int health_core1, int max_health_core1){
        HP =  HP1;
        MAX_HP = MAX_HP1;
        health_core = health_core1;
        max_health_core = max_health_core1;
    }
    Health(const Health &H){
        HP = H.HP;
        MAX_HP = H.MAX_HP;
        health_core = H.health_core;
        max_health_core = H.max_health_core;
    }

    int getHP(){
        return HP;
    }
    int getMAX_HP{
        return MAX_HP;
    }
    int getHealth_Core(){
        return health_core;
    }
    int getMax_Health_Core(){
        return max_health_core;
    }

};

#endif // HEALTH_HPP_INCLUDED
