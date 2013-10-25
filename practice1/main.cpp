#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include "stack.cpp"
#include "queue.cpp"
#include <string.h>

using namespace std;

int main(int argc, const char* argv[]){
	
	String input=0;
	
	if (argc > 2){
		cout << "there's way too much arguments :)";
		return 0;
	}else if(argc ==1){ //just the word to be checked if palindrom or not
		input = argv[0];		
	}else(argc == 2){//-f modifier & name of file to be checked
		if(strcmp(argv[0],"-f")==0){
			cout << "paremeter unknown " + argv[0];
		}else{// if everything is ok
			std::ifstream inputFile (argv[1]);
			if(inputFile.is_open()){
				std::string tmp;
				while(std::getline(inputFile, tmp)
					input+=tmp;
			}//now we've got the file text in 'input' string
			else{
				cout << "the file couldn't be opened, maybe doesn't exists";
				return 0;
			}
		}
	}

	if(isPalindrom(input)){
		cout << input + "is palindrom";
	}else{
		cout << input + "is not palindrom";
	}
	return 0;
}