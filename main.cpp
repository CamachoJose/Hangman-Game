// main.cpp
// Author: Jose Camacho
// Date: 5/08/2021
// Description: Main Hangman Game program.
#include <iostream>
#include <string>
#include <fstream>
#include "Difficulty.hpp"
#include "Category.hpp"
using namespace std;

struct keyboard
{
    string mysteryWord;
    char *letters;
    //Constructor
    keyboard()
    {
        //Make a new dynamic array of type char size 26
        letters = new char[26];
        char j = 'A';
        for (int i = 0; i < 26; i++)
        {
            letters[i] = j;
            j++;
        }
        mysteryWord = "*****";
    }
    //Sets keyboard to its original state
    void resetKeyboard()
    {
        char j = 'A';
        for (int i = 0; i < 26; i++)
        {
            letters[i] = j;
            j++;
        }
    }
    //operator overloading to substract a letter from the keyboard.
    void operator-(const char &c) const
    {
        for (int i = 0; i < 14; i++)
        {
            if (c == letters[i])
                letters[i] = ' ';
        }
        for (int i = 14; i <= 26; i++)
        {
            if (c == letters[i])
                letters[i] = ' ';
        }
    }

    void displayKeyboard()
    {
        for (int i = 0; i < 14; i++)
        {
            cout << letters[i] << " ";
            if (i == 13)
                cout << endl;
        }
        for (int i = 14; i <= 26; i++)
        {
            cout << letters[i] << " ";
        }
    }
};
bool didYouWin(Game game, Difficulty *dif, Category *cate, keyboard g);

int main()
{
    //Declare variables and pointers.
    Game g1;
    Difficulty d1;
    Difficulty *diffptr = &d1;
    Category c1;
    Category *catptr;
    catptr = new Category;
    catptr = &c1;
    keyboard gameplay;
    ifstream inData;
    ofstream outData;
    string wordlist[10];
    bool win;
    g1.displayHangman();
    //Ask user if they want to beging playing.
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        cout << endl;
        cout << "Lets begin" << endl;
        cout << "Enter a username: ";
        //Get info from the user
        string name;
        cin >> name;
        g1.setUsername(name);
        bool question = true;
        while (question == true)
        {
            cout << "Choose a Difficulty:" << endl;
            cout << "1. Easy 2. Medium 3. Hard" << endl;
            int choice2;
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                diffptr->setDifficulty(Easy);
                break;
            case 2:
                diffptr->setDifficulty(Medium);
                break;
            case 3:
                diffptr->setDifficulty(Hard);
                break;
            default:
                cout << "Wrong choice" << endl;
                break;
            }
            catptr->setCategory();
            catptr->setWord(inData, wordlist);
            win = didYouWin(g1, diffptr, catptr, gameplay);
            g1.setWon(win);
            //If user wins, add points to final score
            if (g1.getWon() == true)
                diffptr->addToScore(c1.getWord().length());
            cout << "Want to play again? Enter 1 for yes, 0 for no: ";
            //Keep playing while question is yes.
            cin >> question;
            //Reset keyboard each game.
            gameplay.resetKeyboard();
            cout << endl;
        }
        //Output report card to an external .txt file.
        cout << "Please check your report card a the ReportCardFile file" << endl;
        outData.open("ReportCard.txt");
        outData << "Thanks for playing my game, here is your report: " << endl;
        outData << "Username: " << g1.getUserName() << endl;
        outData << "Score: " << diffptr->getScore() << " points!" << endl;
        outData.close();
    }
    else
        return 0;
}

bool didYouWin(Game game, Difficulty *dif, Category *cate, keyboard g)
{
    int numleft = dif->getNumOfAttempts();
    g.mysteryWord = cate->getMisteryWord();
    //Repeats until mystery word is equal to the actual word, or until numOfAttempts = 0
    while (cate->getWord() != g.mysteryWord && numleft > 0)
    {
        bool correct = false;
        cout << endl;
        //Display info
        cout << "Username: " << game.getUserName() << " " << endl;
        cout << "The word you have to guess is: " << g.mysteryWord << endl;
        cout << "The word has " << cate->getWord().length() << " letter in it." << endl;
        cout << "Category is: " << cate->getName() << endl;
        dif->displayHangman(numleft);
        cout << "You have " << numleft << " of attempts left." << endl;
        g.displayKeyboard();
        cout << endl;
        cout << "Guess a letter: ";
        //Get letter from user.
        char letter;
        cin >> letter;
        letter = toupper(letter);
        //If letter is within the word, replace it.
        for (int i = 0; i < g.mysteryWord.length(); i++)
        {
            if (letter == cate->getWord()[i])
            {
                g.mysteryWord[i] = toupper(letter);
                cout << "You guessed correctly!" << endl;
                correct = true;
            }
        }
        //if it is not within the word, decrease attempts.
        if (correct == false)
        {
            numleft--;
            cout << "Sorry, " << letter << " was not part of the word " << endl;
        }
        g - toupper(letter);
    }
    //Looser message.
    if (numleft == 0)
    {
        dif->displayHangman(0);
        cout << "Sorry you did not guess the word, nice try though. " << endl;
        cout << "The word was: " << cate->getWord() << endl;
        return false;
    }
    //Winner message.
    if (g.mysteryWord == cate->getWord())
    {
        cout << "Congratulations! You won!" << endl;
        cout << "The word was " << cate->getWord() << endl;
        return true;
    }
}
