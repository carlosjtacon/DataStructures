template <class Type> 
class Cell{
private:
    Type element;
    Cell* next;
};

template <class Type>
class Stack{
private:
	Cell<Type>* top;
    
public:
    void makeNull(void);
    Type getTop(void);
    int isEmpty(void);
    int isFull(void);     
    void push(Type*);
    Type pop(void);
};

//methods implementation

template <class Type> void Stack<Type>::makeNull(void){
    top = 0;
}

template <class Type> Type Stack<Type>::getTop(void){
    return *top;   
}    

template <class Type> int Stack<Type>::isEmpty(void){
    return (top == 0);   
} 

template <class Type> void Stack<Type>::push(Type* input){
	//create Cell
	Cell<Type> newElement;
	newElement.element = input;
    //if is empty init top
    if(isEmpty()){
		newElement.next = 0;
        top = newElement;
	}
    else{
        newElement.next = *top;
        top = &newElement;
	}
}

template <class Type> Type Stack<Type>::pop(void){
    Type aux;
    aux = *top.element;//get top's element value
    top = *top.next;//get following stack element
    return aux;
}
