#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
	char data;
	struct node* next;
}Node;

typedef Node* Stack;

void init(Stack &stack){
	stack = NULL;
}
int isEmpty(Stack stack){
	return stack == NULL;
}
Node* createNode(char data){
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->next = NULL;
	return tempNode;
}
void push(Stack &stack , char data){
	Node* tempNode = createNode(data);
	tempNode->next = stack;
	stack = tempNode;
}
char pop(Stack &stack){
	char x ; 
	if(stack != NULL){
		Node* tempNode = stack ; 
		x = tempNode->data;
		stack = tempNode->next;
		delete tempNode;
	}
	return x;
}
char peek(Stack stack){
	char x;
	if(stack != NULL){
		Node* tempNode = stack;
		x = tempNode->data;
	}
	return x;
}
int prec(char x){
	switch(x){
		case '+': case '-':
			return 1;
		case '*': case'/':
			return 2;
		case '^':
			return 3; 
	}
	return -1 ;
}
int isOperand(char number){
	return (number >='1' && number <= '9');
}
char calculateValue(char numberA , char x , char numberB){
	float fResult = 0 ;
	if(x = '+'){
		fResult = (double)numberA + (double)numberB;
	}
	if(x = '-'){
		fResult = (double)numberA - (double)numberB;
	}
	if(x = '*'){
		fResult = (double)numberA * (double)numberB;
	}
	if(x = '/'){
		fResult = (double)numberA / (double)numberB;
	}
	if(x = '^'){
		fResult = 1 ;
		for(int i = 1 ; i < (int) (double)numberB;i++){
			fResult = fResult*(double)numberA;
		}
	}
	char strResult = (char) fResult;
	return strResult;
}
int calculateInfix(char infix[]){
	Stack stackN = new Node();
	Stack stackO = new Node();
	int size = strlen(infix);
	float result = 0;
	for(int i = 0 ; i < size ; i++){
		if(isOperand(infix[i])){
			push(stackN,infix[i]);
		}
//		else if(infix[i] == '('){
//			push(stackN,infix[i]);
//		}
//		else if(infix[i] == ')'){
//			while(!isEmpty(stackO) && peek(stackO) != '('){	
//				char numberA , numberB , x;
//				numberA = pop(stackN);
//				numberB = pop(stackN);
//				x = pop(stackO);
//				push(stackN,calculateValue(numberA,x,numberB));		
//			}
//			if(peek(stackO) == ')')
//				pop(stackO);
//		}
		else{
			while(!isEmpty(stackO) && prec(infix[i]) <= prec(peek(stackO))){
				char numberA , numberB , x;
				numberA = pop(stackN);
				numberB = pop(stackN);
				x = pop(stackO);
				push(stackN,calculateValue(numberA,x,numberB));
			}
			push(stackO,infix[i]);
		}
	}
	while(stackO != NULL){
		char numberA , numberB , x;
		numberA = pop(stackN);
		numberB = pop(stackN);
		x = pop(stackO);
		push(stackN,calculateValue(numberA,x,numberB));
	}
	char strResult ;
	strResult = pop(stackN);
	result = (double)strResult;
	return result;
}
int main(){
	char data[] = "1+2";
	cout<<calculateInfix(data);
}
