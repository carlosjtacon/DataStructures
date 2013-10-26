#include "palindrom.h"

int isPalindrom(std::string input){
	//get string into stack
	Stack stack;
	for(int i=0; i<input.size(); i++){
		stack.push(input[i]);
	}
	//get string into queue
	Queue queue;
	for(int i=0; i<input.size(); i++){
		queue.enqueue(input[i]);	
	}

	//compare both structures
	for(int i=0; i<input.size(); i++){
		if(stack.pop() != queue.dequeue()){
			return 0;
		}
	}
	return 1;
}
