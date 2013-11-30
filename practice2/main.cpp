#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include "queue.h"
#include "stack.h"
#include "functions.h"

using namespace std;

int main()
{
	
	#define HELP "Usage: $ palindrome [parameter]\nWhere: parameter is one of:\n\t\t-h (help)\n\t\t-k (read from keyboard)\n\t\t-f file (read from file)\n\t\t-d letter (remove all palindromes which start by this letter)\n\t\t-s (show data)\n\t\t-q (exit)\n";
	
	string input ("\0");
	string original ("\0");
	string command;

	//always print the help at the begin
	cout << HELP;	

	do
	{
		//print a new prompt until -q
		cout << "$ palindrome ";

		//read command
		getline(cin, command, '\n');

		//create our own argc
		int myArgc = numWords(command);

		//create our own argv
		vector<string> myArgv;
		istringstream iss(command);
		string token;
		while(getline(iss, token, ' '))
		{
			myArgv.push_back(token);
		} 

		//main method
		if (myArgc == 1)
		{
			if (myArgv.at(1) == "-h")
			{
				cout << HELP;
			}
			else if (myArgv.at(1) == "-s")
			{
				//show in the screen the number of queues in the list, the total number of palindromes in each queue and their starting letter
			}
			else if (myArgv.at(1) == "-k")
			{
				int i = 0;

				while(original!="q")
				{
					cout << "(" << i << ") "; i++;
					getline(cin, original, '\n');
					input = rmSpace(original);

					if (isPalindrome(input) && original!="q")
					{
						//add original to list
					}
				} 
			}
			else
			{
				cout << "Paremeter unknown " << myArgv.at(1) << endl;
				cout << HELP;
			}
		}
		else if (myArgc == 2)
		{
			if (myArgv.at(1) == "-f")
			{
				ifstream inputFile (myArgv.at(2));
				if(inputFile.is_open())
				{
					string tmp;
					while(getline(inputFile, tmp))
					{
						if (isPalindrome(tmp))
						{
							//add tmp to list
						}
					}
				}	
				else
				{
					//filename does not exists
					cout << "The file couldn't be opened, maybe doesn't exists :(\n";
					cout << HELP;
				}
			}
			else if (myArgv.at(1) == "-d")
			{
				//Remove all palindromes which start by a specific letter
			}
			else
			{
				cout << "Paremeter unknown " << myArgv.at(1) << endl;
				cout << HELP;
			}
		}
		else if (myArgc > 2)
		{
			cout << "There's way too much arguments :')\n";
			cout << HELP;
		}
	}
	while(command != "-q");
}