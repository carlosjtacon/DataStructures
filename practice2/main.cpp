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
	
	if (argc > 3){

		cout << "there's way too much arguments :) \n";
		return 0;

	}else if(argc ==2){ //just the word to be checked if palindrome or not

		//input = argv[1];
		input=rmSpace(argv[1]);
		original=argv[1];

	}else if(argc == 3){//-f modifier & name of file to be checked

		if(strcmp(argv[1],"-f")==0){// if everything is ok
			
			ifstream inputFile (argv[2]);
			if(inputFile.is_open()){
				string tmp;
				while(getline(inputFile, tmp))
					original+=tmp;
				input=rmSpace(original);
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
	if(isPalindrome(input)){
		cout << original + " is palindrome \n";
	}else{
		cout << original + " is not palindrome \n";
	}
	cout << endl;
	cout << "_____________________________" << endl;
	return 0;
}
