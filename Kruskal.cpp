#include<iostream>
#define MAX 100
using namespace std;

struct Graph{
	int size;
	int arr[MAX][MAX];
};
struct  Edge{
	int vertex_first;
	int vertex_second;
	int value;
};
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
void sortIncreasing(Edge edge[MAX] , int sumEdge){
	Edge tempEdge;
	for(int i = 0 ; i < sumEdge ; i++){
		for(int j = i+1 ; j < sumEdge ; j++){
			if(edge[i].value > edge[j].value ){
				tempEdge = edge[i];
				edge[i] = edge[j];
				edge[j] = tempEdge;
			}
		}
	}
}
void KrusKal(Graph graph){
	Edge listEdge[MAX];
	int sumEdge = 0; // tong so canh	
	for(int i = 0 ; i < graph.size ; i++){
		for(int j = i+1 ; j < graph.size ; j++){
			if(graph.arr[i][j] != 0){
				listEdge[sumEdge].vertex_first = i;
				listEdge[sumEdge].vertex_second= j;
				listEdge[sumEdge].value = graph.arr[i][j];
				sumEdge++;
			}
		}
	}
	sortIncreasing(listEdge,sumEdge);
	int countEdge = 0 ;	// so canh trong cay khung 
	Edge edge[MAX];
	int label[MAX];
	for(int i = 0 ; i < graph.size ; i++){
		label[i] = i;
	}
	int visited = 0; 
	while(countEdge < graph.size && visited < sumEdge){
		if(label[listEdge[visited].vertex_first] != label[listEdge[visited].vertex_second]){
			edge[countEdge] = listEdge[visited];
			countEdge++;
			int value = label[listEdge[visited].vertex_second];
			for(int j = 0 ; j < graph.size ; j++){
				if(label[j] == value){
					label[j] = label[listEdge[visited].vertex_first];
				}
			}
		}
		visited++;
	}
	if(countEdge != graph.size-1){
		cout<<"\n Don't connect\n";
	}else{
		int sumWeightFrameTree =  0;
		cout<<"Connect Graph : \n";
		cout<<"Frame Tree of graph : \n";
		for(int i = 0 ; i < countEdge ; i++){
			cout<<"("<<edge[i].vertex_first+1<<","<<edge[i].vertex_second+1<<")";
			sumWeightFrameTree += edge[i].value;
		}
		cout<<"Sum weight of Frame Tree : "<<sumWeightFrameTree<<"\n";
	}
}
int main(){
	Graph graph;
	inputFile("test1.txt",graph);
	output(graph);
	KrusKal(graph);
	return 0;
}
