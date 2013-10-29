#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include <string.h>
#include "palindrom.h"
#include <fstream>

using namespace std;

int main(int argc, const char* argv[]){
	
	string input ("\0");
	
	if (argc > 3){

		cout << "there's way too much arguments :) \n";
		return 0;

	}else if(argc ==2){ //just the word to be checked if palindrom or not

		//input = argv[1];
		std::getline(input, argv[1], ' ');

	}else if(argc == 3){//-f modifier & name of file to be checked

		if(strcmp(argv[1],"-f")==0){// if everything is ok
			
			ifstream inputFile (argv[2]);
			if(inputFile.is_open()){
				string tmp;
				while(getline(inputFile, tmp, " "))
					input+=tmp;
			}//now we've got the file text in 'input' string
			else{
				cout << "the file couldn't be opened, maybe doesn't exists \n";
				return 0;
			}

		}else{// if wrong parameter
			cout << "paremeter unknown " << argv[1] << endl;
			return 0;
		}
	}

	cout << "_____________________________" << endl;
	cout << endl;
	if(isPalindrom(input)){
		cout << input + " is palindrom \n";
	}else{
		cout << input + " is not palindrom \n";
	}
	cout << endl;
	cout << "_____________________________" << endl;
	return 0;
}
