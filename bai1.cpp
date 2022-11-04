#include<iostream>
#include<stdio.h>
#define MAX 10
#define inputFile "C:/graph/test1.txt"
using namespace std;

typedef struct GRAPH{
	int weight;
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
bool checkGraph(graph g){
	for(int i = 0 ; i < g.n ; i++){
		if (g.arr[i][i] != 0){
			return false;
		}
	}
	return true ;
}
bool checkUndirectedGraph(graph g){
	for(int i = 0 ; i < g.n ; i++){
		for(int j = 0 ; j < g.n; j++){
			if (g.arr[i][j] != g.arr[j][i]){
				return false;
			}
		}
	}
	return true; 
}
 int checkLoopGraph(graph g){
 	int flag = 0;
	for(int i = 0 ; i < g.n ;  i++){
		if(g.arr[i][i] != 0){
			cout<<i<<"\t";
			flag = 1;
		}
	}
	if(flag == 1){
		return 1;
	}
	return 0;
}
int  checkWeightGraph(graph g){
	for(int i = 0 ; i < g.n ; i++){
		for(int j = 0 ; j < g.n ; j++){
			if(g.arr[i][j] > 1 || g.arr[i][j] < 0){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	graph g;
	if(readInputFile(inputFile,g)){
		readInputFile(inputFile , g);
		printScreen(g);
		cout<<"Is the Graph valid ? \n ";
		if(checkGraph(g)){
			cout<<"Valid \n";
		}else{
			cout<<"Invalid\n";
		}
		cout<<"Undirected Graph : ";
		if(checkUndirectedGraph(g)){
			cout<<"Undirected Graph \n";
		}else{
			cout<<"Directed Graph \n";
		}
		cout<<"Loop Graph : ";
		if(checkLoopGraph(g)){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
		cout<<"Weight Graph :";
		if(checkWeightGraph(g)){
			cout<<"yes \n";
		}else{
			cout<<"No \n";
		}
	}
	return 0;
}
