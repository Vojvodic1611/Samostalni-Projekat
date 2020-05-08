#include <iostream>
#ifndef WEAPON_HPP_INCLUDED
#define WEAPON_HPP_INCLUDED
#include "Dinstring.hpp"
#include "List.hpp"

class Weapon{
private:
    int Damage;
    int Accuracy;
    int Range;
    int Ammo;
    DinString Name;
public:
    Weapon(){
        Damage = 70;
        Accuracy = 60;
        Range = 70;
        Ammo = 30;
        Name = "Revolver";
    }
    Weapon(int a, int b, int c, DinString d, int k){
        Damage = a;
        Accuracy = b;
        Range = 70;
        Name = d;
        Ammo = k;
    }
    Weapon(const Weapon &W){
        Damage = W.Damage;
        Accuracy = W.Accuracy;
        Range = W.Range;
        Name = W.Name;
        Ammo = W.Ammo;
    }
    int getWeaponDamage()const{
        return Damage;
    }
    int getWeaponAccuracy()const{
        return Accuracy;
    }
    int getWeaponRange()const{
        return Range;
    }
    int getWeaponAmmo()const{
        return Ammo;
    }
    DinString getWeaponName()const{
        return Name;
    }
    void setWeaponDamage(const int D){
        Damage = D;
    }
    void setWeaponAccuracy(const int A){
        Accuracy = A;
    }
    void setWeaponRange(const int R){
        Range = R;
    }
    void setWeaponAmmo(const int Am){
        Ammo = Am;
    }
    void setWeaponName(const DinString N){
        Name = N;
    }
    void SHOOT(){
        Ammo -= 1;
    }

    friend ostream& operator <<(ostream&out, Weapon& w){
        out << "Weapon Damage = "<< w.getWeaponDamage()<< endl;
        out << "Weapon Accuracy = "<< w.getWeaponAccuracy()<< endl;
        out << "Weapon Range = "<< w.getWeaponRange()<< endl;
        out << "Weapon Ammo = "<< w.getWeaponAmmo()<< endl;
        out << "Weapon Name = "<< w.getWeaponName()<< endl;
        return out;
    }
};

#endif // WEAPON_HPP_INCLUDED
