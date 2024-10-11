#pragma once

#include "Character_class.hpp"
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Player {
  private:
    static const int MAX_CHARACTERS =
        5;                      // Maximum number of characters per player
    string name;                // Name of the player
    string login;               // Player's login
    string password;            // Player's password
    list<Character> characters; // List of Character objects

  public:
    /////***** Constructor *****/////

    Player(string new_name, string new_login, string new_password);
    /* Pre: true */
    /* Post: new player is created with specified name, login, and password */

    /////***** Destructor *****/////

    ~Player();
    /* Post: no longer references to the characters, and memory is freed */

    /////***** Consultors (Getters) *****/////

    string getName() const;
    /* Pre: true */
    /* Post: returns player's name */

    string getLogin() const;
    /* Pre: true */
    /* Post: returns player's login */

    string getPassword() const;
    /* Pre: true */
    /* Post: returns player's password */
    
    vector<Character> getCharacters();
    /* Pre: true */
    /* Post: returns the characters list */

    vector<string> showCharacters();
    /* Pre: true */
    /* Post: return a vector string with all characters info*/
    

    /////***** Character management *****/////

    bool addCharacter(Character newCharacter);
    /* Pre: newCharacter's name is unique for the player */
    /* Post: adds a Character to the player's list if conditions are met */

    bool characterExists(string characterName) const;
    /* Pre: true */
    /* Post: chˆcks if a character with the specified name exists for the player
     */

    bool deleteCharacter(string characterName);
    /* Pre: true */
    /* Post: deletes a character from the player's list if it exists */
};

/////***** Modifiers (Setters) *****/////

// void modifyName(string new_name);
/* Pre: true */
/* Post: updates player's name */

// void modifyLogin(string new_login);
/* Pre: true */
/* Post: updates player's login */

// void modifyPassword(string new_password);
/* Pre: true */
/* Post: updates player's password */
