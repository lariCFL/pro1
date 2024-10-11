#pragma once

#include "Player_class.hpp"
#include "Character_class.hpp"
#include "Equipament_class.hpp"

class Management {
private:
    std::vector<Player> players;
    std::vector<Equipment> equipmentList;

public:
    // Pre-condition: true
    // Post-condition: A player is added to the players vector.
    void createPlayer(std::string name, std::string login, std::string password);

    // Pre-condition: true
    // Post-condition: A character is added to the specified player.
    void createCharacter(std::string name, std::string type, std::string gender, float maxWeight, std::string playerName);

    // Pre-condition: true
    // Post-condition: Displays all characters belonging to the specified player.
    void showPlayerCharacters(std::string playerName);

    // Pre-condition: true
    // Post-condition: The specified character is equipped with the selected equipment.
    void equipCharacter(std::string characterName, std::string equipmentName);

    // Pre-condition: true
    // Post-condition: A new equipment item is added to the equipment list.
    void createItem(std::string name, std::string type, float weight);

    // Pre-condition: true
    // Post-condition: Displays the list of all players.
    void showPlayers();

    // Pre-condition: true
    // Post-condition: Displays the list of all equipment items.
    void showItems();
};
