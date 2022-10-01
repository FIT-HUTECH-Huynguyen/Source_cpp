#include <iostream>
#define Max 100
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
	return (root == NULL );
}
Node* createNode(int data){
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->left = NULL;
	tempNode->right = NULL;
	return tempNode;
}
void createTree(Node* &root , int arr[] , int begin , int end){
	if(begin > end) return ;
	int i = (begin+end)/2;
	root = createNode(arr[i]);
	createTree(root->left,arr,begin,i-1);
	createTree(root->right,arr,i+1,end);
}
void NLR(Node* root){
	if(root != NULL){
		cout<<root->data<<"\t";
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(Node* root){
	if(root != NULL){
		LNR(root->left);
		cout<<root->data<<"\t";
		LNR(root->right);
	}
}
void LRN(Node* root){
	if(root != NULL){
		LRN(root->left);
		LRN(root->right);
		cout<<root->data<<"\t";
	}
}
int countNodeInTree(Node* root){
	int count = 0;
	
	if(root != NULL){
		return 1 + countNodeInTree(root->left) + countNodeInTree(root->right);
	}
}
int isLeaf(Node *root){
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
int main(){
	Node* root;
	int arr[Max] , n;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		cout<<"Arr["<<i<<"]= ";
		cin>> arr[i];
	}
	init(root);
	createTree(root,arr,0,n-1);
	cout<<"NLR : ";
	NLR(root);
	cout<<"\nLNR : ";
	LNR(root);
	cout<<"\nLRN : ";
	LRN(root);
	cout<<"\nNumber of nodes : "<<countNodeInTree(root)<<"\n";
	cout<<"\nNumber of leaf nodes : "<<countLeaf(root)<<"\n";
	return 0 ;
}

