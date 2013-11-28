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
	#define HELP "Usage: ./palindrome [parameter]\nWhere: parameter is one of:\n\t\t-k (read from keyboard)\n\t\t-f file (read from file)\n";
	string input ("\0");
	string original ("\0");
	
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
			/*
			 * INSERTAR
			 */
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

					/*
					 * INSERTAR
					 */
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
	}
}
