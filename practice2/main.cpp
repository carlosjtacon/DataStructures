#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include <string.h>
#include "functions.h"
#include <fstream>

using namespace std;

int main(int argc, const char* argv[]){
	
	string input ("\0");
	string original ("\0");
	
	if (argc > 3)
	{

		cout << "there's way too much arguments :) \n";
		return 0;

	}
	else if(argc ==2)
	{

		if (strcmp(argv[1],"-f")==0)
		{
			cout << "which file do you want to open? pass it in arguments :)";
			return 0;
		}
		else if (strcmp(argv[1],"-k")==0)
		{
			//main, string separated by enter
		}

	}
	else if(argc == 3)
	{

		if(strcmp(argv[1],"-f")==0)
		{	// if everything is ok
			
			ifstream inputFile (argv[2]);
			if(inputFile.is_open())
			{
				string tmp;
				while(getline(inputFile, tmp))
					original+=tmp;
				input=rmSpace(original);
			}	//now we've got the file text in 'input' string
			else
			{
				cout << "the file couldn't be opened, maybe doesn't exists \n";
				return 0;
			}

		}
		else if (strcmp(argv[1],"-k")==0)
		{
			cout << "this parameter is used without arguments!";
			return 0;
		}
		else
		{	// if wrong parameter
			cout << "paremeter unknown " << argv[1] << endl;
			return 0;
		}
	}
}
