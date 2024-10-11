#include "Character_class.hpp"

// Initialize static array of class types
const std::array<std::string, 4> Character::classTypes = {"Warrior", "Mage", "Priest", "Paladin"};

// Initialize static array of class genders
const std::array<std::string, 3> Character::classGender = {"Male", "Female", "Neutral"};

const float Character::maxWeight = 75.0f;

// Default constructor
Character::Character(){
    name = "Unknown";
    classType = "Unknown";
    gender = "Unknown";
    currentWeight = 0.0f;
    equipmentCount = 0;
    personal_maxWeight = 0.0f;
}

// Constructor with specified values
Character::Character(string new_name, int new_classType, int new_gender, float new_maxWeight){
    name = new_name;
    classType = classTypes[new_classType];
    gender = classGender[new_gender];
    currentWeight = 0.0f;
    equipmentCount = 0;
    personal_maxWeight = new_maxWeight;
}

Character::Character(string new_name, string new_classType, string new_gender, float new_maxWeight){
    name = new_name;
    classType = new_classType;
    gender = new_gender;
    currentWeight = 0.0f;
    equipmentCount = 0;
    personal_maxWeight = new_maxWeight;
}

// Copy constructor
Character::Character(const Character &c){
    name = c.name;
    classType = c.classType;
    gender = c.gender;
    currentWeight = c.currentWeight;
    equipmentCount = c.equipmentCount;
    personal_maxWeight = c.personal_maxWeight;
    equipmentList = c.equipmentList;
}

// Assignment operator
Character& Character::operator=(const Character &c){
    if (this != &c) {
        name = c.name;
        classType = c.classType;
        gender = c.gender;
        currentWeight = c.currentWeight;
        equipmentCount = c.equipmentCount;
        personal_maxWeight = c.personal_maxWeight;
        equipmentList = c.equipmentList;

    }
    return *this;
}


// Destructor
Character::~Character() {
}

// Accessors
string Character::getName() const { return name; }

string Character::getClassType() const { return classType; }

string Character::getGender() const { return gender; }

int Character::getMaxWeight() const { return personal_maxWeight; }

int Character::getTypeSize() {return classTypes.size();}

string Character::getTypeAtIndex(int index) {return classTypes[index];}

int Character::getGenderSize() {return classGender.size();}

string Character::getGenderAtIndex(int index) {return classGender[index];}

int Character::numEquipment() const { return equipmentCount; }

float Character::getCurrentWeight() const { return currentWeight; }

void Character::showEquipment() const {
    for (int i = 0; i < equipmentList.size(); i++) {
        auto it = std::next(equipmentList.begin(), i);
        std::cout << "Equipment " << i + 1 << ": "
                  << it->getName() << ", Weight: " << it->getWeight() << std::endl;
    }
}

int Character::getArrayEquipmentSize(){ return MAX_EQUIPMENT; }

// Validators
bool Character::isValidWeight(float new_weight) { return new_weight <= personal_maxWeight; }

bool Character::isValidWeightPersonal(float new_weight) { return (new_weight <= maxWeight && new_weight > 0); }

bool Character::isValidIndexGender(int index) { return index >= 0 && index < classGender.size(); }

bool Character::isValidIndexClass(int index) { return index >= 0 && index < classTypes.size();}

bool Character::canEquip() {
    if (equipmentCount < MAX_EQUIPMENT){return true;}
    else{return false;}}

// Equipment management
string Character::addEquipment(const Equipment newEquipment) {
    float newWeight = getCurrentWeight() + newEquipment.getWeight();
    if (canEquip() && isValidWeight(newWeight)) {
        equipmentList.push_back(newEquipment); // adiciona equipamento diretamente à lista
        currentWeight = newWeight;
        equipmentCount++;
        return "Equipped successfully";
    }
    return "Unable to equip";
}

string Character::removeEquipment(std::string equipmentName) {
    for (auto it = equipmentList.begin(); it != equipmentList.end(); ++it) {
        if (it->getName() == equipmentName) {
            currentWeight -= it->getWeight();
            equipmentList.erase(it); // remove equipamento da lista
            equipmentCount--;
            return "Removed successfully";
        }
    }
    return "Not removed";
}

/*bool Character::equipmentExists(std::string equipmentName) {
    for (const auto& equipment : equipmentList) {
        if (equipment.getName() == equipmentName) {
            return true;
        }
    }
    return false;
}*/

vector<string> Character::InfoEquipments(){
    vector<string> v;
    if (equipmentList.empty()) {
        v.push_back("No equipment created.");
    } else {
        for (const auto &equipment : equipmentList) {
            string a = "Name: " + equipment.getName() + "/n";
            a += "Type: " + equipment.getType() + "/n";
            a += "Weight: " + to_string(equipment.getWeight());
            
            v.push_back(a);
        }
    }
    return v;
}



// Modifiers
/*void Character::modifyName(string new_name) { name = new_name; }

void Character::modifyClassType(int new_classType) {
    if (isValidIndexClass(new_classType)) {
        classType = classTypes[new_classType];
    }
}

void Character::modifyGender(int new_gender) {
    if (isValidIndexGender(new_gender)) {
        gender = classGender[new_gender];
    }
} */

/*bool Character::equipmentIndexExists(int index) {
    return index >= 0 && index < equipmentCount; // checa se o índice está dentro dos limites
}*/

/*std::string Character::NameEquipment(int index) {
 if (equipmentIndexExists(index)) {
     return equipmentList[index].getName(); // acesso direto ao equipamento
 } else {
     return "unknown";
 }
}

std::string Character::InfoEquipment(int index) {
 if (equipmentIndexExists(index)) {
     float weight = equipmentList[index].getWeight();
     std::string info = equipmentList[index].getName() + " - ";
     info += "Type: " + equipmentList[index].getType();
     info += ", Weight: " + std::to_string(weight) + " kg";
     return info;
 } else {
     return "unknown";
 }
}*/
