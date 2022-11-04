#include<iostream>
#include<stdio.h>
#define MAX 10 
#define inputFile ("C:/graph/test1.txt")
using namespace std;

typedef struct GRAPH{
	int n ;
	int arr[MAX][MAX];
}graph;

int readInputFile(char nameFile[100] , graph &g){
	FILE* f ; 
	f = fopen(nameFile ,"rt");
	if( f == NULL){
		cout<<"Don't open file\n";
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i = 0 ; i < g.n ; i++){
		for(int j = 0 ; j < g.n ; j++){
			fscanf(f,"%d",&g.arr[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void printScreen(graph g){
	cout<<g.n<<"\n";
	for(int i = 0 ; i < g.n ; i++){
		for(int j = 0 ; j < g.n ; j++){
			cout<<g.arr[i][j];
			cout<<"\t";
		}
		cout<<"\n";
	}
}
void visit(graph g , int label[MAX] , int i){
	for(int j = 0 ; j < g.n ; j++){
		if(g.arr[i][j] != 0 && label[j] != label[i]){
			label[j] = label[i];
			visit(g,label,j);
		}

	}
}
void checkConnectGraph(graph g ){
	int label[MAX] , count= 0 ;
	int flag = 0;
	for(int i = 0 ; i < g.n ; i++){
		label[i] = 0 ;
	}
	for(int i = 0 ; i < g.n ; i++){
		if(label[i] == 0){
			count++;
			label[i] = count ;
		}
		visit(g,label,i);
	}
	for(int i =1 ; i <= count; i++){
		cout<<"Connect "<<i<<": ";
		for(int j = 0 ; j < g.n ; j++){
			if(label[j] == i){
				cout<<j<<"\t";
			}
		}
		cout<<"\n";
	}
}
int findValencyofNode(graph g ,int pos){
	int count = 0;
	for(int i = 0 ; i < g.n ; i++){
		if(g.arr[pos][i] != 0){
			count++;
		}
	}
	return count ;
	
}
void visitConvert(graph &g , int label[MAX] , int i){
	for(int j = 0 ; j < g.n ; j++){
		if(g.arr[i][j] == 0 && label[i] != label[j]){
			g.arr[i][j] = 1;
		}
	}
}
void convert(graph &g ){
	int label[MAX] , count= 0 ;
	int flag = 0;
	for(int i = 0 ; i < g.n ; i++){
		label[i] = 0 ;
	}
	for(int i = 0 ; i < g.n ; i++){
		if(label[i] == 0){
			count++;
			label[i] = count ;
		}
		visit(g,label,i);
	}
	for(int i =1 ; i <= count; i++){
		for(int j = 0 ; j < g.n ; j++){
			if(label[j] == i && i >1 ){
				g.arr[j][i] = g.arr[i][j] = 1;
			}
		}
		cout<<"\n";
	}
}
int main(){
	graph g; 
	int pos;
	if(readInputFile(inputFile,g)){
		readInputFile(inputFile , g);
//		printScreen(g);
		checkConnectGraph(g);
		cin >> pos ;
		cout<<"Valency of "<<pos<<"is : "<<findValencyofNode(g,pos);
		convert(g);
		printScreen(g);
	}
	
}
