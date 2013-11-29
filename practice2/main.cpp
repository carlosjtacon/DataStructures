#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "queue.h"
#include "stack.h"
#include "functions.h"

using namespace std;

int main(int argc, const char* argv[])
{
	
	#define HELP "Usage: ./palindrome [parameter]\nWhere: parameter is one of:\n\t\t-h (help)\n\t\t-k (read from keyboard)\n\t\t-f file (read from file)\n\t\t-d letter (remove all palindromes which start by this letter)\n\t\t-s (show data)\n\t\t-q (exit)\n";
	
	string input ("\0");
	string original ("\0");
	string command;

	//always print the help at the begin
	cout << HELP;	

	do
	{
		//print a new prompt until -q
		cout << "$ palindrome ";
		getline(cin, command, '\n');
		int myArgc = numWords(command);
		queue<string> myArgv;
		for (int i = 0; i < command.length(); ++i)
		{
			//add word to array
		}
	}
	while(command != "-q");
/*
	if (argc == 1)
	{
		//print the help menu
		cout << HELP;
		return 0;
	}
	else if(argc == 2)
	{
		if (strcmp(argv[1],"-f")==0)
		{
			//command -f without passing file
			cout << "Which file do you want to open? Pass it in arguments :)\n";
			cout << HELP;
			return 0;
		}
		else if (strcmp(argv[1],"-k")==0)
		{
			//read strings from keyboard
			int i = 0;

			while(original!="q")
			{
				cout << "(" << i << ") "; i++;
				getline(cin, original, '\n');
				input = rmSpace(original);

				if (isPalindrome(input) && original!="q")
				{
					//list.add(original);
				}
			} 
		}
		else
		{
			// if wrong parameter
			cout << "Paremeter unknown " << argv[1] << endl;
			cout << HELP;
			return 0;
		}
	}
	else if(argc == 3)
	{
		if(strcmp(argv[1],"-f")==0)
		{	
			// if everything is ok
			ifstream inputFile (argv[2]);
			if(inputFile.is_open())
			{
				string tmp;
				while(getline(inputFile, tmp))
				{
					//INSERTAR
				}
			}	
			else
			{
				//filename does not exists
				cout << "The file couldn't be opened, maybe doesn't exists :(\n";
				cout << HELP;
				return 0;
			}
		}
		else if (strcmp(argv[1],"-k")==0)
		{
			//using command -k with more arguments
			cout << "This parameter is used without arguments, try again!\n";
			cout << HELP;
			return 0;
		}
		else
		{	
			// if wrong parameter
			cout << "Paremeter unknown " << argv[1] << endl;
			cout << HELP;
			return 0;
		}
	}
	else if (argc > 3)
	{
		//passing more than 2 arguments (2+ ./palindrome = 3)
		cout << "There's way too much arguments :)\n";
		cout << HELP;
		return 0;
	}*/
}