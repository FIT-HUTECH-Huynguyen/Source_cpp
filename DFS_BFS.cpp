#include<iostream>
#define MAX 100
using namespace std;
struct QUEUE{
	int size;
	int arr[MAX];
};
struct Stack{
	int size;
	int arr[MAX];
};
typedef struct GRAPH{
	int size ;
	int arr[MAX][MAX];
}Graph;
int unvisited[MAX];
int trace[MAX];
//init 
void init(QUEUE &Q){
	Q.size = 0;
}
//push
int push(QUEUE &Q, int value){
	if(Q.size + 1 >= 100){
		return 0;
	}
	Q.arr[Q.size] = value;
	Q.size++;
	return 1;
}
//pop 
int pop(QUEUE &Q , int &value){
	if(Q.size <= 0){
		return 0;
	}
	value = Q.arr[0];
	for(int i = 0 ; i < Q.size-1;i++){
		Q.arr[i] = Q.arr[i+1];
	}
	Q.size--;
	return 1;
}
// is empty
int isEmpty(QUEUE Q){
	if(Q.size <= 0){
		return 1;
	}
	return 0;
}
// read input file 
int readInputFile(char nameFile[100] , Graph &graph){
	FILE* f ; 
	f = fopen(nameFile ,"rt");
	if( f == NULL){
		cout<<"Don't open file\n";
		return 0;
	}
	fscanf(f,"%d",&graph.size);
	for(int i = 0 ; i < graph.size ; i++){
		for(int j = 0 ; j < graph.size ; j++){
			fscanf(f,"%d",&graph.arr[i][j]);
		}
	}
	fclose(f);
	return 1;
}
// print screen 
void printScreen(Graph graph){
	cout<<graph.size<<"\n";
	for(int i = 0 ; i < graph.size ; i++){
		for(int j = 0 ; j < graph.size ; j++){
			cout<<graph.arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
// init 
void init(Stack &stack){
	stack.size = 0;
}
// push 
int push(Stack &stack , int value){
	if(stack.size + 1 >= 100){
		return 0;
	}
	stack.arr[stack.size] = value;
	stack.size++;
	return 1;
}
// pop 
int pop (Stack &stack , int &value){
	if(stack.size != 0){
		value = stack.arr[stack.size -1];
		for(int i = stack.size-1 ; i >= 0 ; i--){
			stack.arr[i+1] = stack.arr[i];
		}
		stack.size--;
		return 1;
	}
	return 0;
	
}
int isEmpty(Stack stack){
	return stack.size == 0;
}
//void DFS(Graph graph , int vertex){
//	Stack stack;
//	init(stack);
//	push(stack,value);
//	while(!isEmpty(stack)){
//		pop(stack,value);
//		unvisited[value] = 1;
//		
//	}
//}
//DFS
void DFS(Graph graph ,  int vertex){
    unvisited[vertex] = 1;
    for(int i = 0 ; i < graph.size ; i++){
    	if(graph.arr[vertex][i] != 0 && unvisited[i] == 0){
    		trace[i] = vertex;
    		DFS(graph,i);
		}
	}
}
// check DFS
void checkDFS(int start , int finish , Graph graph){
	int temp = 0;
	for(int i = 0 ; i < graph.size ; i++){
		unvisited[i] = 0;
		trace[i] = -1;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
	DFS(graph,start);
	if(unvisited[finish] == 1){
		cout<<"Duong di tu dinh "<<start<<"den dinh "<<finish<<" la : ";
		temp = finish;
		cout<<finish<<"\t";
		while(trace[temp] != start){
			cout<<trace[temp]<<"\t";
			temp = trace[temp];
		}
		cout<<trace[temp]<<"\n";
	}else{
		cout<<"khong co ";
	}
}
//BFS
void BFS(int value , Graph graph){
	QUEUE Q;
	init(Q);
	push(Q,value);
	while(!isEmpty(Q)){
		pop(Q,value);
		unvisited[value] = 1;
		for(int i = 0 ; i < graph.size ; i++){
			
			if(graph.arr[value][i] != 0 && unvisited[i] == 0){
				push(Q,i);
				if(trace[i]==-1){
					trace[i] = value;
				}
			}
		}
	}
}
// check BFS 
void checkBFS(int start , int finish , Graph graph){
	for(int i = 0 ; i < graph.size ; i++){
		unvisited[i] = 0;
		trace[i] = -1;
	}
	BFS(start , graph);
	int temp = 0;
	if(unvisited[finish] == 1){
		cout<<"Duong di tu dinh "<<start<<"den dinh "<<finish<<" la : ";
		temp = finish;
		cout<<finish<<"\t";
		while(trace[temp] != start){
			cout<<trace[temp]<<"\t";
			temp = trace[temp];
		}
		cout<<trace[temp]<<"\n";
	}else{
		cout<<"Khong co \n";
	}
}
int main(){
	Graph graph ;
	readInputFile("C:/graph/test1.txt",graph);
	printScreen(graph);
	cout<<"\n DFS : \n"; 
	checkDFS(1,4,graph);
	cout<<"\n BFS : \n";
	checkBFS(1,4,graph);
}
