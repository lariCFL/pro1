#include "Equipament_class.hpp"

// Initialize the maximum weight constant
//const float Equipment::MAX_weight = 30;
const std::array<std::string, 4> Equipment::equipmentTypes = { "Weapon", "Clothing", "Armor", "Talisman" };


// Constructor
Equipment::Equipment(){
    name= "Unknown";
    weight = 0;
    type = "Unknown";
 //   utilizado = false;
    typeIndex = 0;
}
Equipment::Equipment(string new_name, int new_type, float new_weight){
    name = new_name;
    if (isValidIndex(new_type)){type = equipmentTypes[new_type];}
    weight = new_weight;
  //  utilizado = false;
    typeIndex = new_type;
    //MAX_weight = 30;
}

Equipment::Equipment(string new_name, string new_type, float new_weight){
    name = new_name;
    type = new_type;
    weight = new_weight;
//   utilizado = false;
    typeIndex = -1;
    //MAX_weight = 30;
}

Equipment::Equipment(const Equipment &e){
    name= e.name;
    weight = e.weight;
    type = e.type;
   // utilizado = e.utilizado;
    typeIndex = e.typeIndex;
}

Equipment& Equipment::operator=(const Equipment &e){
    if (this != &e) {
        name= e.name;
        weight = e.weight;
        type = e.type;
       // utilizado = e.utilizado;
        typeIndex = e.typeIndex;
    }
    return *this;
}

// Destructor
Equipment::~Equipment()
{
}

// Consultors
string Equipment::getFullInfo() const {
    string info = name + " - " + type + ", " + to_string(weight);
    return info;
}
string Equipment::getName() const { return name; }
string Equipment::getType() const { return type; }
float Equipment::getWeight() const { return weight; }
int Equipment::getTypeIndex()const { return typeIndex;}
string Equipment::getEquipmentTypeAtIndex(int index) { return equipmentTypes[index]; }
bool Equipment::isValidIndex(int index){
    if (index < 0 || index >= equipmentTypes.size()) { return false;}
    else {return true;}
}
bool Equipment::isValidWeight(float new_weight){
    if (new_weight > 0 & new_weight <= MAX_weight) {return true;}
    else {return false;}
}
//bool Equipment::isEquiped(){return utilizado;}

// Modifiers
//void Equipment::modifyName(string new_name) {name = new_name;}
//void Equipment::modifyType(int new_type) { if (isValidIndex(new_type)){type = equipmentTypes[new_type];}}
//void Equipment::modifyWeight(float new_weight) {if (isValidWeight(new_weight) and !isEquiped()){ weight = new_weight;}}
//void Equipment::equip(){utilizado = true;}
//void Equipment::unequip(){utilizado = false;}

