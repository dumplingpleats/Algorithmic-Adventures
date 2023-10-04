/*ella song 
project 2 ranger.hpp 
*/
#ifndef RANGER_HPP
#define RANGER_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"


struct Arrows
{   
    std::string type_;
    int quantity_;
};

class Ranger : public Character {
    /*- A vector of arrows
    - A vector of affinities (strings)
    - A boolean indicating if they are able to recruit an animal companion
    */
    private:
    std::vector<Arrows> arrows_;
    std::vector<std::string> affinities_;
    bool has_companion_;

    public:
    Ranger();
    Ranger(const std::string &name, const std::string &race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, std::vector<Arrows> arrows = std::vector<Arrows>(), std::vector<std::string> affinities = std::vector<std::string>(),bool has_companion = false);    
    bool addArrows(const std::string& arrows, const int& number);
    std::vector<Arrows> getArrows() const;
  
    bool fireArrow(const std::string& arrows);
    bool addAffinity(const std::string& affinity);
 
    std::vector<std::string> getAffinities() const;
    void setCompanion(const bool& companion);
    bool getCompanion() const;
};

#endif