// Difficulty.hpp
// Author: Jose Camacho
// Date: 5/08/2021
// Description: Difficulty child class
#ifndef DIFFICULTY_H
#define DIFFICULTY_H
#pragma once
#include "Game.hpp"
#include "EasyMediumHard.hpp"

class Difficulty : public Game
{
   //Declare variables
private:
   int numOfAttempts;

public:
   void setNumOfAttempts(int a) { numOfAttempts = a; }
   int getNumOfAttempts() { return numOfAttempts; }
   int getScore() { return score; }
   //Points increase depending on the difficulty.
   void addToScore(int i)
   {
      if (numOfAttempts == 8)
         score += i * 22;
      else if (numOfAttempts == 6)
         score += i * 44;
      else if (numOfAttempts == 4)
         score += i * 66;
   }
   //Depending on the Enum list, the number of attempts is set.
   void setDifficulty(EasyMediumHard s)
   {
      switch (s)
      {
      case Easy:
         numOfAttempts = 8;
         break;
      case Medium:
         numOfAttempts = 6;
         break;
      case Hard:
         numOfAttempts = 4;
         break;
      }
   }

   //Depending on the numOfAttempts, the hangman will have different views.
   void displayHangman(int numleft)
   {
      if (numOfAttempts == 4)
      {
         switch (numleft)
         {
         case 4:
            cout << " ______________________" << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 3:
            cout << " ______________________" << endl;
            cout << "|            O         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 2:
            cout << " ______________________" << endl;
            cout << "|            O         " << endl;
            cout << "|           /|\\       " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 1:
            cout << " ______________________" << endl;
            cout << "|            O         " << endl;
            cout << "|           /|\\       " << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 0:
            cout << " ______________________" << endl;
            cout << "|            O         " << endl;
            cout << "|           /|\\       " << endl;
            cout << "|            |         " << endl;
            cout << "|           /-\\       " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         default:
            break;
         }
      }
      if (numOfAttempts == 6)
      {
         switch (numleft)
         {
         case 6:
            cout << " ______________________" << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 5:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 4:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 3:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            O         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 2:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            O         " << endl;
            cout << "|           /|\\       " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 1:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            O         " << endl;
            cout << "|           /|\\       " << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 0:
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
            break;
         default:
            break;
         }
      }
      if (numOfAttempts == 8)
      {
         switch (numleft)
         {
         case 8:
            cout << " ______________________" << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 7:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 6:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 5:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 4:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 3:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            O         " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 2:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            O         " << endl;
            cout << "|           /|\\       " << endl;
            cout << "|                      " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 1:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            O         " << endl;
            cout << "|           /|\\       " << endl;
            cout << "|            |         " << endl;
            cout << "|                      " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         case 0:
            cout << " ______________________" << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            |         " << endl;
            cout << "|            O         " << endl;
            cout << "|           /|\\       " << endl;
            cout << "|            |         " << endl;
            cout << "|           /-\\       " << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|----------------------" << endl;
            cout << "|______________________" << endl;
            break;
         default:
            break;
         }
      }
   }
   Difficulty() : Game()
   {
      numOfAttempts = 0;
   };
};
#endif
