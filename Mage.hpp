/* 
ella song 
project 2 235 
tizania ligorio
*/
#ifndef MAGE_HPP
#define MAGE_HPP
#include <iostream>
#include "Character.hpp"

class Mage : public Character {
    private:
    std::string school_of_magic_;
    std::string weapon_;
    bool can_summon_incarnate_;
    
    public:
    Mage();
    Mage(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& school = "NONE", const std::string& weapon = "NONE", bool incarnate = false);
    
    bool setSchool(const std::string& school);
    std::string getSchool() const;

    bool setCastingWeapon(const std::string& weapon);
    std::string getCastingWeapon() const;

    void setIncarnateSummon(const bool& incarnate);
    bool hasIncarnateSummon() const;
};

#endif