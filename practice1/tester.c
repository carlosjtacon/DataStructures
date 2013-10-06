#include "stack.cpp"
#include <stdlib.h>
#include <string.h>



int _tmain(int argc, _THCAR* argv[]){

	Stack<char> mystack;
	char input[11] = "0123456789";

	mystack.makeNull();

	for (int i = 0; i < strlen(input); i++){
		
		mystack.push(input[i]);
		cout << "Pushing: " << input[i] << endl;
	}

	while(!mystack.isEmpty()){

		cout << "Poping: " << mystack.pop() << endl;
	}

	system("Pause");

}
