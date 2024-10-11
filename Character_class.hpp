#pragma once

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "Equipament_class.hpp"

using namespace std;

class Character {
private:
    string name;
    string classType;
    static const array<std::string, 4> classTypes;  // Immutable array of class types
    // Warrior, Mage, Priest, Paladin
    string gender;
    static const array<std::string, 3> classGender;  // Immutable array of gender types
    // Male, Female, Neutral
    static const float maxWeight;
    float personal_maxWeight;
    float currentWeight;
    int equipmentCount;
    static const int MAX_EQUIPMENT = 6;  // Maximum number of equipment items
    vector<Equipment> equipmentList;

public:
    // Constructors
    Character();
    /* Pre: None */
    /* Post: A Character object is created with default values:
             - name is set to "Unknown"
             - Class type is set to "Unknown"
             - gender is set to "Unknown"
             - maxWeight is set to 0 */

    Character(string new_name, int new_classType, int new_gender, float new_maxWeight);
    /* Pre: true */
    /* Post: A Character object is created with the specified name and maxWeight; class and gender  in base of the preset options*/
    
    Character(string new_name, string new_classType, string new_gender, float new_maxWeight);
    /* Pre: true */
    /* Post: A Character object is created with the specified name, class, gender, and maxWeight */

    Character(const Character &c);
    /* Pre: true */
    /* Post: A new Character object is created with the same attributes as the Character 'c' */

    Character& operator=(const Character &c);
    /* Pre: true */
    /* Post: The current Character object takes on the attributes of the Character 'c' */
    
    // Destructor
    ~Character();
    /* Post: deletes dynamically allocated Equipment objects */


    // Accessors
    string getName() const;
    /* Pre: true */
    /* Post: returns character's name */

    string getClassType() const;
    /* Pre: true */
    /* Post: returns character's class type */

    string getGender() const;
    /* Pre: true */
    /* Post: returns character's gender */
    
    int getMaxWeight() const;
    /* Pre: true */
    /* Post: returns character's max weight*/
    
    static int getTypeSize();
    /* Pre: true*/
    /* Post: returns the type array size */
    
    static string getTypeAtIndex(int index);
    /* Pre: 0 <= index >= Types.size()*/
    /* Post: returns the type at the specified index */
    
    static int getGenderSize();
    /* Pre: true*/
    /* Post: returns the gender array size */
    
    static string getGenderAtIndex(int index);
    /* Pre: 0 <= index >= Gender.size()*/
    /* Post: returns the gender at the specified index */
    
    float getCurrentWeight() const;
    /* Pre: true */
    /* Post: returns current weight of the equipment the character is carrying */

    void showEquipment() const;
    /* Pre: true */
    /* Post: displays all equipment items and their weights */
    
    static int getArrayEquipmentSize();
    /* Pre: true*/
    /* Post: returns the equipament array size */
    
    
    // Validators
    bool isValidWeight(float new_weight);
    /* Pre: true */
    /* Post: returns true if the new weight is valid, false otherwise */
    
    static bool isValidWeightPersonal(float new_maxWeight);
    /* Pre: true */
    /* Post: returns true if the max weight is valid, false otherwise */
    
    static bool isValidIndexGender(int index);
    /* Pre: true */
    /* Post: returns true if the index Gender is valid, false otherwise */
    
    static bool isValidIndexClass(int index);
    /* Pre: true */
    /* Post: returns true if the index Class is valid, false otherwise */
    
    bool canEquip();
    /* Pre: true */
    /* Post: returns if can equip new equipment*/


    // Equipment management
    string addEquipment(Equipment newEquipment);
    /* Pre: true */
    /* Post: adds Equipment to character's inventory if there's space and weight capacity */

    string removeEquipment(string equipmentName);
    /* Pre: equipmentName exists in the list */
    /* Post: removes the specified Equipment and updates weight */

    //string equipmentExists(string equipmentName);
    /* Pre: true */
    /* Post: checks what equipment exists */
    
    
    int numEquipment() const;
    /* Pre: true */
    /* Post: returns how many equipments are equiped */
    
   // string NameEquipment(int index);
    /* pre: true */
    /* Post: returns the equipament name at the index*/
    
    vector<string> InfoEquipments();
    /* pre: true */
    /* Post: returns the equipament full information*/
};




// Modifiers
//void modifyName(string new_name);
/* Pre: true */
/* Post: updates character's name */

//void modifyClassType(int new_classType);
/* Pre: true */
/* Post: updates character's class type */

//void modifyGender(int new_gender);
/* Pre: true */
/* Post: updates character's gender */


//bool equipmentIndexExists(int index);
/* Pre: true */
/* Post: checks what equipment exists */
