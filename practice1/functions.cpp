#include "functions.h"

int isPalindrom(string input){
	//get string into stack
	Stack stack;
	for(unsigned int i=0; i<input.size(); i++){
		stack.push(input[i]);
	}
	//get string into queue
	Queue queue;
	for(unsigned int i=0; i<input.size(); i++){
		queue.enqueue(input[i]);	
	}

	//compare both structures
	for(unsigned int i=0; i<input.size(); i++){
		if(stack.pop() != queue.dequeue()){
			return 0;
		}
	}
	return 1;
}

string rmSpace(const char* input)
{
	//remove spaces in the input string
	string output ("\0");
	for (int i = 0; i < strlen(input); ++i)
	{
		if (input[i]!=' ')
		{
			output+=input[i];
		}
	}
	return output;
}
string rmSpace(string input)
{
	//remove spaces in the input string
	string output ("\0");
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i]!=' ')
		{
			output+=input[i];
		}
	}
	return output;
}