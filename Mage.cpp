/* 
Ella Song 
Mage.cpp
*/
#include "Mage.hpp"

Mage::Mage()
{
    Character();
    school_of_magic_ = "NONE";
    weapon_ = "NONE";
    can_summon_incarnate_ = false;
}

Mage::Mage(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& school, const std::string& weapon, bool incarnate) : Character(name, race, vitality, armor, level, enemy)
{
    std::string new_school = "";

    for (int i=0; i<school.length();i++)
    {
        new_school += toupper(school[i]);
        }
    if (new_school == "ELEMENTAL")
    {
        school_of_magic_ = "ELEMENTAL";
    }
    else if (new_school == "NECROMANCY")
    {
        school_of_magic_ = "NECROMANCY";
    }
    else if (new_school == "ILLUSION")
    {
        school_of_magic_ = "ILLUSION";
    }
    else
    {
        school_of_magic_ = "NONE";
    }

    std::string new_weapon = "";
    for (int i=0; i<weapon.length();i++)
    {
        new_weapon += toupper(weapon[i]);
    }
    
    if (new_weapon == "WAND")
    {
        weapon_ = "WAND";
    }
    else if (new_weapon == "STAFF")
    {
        weapon_ = "STAFF";
    }
    else
    {
        weapon_ = "NONE";
    }

    can_summon_incarnate_ = incarnate;
}
 
bool Mage::setSchool(const std::string& school){
    std::string new_school = "";
    for (int i=0; i<school.length();i++) {
        new_school += toupper(school[i]);

    }

    if (new_school == "ELEMENTAL")
    {
        school_of_magic_ = "ELEMENTAL";
        return true;
    }
    else if (new_school == "NECROMANCY")
    {
        school_of_magic_ = "NECROMANCY";
        return true;
    }
    else if (new_school == "ILLUSION")
    {
        school_of_magic_ = "ILLUSION";
        return true;
    }
    else
    {
        return false;
    }
}

std::string Mage::getSchool() const
{
    return school_of_magic_;
}

bool Mage::setCastingWeapon(const std::string& weapon)
{
    std::string new_weapon = "";
    for (int i=0; i<weapon.length();i++)
    {
        new_weapon += toupper(weapon[i]);
    }

    if (new_weapon == "WAND")
    {
        weapon_ = "WAND";
        return true;
    }
    else if (new_weapon == "STAFF")
    {
        weapon_ = "STAFF";
        return true;
    }
    else
    {
        return false;
    }
}

std::string Mage::getCastingWeapon() const
{
    return weapon_;
}

void Mage::setIncarnateSummon(const bool& incarnate)
{
    can_summon_incarnate_ = incarnate;
}

bool Mage::hasIncarnateSummon() const 
{
    return can_summon_incarnate_;
}