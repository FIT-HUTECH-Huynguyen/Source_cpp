#include <iostream>
using namespace std;
typedef struct Patient{
	int number;
	char name[31];
	int  age;
}patient;

typedef struct node{
	patient data;
	strutct node* next;
}Node;
typedef struct QUEUE{
	Node* head;
	Node* tail;
}Queue;

void init(Queue &queue){
	queue.head = NULL;
	queue.tail = NULL;
}
int isEmpty(Queue queue){
	return (queue.head == NULL);
}
Node* createNode(patient data){
	Node* tempNode = new Node ;
	tempNode->data = data;
	tempNode->next = NULL;
	return tempNode;
}
void insert(Queue &queue){
	Node* tempNode = createNode(data);
	if(queue == NULL)
	 	queue.head = tempNode;
	else{
		tempNode->next =queue.head->next;
		queue.head->next = tempNode;
	}
}
