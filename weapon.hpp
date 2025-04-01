#pragma once
#include <cstdio>
#include <vector>

class Weapon {
public:
    std::vector<int> spells;//武器咒语序列
    const int penetration;//武器的p值

    Weapon(int _penetration): penetration(_penetration) {
        printf("Weapon with penetration %d created\n", penetration);
    }//接受p值
    ~Weapon() {
        printf("Weapon destroyed\n");
    }//武器构析

    // Disallow other constructors
    Weapon(const Weapon&) = delete;
    Weapon& operator=(const Weapon&) = delete;
    Weapon(Weapon&&) = delete;
    Weapon& operator=(Weapon&&) = delete;
};