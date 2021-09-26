// Game.hpp
// Author: Jose Camacho
// Date: 5/08/2021
// Description: Game parent class
#ifndef GAME_H
#define GAME_H
#pragma once
#include <iostream>
#include <string>

using namespace std;
class Game
{
    //Declare variables, protected so child classes can access them.
protected:
    string username;
    int score;
    string word;
    bool won;

public:
    void setWon(bool i) { won = i; }
    bool getWon() { return won; }
    void setScore(int num) { score = num; }
    void setUsername(string name) { username = name; }
    string getUserName() { return username; }
    int getScore() { return score; }
    void addToScore(int i)
    {
        score += i * 1;
    }
    //Display Hangman(Welcome menu)
    void displayHangman()
    {
        cout << "-----------------------" << endl;
        cout << "Welcome to Hangman Game" << endl;
        cout << "---By: Jose Camacho----" << endl;
        cout << "--------CSC160---------" << endl;
        cout << " ______________________" << endl;
        cout << "|            |         " << endl;
        cout << "|            |         " << endl;
        cout << "|            O         " << endl;
        cout << "|           /|\\       " << endl;
        cout << "|            |         " << endl;
        cout << "|           /-\\       " << endl;
        cout << "|                      " << endl;
        cout << "|                      " << endl;
        cout << "|----------------------" << endl;
        cout << "|----------------------" << endl;
        cout << "|----------------------" << endl;
        cout << "|______________________" << endl;
        cout << "Press 1 to begin the game, or 2 to quit: ";
    }
    Game()
    {
        username = "Jose Camacho";
        score = 0;
        won = true;
    };
};
#endif