#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
	char data;
	float data_f;
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

Node* createNode1(float data){
	Node* tempNode = new Node();
	tempNode->data_f = data;
	tempNode->next = NULL;
	return tempNode;
}


void push(Stack &stack , char data){
	Node* tempNode = createNode(data);
	if(stack!=NULL)
		tempNode->next = stack;
	stack = tempNode;
}

void push1(Stack &stack , float data){
	Node* tempNode = createNode1(data);
	if(stack!=NULL)
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

float popFloat(Stack &stack){
	float x ; 
	if(stack != NULL){
		Node* tempNode = stack ; 
		x = tempNode->data_f;
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
void show(Stack stack){ 
	if(stack != NULL){
		printf("[");
		while(stack != NULL){
			printf(" %c ", stack->data);
			stack = stack->next;
		}
		printf("]\n");
	}
}
void showFloat(Stack stack){ 
	if(stack != NULL){
		printf("[");
		while(stack != NULL){
			printf(" %f ", stack->data_f);
			stack = stack->next;
		}
		printf("]\n");
	}
}
int isNumberics(char number){
	return (number >='1' && number <= '9');
}
float calculateValue(float numberA , char x , float numberB){
	float fResult = 0 ;
	if(x == '+'){
		fResult = numberA + numberB;
	}
	if(x == '-'){
		fResult = numberA - numberB;
	}
	if(x == '*'){
		fResult = numberA * numberB;
	}
	if(x == '/'){
		fResult = numberA / numberB;
	}
	if(x == '^'){
		fResult = 1 ;
		for(int i = 1 ; i < numberB;i++){
			fResult = fResult*numberA;
		}
	}
//	char strResult = (char) fResult;
	return fResult;
}
int calculateInfix(char infix[]){
	Stack stackN = new Node();
	init(stackN);
	Stack stackO = new Node();
	init(stackO);
	
	int size = strlen(infix);
	float result = 0;
	for(int i = 0 ; i < size ; i++){	
		if(isNumberics(infix[i])){
			float num = infix[i] - '0';
			push1(stackN,num);
		}
		else if(infix[i] == '('){
			push(stackO,infix[i]);
		}
		else if(infix[i] == ')'){
			while(!isEmpty(stackO) && peek(stackO) != '('){	
				float numberA , numberB ;
				char x;
				numberA = popFloat(stackN);
				numberB = popFloat(stackN);
				x = pop(stackO);
				float value = calculateValue(numberA,x,numberB);
				push1(stackN,value);		
//				showFloat(stackN);
			}
			if(peek(stackO) == '(')
				pop(stackO);
		}
		else{
			while(!isEmpty(stackO) && prec(infix[i]) <= prec(peek(stackO))){
				float numberA , numberB;
				char x;
				numberA = popFloat(stackN);
				numberB = popFloat(stackN);
				x = pop(stackO);
				float value = calculateValue(numberA,x,numberB);
//				printf("calculateValue: [%f] \n", value);
				push1(stackN,value);
			}
			push(stackO,infix[i]);
		}
		
//		show(stackO);
//		showFloat(stackN);	
	}
	
	while(stackO != NULL){
		float numberA , numberB ;
		char x;
		numberA = popFloat(stackN);
//		printf("numberA: %f \n", numberA);
		numberB = popFloat(stackN);
//		printf("numberB: %f \n", numberB);
		x = pop(stackO);
		float value = calculateValue(numberA,x,numberB);
//		printf("calculateValue: [%f] \n", value);
		push1(stackN,value);		
//		show(stackO);
//		showFloat(stackN);	
	}
	result= popFloat(stackN);
	return result;
}
int main(){
	char data[] = "1+(2*3)";
	
	cout<<calculateInfix(data);
}
