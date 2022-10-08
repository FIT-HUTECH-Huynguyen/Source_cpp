#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	int height;
}Node;
Node* root;
void init(Node* root){
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
		return 0;
	return root->height;
}
int balanceFactor(Node* root){
	if(root == NULL)
		return 0 ;
	return getHeight(root->left)-getHeight(root->right);
}
int max(int a , int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}
Node* rotateLeft(Node *&root){
	//th1 : Khong xoay duoc do nut rong 
	if(root == NULL)
		return NULL;
	//th2 : khong xoay duoc do nut rong khong co cay con phai 
	if(root->right == NULL)
		return NULL;
	//th3: thuc hien xoay 
	Node* pivot = root->right;
	// chuyen cay con trai cua pivot thanh cay con phai cua p
	root->right = pivot->left;
	// chuyen root thanh cay con trai cua pivot 
	pivot->left = root;
	//cap nhat chieu cao  cua nut root va pivot 
	root->height = 1 + max(getHeight(root->right),getHeight(root->left));
	pivot->height = 1 + max(getHeight(pivot->right),getHeight(pivot->left));
	
	return pivot;
}
Node* rotateRight(Node* &root){
	//th1 : khong xoay duoc do nut root rong
	if(root == NULL)
		return NULL;
	//th2 : Khong xoay duoc do nut root rong khong co cay con trai
	if(root->left == NULL)
		return NULL;
	//th3 : thuc hien xoay 
	Node* pivot = root->left;
	// chuyen cay con phai cua pivot thanh cay con trai cua p 
	root->left = pivot->right;
	// chuyen root thanh cay con trai cua pivot 
	pivot->right = root;
	//cap nha chieu cao cua nut root va pivot 
	root->height = 1 + max(getHeight(root->right),getHeight(root->left));
	pivot->height = 1 + max(getHeight(pivot->right),getHeight(root->left));

	return pivot;
}
Node* balance(Node* &root){
	if(balanceFactor(root) < -1){
		if(balanceFactor(root->right) > 0){ // lech trai
			root->right = rotateRight(root->right);
		}
		root = rotateLeft(root);
	}
	if(balanceFactor(root) > 1){
		if(balanceFactor(root->left) < 0){  // lech phai 
			root->left = rotateLeft(root->left);
		}
		root = rotateRight(root);
	}
	return root;
}
Node* insert(Node* &root, int x){
	if(root == NULL)
		root = createNode(x);
    if(x < root->data)
		root->left=insert(root->left,x);
	if(x > root->data)
		root->right =insert(root->right,x);
	
	root->height = 1 + max(getHeight(root->left),getHeight(root->right));
	return balance(root);
	//return root;
}
Node* minValueNode(Node* root){
	Node* current = root ;
	while(current && current->left != NULL){
		current = current->left;
	}
	return current;
}
Node * remove(Node* &root, int temp){
	if(root == NULL)
		return root;
	if(root->data > temp)
		root->left = remove(root->left,temp);
	if(root->data < temp)
		root->right = remove(root->right,temp);
	else{
		if(root->left == NULL){
			Node* tempNode = root->right;
			delete root;
			return tempNode;
		}
		else if(root->right == NULL){
			Node* tempNode = root->left;
			delete root;
			return tempNode;
		}
		Node* tempNode = minValueNode(root->right);
		root->data = tempNode->data;
		root->right = remove(root->right,tempNode->data);
	}
	if(root == NULL)
		return root;
	root->height = 1 + max(getHeight(root->left),getHeight(root->right));
	
	return balance(root);
}
void LNR(Node* root){
	if(root == NULL){
		return;
	}else{
		LNR(root->left);
		cout<<root->data<<"\t";
		LNR(root->right);
	}
}
int main(){
	init(root);
	int x , n ;
	cin>> n ;
	for(int i = 0 ; i< n ; i++){
		cin>>x;
		insert(root,x);
	}
	LNR(root);
	int temp;
	cin>> temp;
	remove(root,temp);
	LNR(root);
	return 0 ;
}
