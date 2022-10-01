#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node* left;
	node* right;
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
		if(data == root->data){
			return ;
		}
		if(data < root->data){
			insertNode(root->left,data);
		}
		if(data > root->data){
			insertNode(root->right,data);
		}
	}
}
void ascending(Node* root ){
	if(root != NULL){
		ascending(root->left);
		cout<<root->data<<"\t";
		ascending(root->right);
	}
}
void decrease(Node* root){
	if(root != NULL){
		decrease(root->right);
		cout<<root->data<<"\t";
		decrease(root->left);
	}
}
bool isThisBST(Node* root){
	if(root == NULL){
		return true;
	}
	if(root->left!= NULL && root->left->data > root->data){
		return false;
	}
	if(root->right != NULL && root->right->data < root->data){
		return false;
	}
	if(!isThisBST(root->left) || !isThisBST(root->right)){
		return false;
	}
	return true;
}
bool isFullBST(Node* root){
	if(root == NULL) return true;
	else if (root->left == NULL && root->right == NULL)
		return true;
	else if (root->left && root->right){
		return isFullBST(root->left) && isFullBST(root->right);
	}else{
		return false;
	}
}
int findFNode(Node* root , int findx){
	Node* temp , *froot;
	temp = root;
	if(root!= NULL){
		findFNode(root,findx);
		froot = temp;
		if(findx == temp->data) 
			return froot->data;
		findFNode(root,findx);
	}
}
int main(){
	int data;
	init(root);
	for(int i = 0 ; i <5 ; i++){
		cin>> data;
		insertNode(root,data);
	}
	ascending(root);
	decrease(root);
	cout<<"\nresult : "<<isThisBST(root);
	cout<<"\nresult : "<<isFullBST(root);
	cout<<"\nresult : "<<findFNode(root,4);
}
