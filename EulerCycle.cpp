#include<iostream>
#include<stdio.h>
#define MAX 10 
using namespace std;
typedef struct NODE{
	int data;
	struct NODE* next;
}Node;
typedef struct STACK{
	Node* head;
}Stack;
typedef struct GRAPH{
	int size;
	int arr[MAX][MAX];
}Graph;
int ReadFile(char nameFile[100] , Graph &graph){
	FILE* f ; 
	f = fopen(nameFile ,"rt");
	if( f == NULL){
		cout<<"Don't open file\n";
		return 0;
	}
	fscanf(f,"%d",&graph.size);
	for(int i = 1 ; i <= graph.size ; i++){
		for(int j = 1 ; j <= graph.size ; j++){
			fscanf(f,"%d",&graph.arr[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void Output(Graph graph){
	cout<<graph.size<<"\n";
	for(int i = 1 ; i <= graph.size ; i++){
		for(int j = 1 ; j <= graph.size; j++){
			cout<<graph.arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
// initialize
void init(Stack &stack){
	stack.head = NULL;
}
// check empty
int isEmpty(Stack stack){
	return stack.head == NULL;
}
// create stack
Node* createStack(int data){
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->next = NULL;
	return tempNode;
}
// push into stack
void push(Stack &stack,int data){
	Node* tempNode =createStack(data);
	tempNode->next = stack.head;
	stack.head = tempNode;
}
// pop stack
int pop(Stack &stack){
	int rm_data = -1;
	if(!isEmpty(stack)){
		Node* tempNode = stack.head;
		stack.head = tempNode->next;
		rm_data = tempNode->data;
		delete tempNode;
	}
	return rm_data;
}

// peek stack
int peek(Stack stack){
	int peek_data ;
	if(!isEmpty(stack)){
		Node* tempNode = stack.head;
		stack.head = tempNode->next;
		peek_data = tempNode->data;
	}
	return peek_data;
}
// find the way 
void findTheWay(int pos , Graph &graph , Stack &stack){
	for(int i = 1 ; i <= graph.size ; i++){
		if(graph.arr[pos][i] != 0){
			graph.arr[pos][i] = graph.arr[i][pos] = 0;
			findTheWay(i ,graph,stack);
		}
	}
	push(stack,pos);
}
// check connect graph
void visit(Graph graph , int label[MAX] , int i){
	for(int j = 0 ; j < graph.size ; j++){
		if(graph.arr[i][j] != 0 && label[j] != label[i]){
			label[j] = label[i];
			visit(graph,label,j);
		}

	}
}
int checkConnectGraph(Graph graph){
	int label[MAX] , count= 0 , temp = 0;
	int flag = 0;
	for(int i = 1 ; i <= graph.size ; i++){
		label[i] = 0 ;
	}
	for(int i = 1 ; i <= graph.size ; i++){
		if(label[i] == 0){
			count++;
			label[i] = count ;
		}
		visit(graph,label,i);
	}
	return count; 
}
//Check Euler Cycle
int checkEulerCycle(Graph graph){
	int pos = 1 , min = pos, count = 0 , check = 0; 
	for(int i = 1 ; i <= graph.size ; i++){
		count = 0;
		for(int j = 1 ; j <= graph.size; j++){
			if(graph.arr[i][j] != 0){
				count++;
			}
		}
		if(count %2 == 0 && i <= min){
			min = i ;
			pos = min; 
		}
		if(count % 2 == 0){
			check++;
		}
	}
	if(check != graph.size){
		return 0;
	}
	Graph tempGraph = graph;
	Stack stack ;
	init(stack);
	findTheWay(pos,tempGraph,stack);
	//Check way 
	for(int i = 1 ; i <= graph.size ; i++){
		for(int j = 1 ; j <= graph.size;j++){
			if(tempGraph.arr[i][j] == 1){
				return 0;
			}
		}
	}
	//check connect graph
	if(checkConnectGraph(graph)!= 1){
		return 0;
	}
	// check Euler Cycle 
	Node* tempNode = stack.head;
	int head_data = stack.head->data;
	int tail_data ;
	while(tempNode != NULL){ 
		if(tempNode->next == NULL){
			tail_data = tempNode->data;
			
		}
		tempNode = tempNode->next;
	}
	if(head_data != tail_data){
		return 0;
	}
	cout<<"Euler Cycle : \n";
	while(stack.head != NULL){
		cout<<stack.head->data<<"\t";
		stack.head = stack.head->next;
	}
	return 1;
}

int checkEulerWay(Graph graph){
	int pos = 0 , count = 0 , min = 0 , check = 0;
	for(int i = 1 ; i <= graph.size ; i++){
		count = 0;
		for(int j = 1 ;j <= graph.size ; j++){
			if(graph.arr[i][j] != 0){
				count++;
			}
			
		}
		if(count % 2 != 0 ){
			pos =i ;
		}cout<<i<<"-"<<count<<"-"<<pos<<"\n";
		if(count % 2 != 0){
			check++;
		}
	}
	if(check != 2){
		return 0;
	}
	Graph tempGraph = graph ;
	Stack stack ;
	init(stack);
	findTheWay(pos,tempGraph,stack);
	//check way
	for(int i = 1 ; i <= graph.size ; i++){
		for(int j = 1 ; j <= graph.size;j++){
			if(tempGraph.arr[i][j] == 1){
				return 0;
			}
		}
	}
	//check connect graph
	if(checkConnectGraph(graph)!= 1){
		return 0;
	}
	//check Euler way
	Node* tempNode = stack.head;
	int head_data = stack.head->data;
	int tail_data ;
	while(tempNode != NULL){ 
		if(tempNode->next == NULL){
			tail_data = tempNode->data;
			
		}
		tempNode = tempNode->next;
	}
	if(head_data == tail_data){
		return 0;
	}
	cout<<"Euler Way : \n";
	while(stack.head != NULL){
		cout<<stack.head->data<<"\t";
		stack.head = stack.head->next;
	}
	return 1;
	
}
int main(){
	Graph graph;
	if(ReadFile("C:/graph/test3.txt",graph) == 1){
		Output(graph);
		if(!checkEulerCycle(graph)){
			//cout<<"Khong co chu trinh euler !";
			if(!checkEulerWay(graph)){
				cout<<"Khong co duong di euler !";
			}
		}
		
	}
	return 0;
	
}


