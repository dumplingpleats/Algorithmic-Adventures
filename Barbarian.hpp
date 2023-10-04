/*ella song 
cs 235 f 23 proj 2 
barbarian.hpp 
*/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <iostream>
#include "Character.hpp"

class Barbarian : public Character{
    /*
    - A string representing their main weapon
    - A string representing their offhand weapon
    - A boolean indicating if they are enraged
    */
    private:
    std::string main_weapon_;
    std::string secondary_weapon_;
    bool enraged_;
    
    public:
    Barbarian();
    Barbarian(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& main_weapon = "NONE", const std::string& secondary_weapon = "NONE", bool enraged = false);
   
    bool setMainWeapon(const std::string& main_weapon);
    std::string getMainWeapon() const;

    bool setSecondaryWeapon(const std::string& secondary_weapon);
    std::string getSecondaryWeapon() const;
    
    void setEnrage(const bool& enraged);
    bool getEnrage() const;
    void toggleEnrage();
};

#endif

