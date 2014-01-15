#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include "queue.h"
#include "stack.h"
#include "tree.h"
#include "functions.h"

using namespace std;

int main()
{
	
	#define HELP "Usage: $ palindrome [parameter]\nWhere: parameter is one of:\n\t\t-h (help)\n\t\t-k (read from keyboard)\n\t\t-f file (read from file)\n\t\t-d (remove all words that are not palindromes)\n\t\t-s (search and show words that are repeated in the tree)\n\t\t-t (traverse the tree and show all palindrome words)\n\t\t-bst (print binary search tree structure)\n\t\t-q (exit)\n";
	
	string input ("\0");
	string original ("\0");
	string command;

	Tree tree;

	//always print the help at the begin
	cout << HELP;	

	do
	{
		//print a new prompt until -q
		cout << "$ palindrome ";

		//read command
		getline(cin, command, '\n');

		//create our own argv
		vector<string> myArgv;
		istringstream iss(command);
		string token;
		while(getline(iss, token, ' '))
		{
			myArgv.push_back(token);
		} 

		//create our own argc
		int myArgc = myArgv.size();

		//main method
		if (myArgc == 1)
		{
			if (myArgv[0] == "-h")
			{
				//print help
				cout << HELP;
			}
			else if (myArgv[0] == "-s")
			{
				//Search and show on the screen those words that are repeated in the search tree 
				//(one word is repeated if it appears at least two times in the tree. 
				//The number of repetitions is not relevant). 
				//For each word you have to show whether or not is palindrome.
				tree.search();
			}
			else if (myArgv[0] == "-k")
			{
				//write words in the keyboard to add it to the BST

				int i = 0;

				cout << "(-q to exit)" << endl;

				while(1)
				{
					cout << "(" << i << ") "; i++;
					getline(cin, original, '\n');
					
					if (original.compare("-q")==0)
						break;
					
					if (original.find(" ") == string::npos && original.size() != 0)//no blank spaces
						tree.add(original);
					else
						cout << "Must be a single word!" << endl;
				}
			}
			else if (myArgv[0] == "-t")
			{
				//traverse inorder showing palindromes
				tree.traverse();
			}
			else if (myArgv[0] == "-d")
			{
				//Remove all words that are not palindromes keeping the structure of the search tree.
				tree.removeAllNotPalindromes();
			}
			else if (myArgv[0] == "-bst")
			{
				//show the BST properties
				tree.show();
			}
			else
			{
				if (myArgv[0] != "-q")
				{
					cout << "Paremeter unknown " << myArgv[0] << endl;
				}
			}
		}
		else if (myArgc == 2)
		{
			if (myArgv[0] == "-f")
			{
				//read words from file

				int cont0 = 0, cont1 = 0;

				ifstream inputFile (myArgv[1]);
				if(inputFile.is_open())
				{
					string tmp;
					while(getline(inputFile, tmp))
					{
						if (tmp.find(" ") == string::npos)
						{
							//add tmp in the tree
							tree.add(tmp);
							cont1++;
						}
						else
						{
							//space found
							cout << "Must be a single word!, " << tmp << " not added." << endl;
							cont0 ++;
						}
					}
					cout << cont1 << " words inserted." << endl;
					cout << cont0 << " lines that were not words, not inserted." << endl;
				}	
				else
				{
					//filename does not exists
					cout << "The file couldn't be opened, maybe doesn't exists :(\n";
				}
			}
			else
			{
				cout << "Paremeter unknown " << myArgv[0] << endl;
			}
		}
		else if (myArgc > 2)
		{
			cout << "There's way too much arguments :')\n";
		}
	}
	while(command != "-q");
}