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
	return stack==NULL;
}
Node* createNode(char x){
	Node* newNode = new Node();
	newNode->data = x ;
	newNode->next = NULL;
	return newNode;
}
void push(Stack &stack , char x){
	Node* tempNode = createNode(x);
	tempNode->next = stack;
	stack = tempNode;
}
char  pop(Stack &stack){
	char x;
	if(stack != NULL){
		Node* tempNode = stack;
		x = tempNode->data ; 
		stack = tempNode->next;
		delete tempNode;	
	}
	return x;
}
char peek(Stack stack){
	char x;
	if(stack == NULL){
		return 'N';
	}else{
		Node* tempNode = stack;
		x = tempNode->data;	
	}
	return x;
}
int prec(char ch){
	switch(ch){
		case '+': case '-':
			return 1;
		case '*': case '/' :
			return 2;
		case '^':
			return 3;
	}
	return -1;
}
int isNumberics(char chars){
	return (chars >= '1' && chars <= '9') ;
}
int infixConvertPostfix(Stack stack , char infix[]){
	stack = createNode(strlen(infix));
	int size = strlen(infix) , k = 0;
	char temp[size]; 
	for(int i = 0 ; i < size ; i++){
		if(isNumberics(infix[i])){
			temp[k++] = infix[i];
		}
		else if(infix[i] == '('){
			push(stack,infix[i]);
		}
		else if(infix[i] == ')'){
			while(stack != NULL &&peek(stack) != '('){
				temp[k++] = pop(stack);
			}
			if(stack != NULL && peek(stack) != '('){
				return -1;
			}else{
				pop(stack);
			}
		}
		else{
			while(!isEmpty(stack) && prec(infix[i]) <= prec(peek(stack))){
				temp[k++] = pop(stack);
			}
			push(stack,infix[i]);
		}
	}
	
	while(stack != NULL){
		temp[k++] = pop(stack);
	}
	temp[k++] = '\0';
	puts(temp);
}
int main(){
	Stack stack;
	int x ; 
	init(stack);
	char infix[] = "2/3+4*5";
	/* Data test 
	1) 2*(3/2-1)+5*(4-1)*7+1*(9-4)
	2) 2/3+4*5 
	*/
	infixConvertPostfix(stack,infix);
	return 0 ;
}
