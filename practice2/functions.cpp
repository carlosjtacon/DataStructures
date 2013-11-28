#include "functions.h"

int isPalindrome(string input){
	//get string into stack
	Stack<char> stack;
	for(unsigned int i=0; i<input.size(); i++){
		stack.push(input[i]);
	}
	//get string into queue
	Queue<char> queue;
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
	for (unsigned int i = 0; i < strlen(input); ++i)
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
	for (unsigned int i = 0; i < input.size(); ++i)
	{
		if (input[i]!=' ')
		{
			output+=input[i];
		}
	}
	return output;
}
int numWords(string input)
{
	int cont = 1;
	int length = input.length();
	for (int i = 0; i < length; ++i)
	{
		if (input[i] == ' ' && input[i+1]!=' ' && input[i+1]!='\0')
		{
			cont++;
		}
	}
	return cont;
}