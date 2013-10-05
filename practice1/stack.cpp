template <class Type>

class Cell{
private:
    Type element;
    Cell* next;
}

class Stack{
private:
    Cell* top;
    
public:
    void makeNull(void);
    Type top(void);
    int isEmpty(void);
    int isFull(void);     
    void push(Cell);
    Type pop(void);
};

//methods implementation

void Stack::makeNull(void){
    top = 0;
}

Type Stack::clear(void){
    return *top;   
}    

int Stack::isEmpty(void){
    return (top == 0);   
} 

void push(Cell input){
    //if is empty init top
    if(isEmpty())
        top = &input;
    else
        input.next = *top;
        top = &input;
}

Type pop(void){
    Type aux;
    aux = *top.element;//get top's element value
    top = *top.next;//get following stack element
    return aux;
}
