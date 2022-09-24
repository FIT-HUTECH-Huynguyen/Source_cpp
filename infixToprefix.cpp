#include <iostream>
#include <string.h>
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
		Node* tempNode = stack;
		x = tempNode->data;
		stack = tempNode->next;
		delete tempNode; 
	}
	return x; 
}
char peek(Stack stack){
	char x ; 
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
void reverse(char data[]){
	int size = strlen(data);
	for(int i = 0 ; i < size/2 ; i++){
		char temp = data[i];
		data[i] = data[size-1-i];
		data[size-1-i] = temp;
	}
}
int infixToPrefix(Stack stack , char prefix[]){
	stack = createNode(strlen(prefix));
	int size = strlen(prefix) , j = 0 ;
	char temp[size];
	for(int i = 0 ; i < size ; i++){
		if(isOperand(prefix[i])){
			temp[j++] = prefix[i];
		}
		else if(prefix[i] == '('){
			push(stack,prefix[i]);
		}
		else if(prefix[i] == ')'){
			while(stack != NULL && peek(stack) != '('){
				temp[j++] = pop(stack);
			}
			if(stack != NULL && peek(stack) != '('){
				return -1;
			}else{
				pop(stack);
			}
		}
		else{
			while(!isEmpty(stack)&&prec(prefix[i]) <= prec(peek(stack))){
				temp[j++] = pop(stack);
			}
			push(stack,prefix[i]);
		}
	}
	while(stack != NULL){
		temp[j++] = pop(stack);
	}
	temp[j++] ='\0';
	reverse(temp);
	puts(temp);
}
int main(){
	Stack stack;
	init(stack);
	char data[] = "5*(1+2)";
	/*	data test 
		1) 2/3 + 4*5 
		2) (1+2)*5
	*/
	reverse(data);
	int size = strlen(data);
	for(int i = 0 ; i < size ; i++){
		if(data[i] == '('){
			data[i] = ')';
		}
		else if(data[i] == ')'){
			data[i] = '(';
		}
	}
	infixToPrefix(stack,data);
}
