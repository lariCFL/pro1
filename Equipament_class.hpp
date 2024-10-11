#pragma once

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Equipment {
private:
    string name;           // Name of the equipment
    string type;            // Type of equipment: Weapon, Clothing, Armor, Talisman
    static const std::array<std::string, 4> equipmentTypes;  // Array imutável dos tipos de equipamento
    float weight;           // Weight of the equipment in kg
    float const MAX_weight = 30;   // Maximo weight (30) of the equipment in kg
   // bool utilizado;
    int typeIndex;

public:
    // Constructor
    Equipment();
    /* Pre: None */
    /* Post: An Equipment object is created with default values:
             - name is set to "Unknown"
             - type is set to "Unknown"
             - weight is set to 0.0f */

    Equipment(string new_name, int new_type, float new_weight);
    /* Pre: new_weight > 0 && new_weight <= 30 */
    /* Post: new equipment created with specified name and weight; type as one of the presets. */
    
    Equipment(string new_name, string new_type, float new_weight);
    /* Pre: new_weight > 0 && new_weight <= 30 */
    /* Post: new equipment created with specified name, type, and weight*/
    
    Equipment(const Equipment &e);
    
    Equipment& operator=(const Equipment &e);

    // Destructor
    ~Equipment();
    /* Post: no longer references to the equipment, and memory is freed */

    //Consultors
    string getFullInfo() const;
    /* Pre: true */
    /* Post: returns the name, the type, and the weight of the equipment */
    
    string getName() const;
    /* Pre: true */
    /* Post: returns the name of the equipment */

    string getType() const;
    /* Pre: true */
    /* Post: returns the type of the equipment */
    
    int getTypeIndex()const;

    float getWeight() const;
    /* Pre: true */
    /* Post: returns the weight of the equipment */

    bool isValidWeight(float new_weight);
    /* Pre: true*/
    /* Post: returns true if the new weight is valid, false otherwise */
    
    static string getEquipmentTypeAtIndex(int index);
    /* Pre: 0 <= index >= equipmentTypes.size()*/
    /* Post: returns the equipment type at the specified index */

    static bool isValidIndex (int index);
    /* Pre: True*/
    /* Post: returns true if the index is valid, false otherwise */
    
 //   bool isEquiped();
    /* Pre: True */
    /* Post: Returns true if the equipment is currently being used (utilizado == true),
             otherwise returns false */

    
    //Modifiers
    //void modifyName(string new_name);
    /* Pre: true */
    /* Post: updates the name of the equipment */

    //void modifyType(int new_type);
    /* Pre: 0 <= index >= equipmentTypes.size()*/
    /* Post: updates the type of the equipment */

    //void modifyWeight(float new_weight);
    /* Pre: true */
    /* Post: updates the weight of the equipment if its not equiped and new_weight > 0 && new_weight <= 30*/
    
   // void equip();
    /* Pre: The equipment is not currently being used (utilizado == false) */
    /* Post: The equipment is now being used (utilizado == true) */

   // void unequip();
    /* Pre: The equipment is currently being used (utilizado == true) */
    /* Post: The equipment is no longer being used (utilizado == false) */
    
};
