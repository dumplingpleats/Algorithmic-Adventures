#include "Tavern.hpp"
/**
    Default constructor.
    Default-initializes all private members. 
*/

Tavern::Tavern() : ArrayBag<Character>() {
    level_sum_ = 0;
    enemy_count_ = 0;
}

/** 
@param:   A const reference to a Character entering the Tavern
@return:  returns true if a Character was successfully added to the tavern (i.e. items_),                 false otherwise
@post:    adds Character to the Tavern and updates the level sum and the enemy count 
            if the character is an enemy.
**/
bool Tavern::enterTavern(const Character& person) {
	if (add(person)) {
		level_sum_ += person.getLevel();
		if (person.isEnemy()) {
			enemy_count_++;
		}
		return true;
	}
	return false;
}

    /** 
    @param:   A const reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from the tavern (i.e. items_),               false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count
                if the character is an enemy.
    **/
bool Tavern::exitTavern(const Character& person) {
	if (remove(person)) {
		level_sum_ -= person.getLevel();
		if (person.isEnemy()) {
			enemy_count_--;
		}
		return true;
	}
	return false;
}


    /** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum() const{
        int total=0;
        for (int i=0; i<getCurrentSize(); i++){
            total+= items_[i].getLevel(); 
        }
        return total;
    };


    /** 
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
    **/
    int Tavern::calculateAvgLevel() const{
        return getLevelSum()/getCurrentSize();
    }; 

    /** 
    @return:  The integer enemy count of the Tavern
    **/

    int Tavern::getEnemyCount() const{
        int tally=0; 
        for( int i=0;  i<getCurrentSize(); i++){
            if(items_[i].isEnemy()){
                tally++;
        
            }
        }
        return tally;
    }; 

    /** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
    **/

    double Tavern::calculateEnemyPercentage() const{
        double percentage= ((double) getEnemyCount() / (getCurrentSize()) * 100.0); 
        return std::ceil(percentage * 100.0) /100.0;
    }; 

    /** 
    @param:   A const reference to a string representing a character Race with value in 
                ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return:  An integer tally of the number of characters in the Tavern of the given race. 
                If the argument string does not match one of the expected race values, 
                the tally is zero. NOTE: no pre-processing of the input string necessary, only                  uppercase input will match.
    **/

    int Tavern::tallyRace(const std::string& race) const{
        int tally=0; 
        for (int i=0; i<getCurrentSize(); i++){
            if (items_[i].getRace() == race){
                tally++;
            }
        }
        return tally;
    }; 

    /**
    @post:      Outputs a report of the characters currently in the tavern in the form:
            "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average             level is: [x] \n[x]% are enemies.\n"
            Note that the average level should be rounded to the NEAREST integer, and the enemy             percentage should be rounded to 2 decimal places.

            Example output: 
            Humans: 3
            Elves: 5
            Dwarves: 8
            Lizards: 6
            Undead: 0

            The average level is: 7
            46.67% are enemies.
    */

    void Tavern::tavernReport() const{
        std::cout<< "Humans: "<< tallyRace("HUMAN") << std::endl; 
        std::cout<< "Elves: "<< tallyRace("ELF") << std::endl; 
        std::cout<< "Dwarves: "<< tallyRace("DWARF") << std::endl; 
        std::cout<< "Lizards: "<< tallyRace("LIZARD") << std::endl; 
        std::cout<< "Undead: "<< tallyRace("UNDEAD") << std::endl<<std::endl; 
        std::cout<<"The average level is: "<<calculateAvgLevel()<<std::endl;
        std::cout<<calculateEnemyPercentage() << "% are enemies." << std::endl;

    }; 
