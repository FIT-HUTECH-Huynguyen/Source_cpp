#include<iostream>
#include<math.h>
using namespace std;

typedef struct node{
	int data;
	int height;
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
	tempNode->right = NULL;
	return tempNode;
}
int getHeight(Node* root){
	if(root == NULL)
		return 0 ;
	return root->height;
}
int balanceFactor(Node* root){
	if(root == NULL)
		return 0 ;
	return getHeight(root->right) - getHeight(root->left);
}
int max(int a,int b){
	if(a < b)
		return b ;
	else
		return a;
}
Node* rotateLeft(Node* &root){
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return NULL;
	Node* pivot = root->right;
	root->right = pivot->left;
	pivot->left = root;
	root->height = max(getHeight(root->right),getHeight(root->left));
	pivot->height = max(getHeight(pivot->right),getHeight(pivot->left));
	
	return pivot;
}
Node* rotateRight(Node* &root){
	if(root == NULL)	
		return NULL;
	if(root->left == NULL)
		return NULL;
	Node* pivot = root->left;
	root->left = pivot->right;
	pivot->right = root;
	
	root->height = max(getHeight(root->right),getHeight(root->left));
	pivot->height = max(getHeight(pivot->right),getHeight(root->left));
	
	return pivot;
}
Node* balance(Node* &root){
	if(balanceFactor(root) < -1 ){
		if(balanceFactor(root->right) > 0)
			root->right = rotateRight(root->right);
		root = rotateLeft(root);
	}
	if(balanceFactor(root) > 1 ){
		if(balanceFactor(root->left) < 0)
			root->left = rotateLeft(root->left);
		root = rotateRight(root); 
	}
	return root;
}
Node* insert(Node* &root , int x){
	if(root == NULL)
		root = createNode(x);
	if(root->data > x)
		root->left = insert(root->left , x);
	if(root->data < x)
		root->right = insert(root->right,x);
	root->height = 1+max(getHeight(root->right),getHeight(root->left));
	return root;
}
bool isAVL(Node* root){
	if(root == NULL)
		return true;
	if(abs(balanceFactor(root)) > 1)
		return false;
	return true;
}
void NLR(Node* root){
	if(root != NULL){
		cout<<root->data<<"\t";
		NLR(root->left);
		NLR(root->right);
	}
}
int main(){
	init(root);
	int x , n ;
	cin >> n ; 
	for(int i = 0 ; i < n ;i++){
		cin>> x;
		insert(root,x);
	}
	cout<<"\nBefore : ";
	NLR(root);
	cout<<"\nCheck balance tree : ";
	if(isAVL(root) == true){
		cout<<"True\n";
	}else{
		cout<<"False\n";
	}
	cout<<"\nAFTER :";
	if(isAVL(root) == false){
		balance(root);	NLR(root);
	}else{
		cout<<"Not change !\n";
	}
	return 0 ;
}
