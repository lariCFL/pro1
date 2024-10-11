#include "Player_class.hpp"

Player::Player(string new_name, string new_login, string new_password) {
    name = new_name;
    login = new_login;
    password = new_password;
}

Player::~Player() {
    characters.clear();
}

string Player::getName() const {
    return name;
}

string Player::getLogin() const {
    return login;
}

string Player::getPassword() const {
    return password;
}

vector<Character> Player::getCharacters() {
    vector<Character> charactersVector(characters.begin(), characters.end());
    return charactersVector;
}

vector<string> Player::showCharacters() {
    vector<string> charactersInfo;
    for (const auto& character : characters) {
        charactersInfo.push_back(character.getName());
    }
    return charactersInfo;
}

bool Player::addCharacter(Character newCharacter) {
    if (characters.size() < MAX_CHARACTERS && !characterExists(newCharacter.getName())) {
        characters.push_back(newCharacter);
        return true;
    }
    return false;
}

bool Player::characterExists(string characterName) const {
    for (const auto& character : characters) {
        if (character.getName() == characterName) {
            return true;
        }
    }
    return false;
}

bool Player::deleteCharacter(string characterName) {
    for (auto it = characters.begin(); it != characters.end(); ++it) {
        if (it->getName() == characterName) {
            characters.erase(it);
            return true;
        }
    }
    return false;
}
