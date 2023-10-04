#include "Scoundrel.hpp"
/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/

Scoundrel::Scoundrel(){
    Character(); 
    dagger_=WOOD;
    faction_="NONE";
    has_disguise_=false;

}
/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.
    @param      : The character's dagger type (a const string reference).
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the dagger enum. Default to WOOD
    @param      : The character's Faction (a const string reference). 
                Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE"
    @param      : A flag indicating whether the character has a disguise. Default to false
    @post       : The private members are set to the values of the corresponding 
                parameters.
                If the dagger type is not provided or invalid, the variable should 
                be set to WOOD. 
                If the Faction is not provided or invalid, the variable should be 
                set to "NONE". 
*/
Scoundrel::Scoundrel(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& dagger, const std::string& faction, bool disguise):Character(name, race, vitality, armor, level, enemy) {
    setDagger(dagger);
    if (!setFaction(faction)) { 
        faction_ = "NONE";
    }
    setDisguise(disguise);
} 

/**
    @param     : a reference to a string representing the dagger type
    @post      : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the dagger type is not valid (i.e, is one of the following: 
                [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                the variable should be set to WOOD. 
**/
void Scoundrel::setDagger(const std::string &dagger_type) {
    std::string daggerUppercase = "";
    for (int n = 0; n < dagger_type.size(); n++) {
        daggerUppercase += toupper(dagger_type[n]);
    }

    if (daggerUppercase == "BRONZE") {
        dagger_ = BRONZE;
    } else if (daggerUppercase == "IRON") {
        dagger_ = IRON;
    } else if (daggerUppercase == "STEEL") {
        dagger_ = STEEL;
    } else if (daggerUppercase == "MITHRIL") {
        dagger_ = MITHRIL;
    } else if (daggerUppercase == "ADAMANT") {
        dagger_ = ADAMANT;
    } else if (daggerUppercase == "RUNE") {
        dagger_ = RUNE;
    } else {
        dagger_ = WOOD;
    }
}


/**
    @return     : the string indicating the character's dagger type
**/
std::string Scoundrel::getDagger() const {
    switch (dagger_) {
    case WOOD: return "WOOD";
    case BRONZE: return "BRONZE";
    case IRON: return "IRON";
    case STEEL: return "STEEL";
    case MITHRIL: return "MITHRIL";
    case ADAMANT: return "ADAMANT";
    case RUNE: return "RUNE";
    default: return "WOOD";
    }
}

/**
    @param    : a reference to a string representing the character's Faction
    @post     : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the provided faction is not one of the following: 
                [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
                do nothing and return false.
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Scoundrel::setFaction(const std::string &faction) {
    std::string factionUppercase ="";
    for (int j=0; j<faction.size(); j++){
      factionUppercase += toupper(faction[j]);
    }
    if (factionUppercase == "NONE") {
        faction_ = "NONE";
    } else if (factionUppercase == "CUTPURSE") {
        faction_ = "CUTPURSE";
    } else if (factionUppercase == "SHADOWBLADE") {
        faction_ = "SHADOWBLADE";
    } else if (factionUppercase == "SILVERTONGUE") {
        faction_ = "SILVERTONGUE";
    } else {
        return false;
    }

    return true;
}

/**
    @return  : the string indicating the character's Faction
**/
std::string Scoundrel::getFaction() const {
    return faction_;
}

/**
    @param  : a reference to boolean
    @post   : sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise(const bool &has_disguise) {
    has_disguise_ = has_disguise;
}

/**
    @return  : the visual aid flag
**/
bool Scoundrel::hasDisguise() const {
    return has_disguise_;
}
