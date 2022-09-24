#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
	float data;
	struct node* next;
}Node;

typedef Node* Stack;

void init(Stack &stack){
	stack = NULL;
}

int isEmpty(Stack stack){
	return stack == NULL;
}

Node* createNode(float data){
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->next = NULL;
	return tempNode;
}
void push(Stack &stack , float data){
	Node* tempNode = createNode(data);
	if(stack!=NULL)
		tempNode->next = stack;
	stack = tempNode;
}
float pop(Stack &stack){
	float x ; 
	if(stack != NULL){
		Node* tempNode = stack ; 
		x = tempNode->data;
		stack = tempNode->next;
		delete tempNode;
	}
	return x;
}
float peek(Stack stack){
	float x;
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
int isNumberics(char number){
	return (number >='1' && number <= '9');
}
char isOperator(char oper){
	return (oper == '+' ||oper == '-' ||oper == '*' ||oper == '/' ||oper == '^');
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
void reverse(char data[]){
	int size = strlen(data);
	for(int i = 0 ; i < size/2 ; i++){
		char temp = data[i];
		data[i] = data[size-1-i];
		data[size-1-i] = temp;
	}
}
void showFloat(Stack stack){ 
	if(stack != NULL){
		printf("[");
		while(stack != NULL){
			printf(" %f ", stack->data);
			stack = stack->next;
		}
		printf("]\n");
	}
}
float calculateInfix(char prefix[]){
	Stack stack = new Node();
	init(stack);
	int size = strlen(prefix);
	float result = 0;
	for(int i = 0 ; i < size ; i++){	
		if(isNumberics(prefix[i])){
			float num = prefix[i] - '0';
			push(stack,num);
		}
		else if(isOperator(prefix[i])){
			float numberA , numberB;
			char x;
			numberA = pop(stack);
			numberB = pop(stack);
			x = prefix[i];
			float value = calculateValue(numberA,x,numberB);
			push(stack,value);
		}
		showFloat(stack);
	}
	result= pop(stack);
	return result;
}
int main(){
	char data[] = "+*23/45";
	reverse(data);
	cout<<calculateInfix(data);
}
