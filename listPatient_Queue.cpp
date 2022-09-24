#include <iostream>
using namespace std;
typedef struct Patient{
	int number;
	char name[31];
	int  age;
	int temp;
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
void viewHead(Queue queue , patient data , int n){
	Node* tempNode = queue.head;
	if(tempNode == NULL){
		cout<<"Not View !\n";
	}else{
		for(int i = 0 ; i < n ; i++){
			data = tempNode->data;
			queue.head = tempNode->next;
		}
	}
}
patient remove(Queue &queue , patient &data){
	if(tempNode != NULL){
		Node* tempNode = queue.head;
		data = tempNode->data;
		queue.head = tempNode->next;
		delete tempNode;
		return data;
	}
}
int countPatientExamined(Queue queue ){
	int count = 0;
	Node* tempNode = queue.head;
	if(tempNode == NULL) return NULL;
	else{
		while(tempNode != NULL){
			if(tempNode->data.temp == 0){
				count++;
			}
		}
		return count++;
	}
}
int countPatientUnexamined(Queue queue){
	int count = 0 ;
	Node* tempNode = queue.head;
	if(tempNode == NULL) return NULL;
	else{
		while(tempNode != NULL){
			if(tempNode->data.temp == 1){
				count++;
			}
		}
		return count;
	}
}
void showPaintedUnexamined(Queue queue){
	Node* tempNode = queue.head;
	if(tempNode == NULL) cout<<"Queue is empty ! \n";
	else{
		while(tempNode != NULL){
			if(tempNode->data.temp == 1){
				remove(tempNode,tempNode->data);
			}
			output(tempNode.data);
		}
	}
}
