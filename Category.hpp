// Category.hpp
// Author: Jose Camacho
// Date: 5/08/2021
// Description: Category child class
#ifndef CATEGORY_H
#define CATEGORY_H
#pragma once
#include "Game.hpp"
#include <fstream>

class Category : public Game
{
	//Declare variables
private:
	string name;

public:
	string getName() { return name; }
	string getWord() { return word; }
	void setWord(ifstream &inData, string wordlist[10])
	//Depending on the name of the category, a certain file will be opened.
	{
		try
		{
			if (name == "animals")
				inData.open("animals.txt");
			if (name == "sports")
				inData.open("sports.txt");
			if (name == "fruits")
				inData.open("fruits.txt");
			if (name == "countries")
				inData.open("countries.txt");
			if (name == "vegetables")
				inData.open("vegetables.txt");
			if (!inData)
				throw 56;
		}
		//If the file is not found, display error message
		catch (int)
		{
			cout << "Error: File not found" << endl;
		}
		//Make a word list and choose a randon one for the word.
		for (int i = 0; i < 10; i++)
		{
			inData >> (wordlist[i]);
		}
		srand(time(NULL)); //initialize the random seed
		int randomnum = rand() % 10;
		string RandomWord = wordlist[randomnum];
		for (int i = 0; i < RandomWord.length(); i++)
		{
			toupper(RandomWord[i]);
		}
		word = RandomWord;
		inData.close();
	}
	//Replace each letter of the word with "*";
	string getMisteryWord()
	{
		string newMisteryWord = word;
		for (int i = 0; i < newMisteryWord.length(); i++)
		{
			newMisteryWord[i] = '*';
		}
		return newMisteryWord;
	}
	//Ask user for category.
	void setCategory()
	{
		cout << "Choose a category:" << endl;
		cout << "1.Animals 2.Sports 3.Fruits 4.Countries 5.Vegetables: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			name = "animals";
			break;
		case 2:
			name = "sports";
			break;
		case 3:
			name = "fruits";
			break;
		case 4:
			name = "countries";
			break;
		case 5:
			name = "vegetables";
			break;
		}
	}
	Category() : Game()
	{
		name = "none";
	}
};
#endif