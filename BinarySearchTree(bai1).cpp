#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* root;

void init(Node* &root){
	root = NULL;
}
int isEmpty(Node* root){
	return (root == NULL);
}
Node* createNode(int data){
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->left = NULL;
	tempNode->right= NULL;
	return tempNode;
}
void insertNode(Node* &root , int data){
	if(root == NULL){
		root = createNode(data);
	}
	else{
		if(data == root->data){
			return;
		}
		else if (data < root->data){
			insertNode(root->left,data);
		}
		else if (data > root->data){
			insertNode(root->right,data);			
		}
	}
}
int removeNode(Node* &root , int x){
	Node* temp, *repeat, *froot;
	if(root == NULL){
		return 0;
	}else{
		if(x < root->data)
			return removeNode(root->left,x);
		if( x > root->data)
			return removeNode(root->right,x);
		temp = root;
		if(root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else{
			froot = temp;
			repeat = root->right;
			while(repeat->left != NULL){
				froot = repeat;
				repeat = repeat->left;
			}
			temp->data = repeat->data;
			if(froot == temp)
				froot->right = repeat->right;
			else
				froot->left = repeat->right;
				temp = repeat;
		}	
	}
	delete temp;
	return true;
}
void NLR (Node*root){
	if(root != NULL){
		cout<<root->data<<"\t";
		NLR(root->left);
		NLR(root->right);
		
	}
}
int main(){
	Node* root;
	init(root);
	int data;
	for(int i = 0 ; i < 5 ; i++){
		cin>> data;
		insertNode(root,data);
	}
	NLR(root);
	return 0;
}
