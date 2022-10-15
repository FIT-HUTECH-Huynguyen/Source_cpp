#include<iostream>
using namespace std;

typedef struct node{
	int data ; 
	struct node* left;
	struct node* right;
}Node;

Node* root;

void init(Node* &root){
	root = NULL;
}

int isEmpty(Node* root){
	return root == NULL;
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
	}else{
		if(data < root->data)
			insertNode(root->left,data);
		if(data > root->data)
			insertNode(root->right,data);
	}
}
void decreasing(Node* root){
	if(root == NULL)
		return ;
	else{
		decreasing(root->right);
		cout<<root->data<<"\t";
		decreasing(root->left);
	}
}
int isLeaf(Node* root){
	return (root->left == NULL) && (root->right == NULL);
}

int countLeaf(Node* root){
	if(root == NULL){
		return 0 ;
	}else{
		if(isLeaf(root))
			return 1;
		else
			return countLeaf(root->left) + countLeaf(root->right);
	}
}
int sumValueofNode(Node* root){
	if(root == NULL){
		return 0 ;
	}

	return root->data + sumValueofNode(root->left) + sumValueofNode(root->right);
}
int main(){
	init(root);
	insertNode(root,5);
	insertNode(root,2);
	insertNode(root,3);
	insertNode(root,6);
	insertNode(root,7);
	insertNode(root,1);
	
	cout<<"Decreasing: ";
	decreasing(root);
	cout<<"\nCount Node leaf : "<<countLeaf(root);
	cout<<"\nSum : "<<sumValueofNode(root);
	return 0;
}

