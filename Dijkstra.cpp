#include<iostream>
#include<stdlib.h>
#include<time.h>
#define MAX 100
#define infinity 1000
using namespace std;

int trace[MAX];
int unvisit[MAX];
int dist[MAX];

struct Graph{
	int size;
	int arr[MAX][MAX];
};

int findMinWay(Graph graph){
	int vertex = -1; // neu khong tim thay dinh nao phu hop thi tra ve -1 
	float inf = infinity; 
	
	for(int i = 0 ; i < graph.size ; i++){
		// kiem tra dinh i da xet chua va do dai di toi dinh i co nho hon vo cuc khong 
		if(unvisit[i] == 0 && dist[i] < inf){
			inf = dist[i];
			vertex = i;
		}
	}
	return vertex;
} 
void updateWay(int vertex_i , Graph graph){
	unvisit[vertex_i] = 1; // dinh u da duoc chon nen phai gan gia tri unvisit cua no = 1
	for(int i = 0 ; i < graph.size ; i++){
		// tim mot dinh v chua xet va co canh noi tu u-> v
		if(unvisit[i] == 0 && graph.arr[vertex_i][i] > 0 && graph.arr[vertex_i][i] < infinity){
			// Neu nhu do dai duong di toi dinh i tu dinh khac ma lon hon do gia duong di tu dinh vertex_i + (vertex_i,i) thi tien hanh cap nhat lai
			if(dist[i] > dist[vertex_i] + graph.arr[vertex_i][i]){
				dist[i] = dist[vertex_i]+ graph.arr[vertex_i][i];
				trace[i] = vertex_i;
			}
		}
	}
}
void Dijkstra(int vertex_A , int vertex_B ,Graph graph){
	// khoi tao cac gia tri can thiet cho thuat toan 
	
	for(int i = 0 ;  i < graph.size ; i++){
		unvisit[i] = 0;
		dist[i] = infinity;
		trace[i] = -1;
	} 
	dist[vertex_A] = 0;
	if(vertex_A == vertex_B){
		cout<<"Duong di ngan nhat tu dinh"<<vertex_A<<" den dinh "<<vertex_B<<" la : \n\t";
		cout<<"\t"<<vertex_A<<"<--"<<vertex_B<<" co do dai = 0\n";
		return;
	}
	// thi hanh thuat toa Dijkstra 
	while(unvisit[vertex_B] == 0){
		// bien gan tim do dai duong di ngan nhat 
		int vertex_min = findMinWay(graph);
		// neu nhu khong thay duong di nao thi dung thuat toan va ket qua khong tim thay duong di . Nguoc lai tien hanh cap nhat lai do dai duong di 
		if(vertex_min == -1) 
			break;
		updateWay(vertex_min,graph);
	}
	if(unvisit[vertex_B] == 1){
		cout<<"Duong di ngan nhat tu dinh [ "<<vertex_A<<" ] den dinh [ "<<vertex_B<<" ] la : \n\t";
		int vertex_temp = vertex_B;
		cout<<vertex_B;
		while(trace[vertex_temp] != vertex_A){
			cout<<"<--"<<trace[vertex_temp];
			vertex_temp = trace[vertex_temp];
			
		}
		cout<<"<--"<<trace[vertex_temp]<<" ";
		cout<<"\t Vo do dai la "<<dist[vertex_B]<<"\n";
	}
	else{
		cout<<"Khong co duong di nao tu dinh "<<vertex_A<<" den dinh "<<vertex_B<<"\n";
	}
}
int readFile(char nameFile[] , Graph &graph){
	FILE* f ;
	f = fopen(nameFile , "rt");
	if(f == NULL){
		cout<<"Don't open file \n";
		return 0;
	}
	fscanf(f,"%d",&graph.size);
	for(int i = 0 ; i < graph.size; i++){
		for(int j = 0 ; j < graph.size;j++){
			fscanf(f,"%d",&graph.arr[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void output(Graph graph){
	cout<<"size : "<<graph.size<<"\n";
	for(int i = 0 ; i < graph.size ; i++){
		for(int j = 0 ; j < graph.size; j++){
			cout<<graph.arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void matrix100(Graph &graph){
	cout<<"Enter size of matrix : ";
	cin >> graph.size;
	srand((int)time(0));
	for(int i = 0 ; i < graph.size; i++){
		for(int j = 0 ; j < graph.size; j++){
			if(i == j){
				graph.arr[i][j] == 0;
			}else{
				graph.arr[i][j] = 1+rand()%5;
			}
		}
	}
}
void pathOfTheVertices(int u , Graph graph){	
	for(int i = 0 ; i < graph.size ; i++){
		if(u == i)	 continue;
		Dijkstra(u,i,graph);
	}
//	while( i >= 0  || j >= 0){
//		if(i != j && j >= 0 ){
//			Dijkstra(i,j,graph);
//			j--;
//		}	
//		if(j == 0){
//				j = graph.size-1;
//				i--;
//		}
//	}
}
int main(){
	Graph graph;
	//readFile("test1.txt",graph);
	matrix100(graph);	
	//output(graph);
	//Dijkstra(1,1,graph);
	for(int i = 0 ; i < graph.size ; i++){
		pathOfTheVertices(i,graph);
	}
	
}
