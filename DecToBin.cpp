#include <iostream>
#include <string.h>
using namespace std;

typedef struct node{
	unsigned  data;
	struct node* next;
}Node;

typedef Node* Stack;

void init(Stack &stack){
	stack = NULL;
}
int isEmpty(Stack stack){
	return stack==NULL;
}
Node* createNode(unsigned x){
	Node* newNode = new Node();
	newNode->data = x ;
	newNode->next = NULL;
	return newNode;
}
void push(Stack &stack , unsigned x){
	Node* tempNode = createNode(x);
	tempNode->next = stack;
	stack = tempNode;
}
int  pop(Stack &stack , unsigned &x){
	if(stack == NULL)
		return -1;
	else{
		Node* tempNode = stack;
		x = tempNode->data ; 
		stack = tempNode->next;
		delete tempNode;	
	}
	return 1;
}
void showStack(Stack stack){
	if(stack == NULL){
		cout<<"Stack is empty !\n";
	}else{
		while(stack!= NULL){
			unsigned x = 0 ;
			pop(stack,x);
			cout<<x;
		}
	}
}
//cau1 : chuyen doi thap phan sang nhi phan
void convert(Stack &stack , int data ){
	while(data != 0 ){
		int temp = data % 2 ; 
		push(stack , temp);
		data = data / 2;
	}
}
void showResult(Stack &stack){
	unsigned x = 0;
	while(stack != NULL){
		if(pop(stack,x)==1){
			//pop(stack,x);
			if( x < 10){
				x += 48;
			}else{
				x += 55;
			}
			cout<<(char) x;
		}
	}
}
int main(){
	Stack stack;
	int x ; 
	init(stack);
	cin>>x;
	convert(stack ,x);
	showResult(stack);
}
