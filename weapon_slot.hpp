#pragma once
#include "weapon.hpp"

inline int max(int a,int b){
    return a>b? a:b;
}

class WeaponSlot {
    Weapon* w=nullptr;
    public:
    void create_weapon(int p){
        w = new Weapon(p);
    }

    void add_spell(int a){
        w->spells.push_back(a);
    }

    WeaponSlot& operator=(WeaponSlot&& m){
        w = m.w;
        m.w = nullptr;  
        return *this;
    }

    WeaponSlot& operator=(const WeaponSlot& m){
        create_weapon(m.w->penetration);
        for(int i=0;i<m.w->spells.size();i++){
            if(m.w->spells[i]%2==0)
                w->spells.push_back(m.w->spells[i]);
        }
        return *this;
    }

    int calc_damage_typeA(int d){
        d-=w->penetration;
        if(d<0) d=0;
        int dam=0;
        for(int i=0;i<w->spells.size();i++){
            if(w->spells[i]>d)
                dam+=(w->spells[i]-d);
        }
        return dam;
    }

    int calc_damage_typeB(){
        int d=0;
        int dam=0;
        for(int i=0;i<w->spells.size();i++){
            if(w->spells[i]>max(0,d-w->penetration))
                dam+=(w->spells[i]-max(0,d-w->penetration));
            d++;
        }
        return dam;
    }

    int calc_damage_typeC(){
        int d=0;
        int dam=0;
        for (int i=0;i<w->spells.size();i++) {       
            int damage = w->spells[i] - max(0, d-w->penetration);        
            if (damage > 0) {                      
                if (damage % 2 != 0) {            
                    d++;
                } else {                                  
                   damage/=2;
                }
                dam += damage;   
            }
                                    
        }
        return dam;
    }

    ~WeaponSlot(){
        delete w;
    }
};//槽