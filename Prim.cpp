#include<iostream>
#define MAX 100 
using namespace std;

struct Graph{
	int size;
	int arr[MAX][MAX];
};
struct Edge{
	int vertex_first;
	int vertex_second;
	int value;
};
Edge T[MAX];
int unvisited[MAX];
int inputFile(char nameFile[] , Graph &graph){
	FILE* f ;
	f = fopen(nameFile,"rt");
	if(f == NULL){
		cout<<"Khong mo duoc file";
		return 0;
	}
	fscanf(f,"%d",&graph.size);
	for(int i = 0 ; i < graph.size ; i++){
		for(int j  = 0 ;  j <  graph.size; j++){
			fscanf(f,"%d",&graph.arr[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void output(Graph graph){
	cout<<graph.size<<"\n";
	for(int i = 0 ; i < graph.size ; i++){
		for(int j = 0 ; j < graph.size; j++){
			cout<<graph.arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void findVertexConnection(Graph graph , int label[MAX], int pos){
	for(int i = 0 ; i < graph.size ; i++){
		if(graph.arr[pos][i] != 0 && label[i] != label[pos]){
			label[i] = label[pos];
			findVertexConnection(graph,label,i);
		}
	}
}
int checkConnectGraph(Graph graph){
	int label[MAX];
	int count = 0;
	for(int i = 0 ; i < graph.size ; i++){
		label[i] = 0;
		count = 0 ;
		for(int j = 0 ; j < graph.size ; j++){
			if(label[i] == 0 ){
				count++;
				label[i] = count;
				findVertexConnection(graph,label,i);
			}
		}
	}
	return count;
}
void prim(Graph graph){
	if(checkConnectGraph(graph) != 1){
		cout<<"Don't connect\n";
		return ;
	}
	int flag  = 0 ;
	for(int i = 0 ; i < graph.size; i++){
		flag = 0;
		for(int j = 0 ; j < graph.size; j++){
			if(graph.arr[i][j] != graph.arr[j][i]){
				flag = 1;
			}
		}
	}
	if(flag == 1){
		cout<<"Don't Connect\n";
		return ;
	}
	int countEdge = 0 ;
	for(int i = 0 ; i < graph.size ; i++){
		unvisited[i] = 0;
	}
	unvisited[0] = 1;
	while(countEdge < graph.size -1 ){
		Edge  minEdge ;
		int minValue = 100 ;
		for(int i = 0 ; i < graph.size ; i++){
			if(unvisited[i] == 1){
				for(int j = 0 ; j < graph.size ; j++){
					if(unvisited[j] == 0 && graph.arr[i][j] != 0 && minValue > graph.arr[i][j]){
						minEdge.vertex_first = i ;
						minEdge.vertex_second = j ;
						minEdge.value = graph.arr[i][j];
						minValue = graph.arr[i][j];
					}
				}
			}
		}
		T[countEdge] = minEdge;
		countEdge ++;
		unvisited[minEdge.vertex_second] = 1;
	}
	if(countEdge == graph.size-1 ){
		cout<<"Don't connect";
	}
	int sumWeightNumber = 0 ;
	cout<<"Min frame Tree of Graph : \n";
	for(int i = 0 ; i < countEdge-1 ; i++){
		cout<<"("<<T[i].vertex_first+1<<","<<T[i].vertex_second+1<<"),";
		sumWeightNumber += T[i].value;
	}
	cout<<"("<<T[countEdge-1].vertex_first+1<<","<<T[countEdge-1].vertex_second+1<<")"<<"\n";
	sumWeightNumber += T[countEdge-1].value;
	cout<<"Sum value of frame Tree is : "<< sumWeightNumber;
	
}
int main(){
	Graph graph;
	inputFile("test1.txt",graph);
	output(graph);
	prim(graph);
	return 0;
}

