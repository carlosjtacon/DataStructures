#include "stack.cpp"
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


int main(int argc, const char* argv[]){

	Stack mystack;
	char input[11] = "0123456789";

	for (int i = 0; i < strlen(input); i++){
		
		mystack.push(input[i]);
		cout << "Pushing: " << input[i] << endl;
	}

	while(!mystack.isEmpty()){

		cout << "Poping: " << mystack.pop() << endl;
	}
	return 0;

}
