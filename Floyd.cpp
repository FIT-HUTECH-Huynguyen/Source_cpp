#include<iostream>
#include<stdlib.h>
#include<time.h>
#define infinity 1000
#define MAX 100
using namespace std;
int afterNode[MAX][MAX];
int length[MAX][MAX];

struct Graph{
	int size;
	int arr[MAX][MAX];
};

void Floyd(Graph graph){
	
	for(int i = 0 ; i < graph.size ; i++){
		for(int j = 0 ; j < graph.size ; j++){
			if(graph.arr[i][j] > 0){
				afterNode[i][j] = j;
				length[i][j] = graph.arr[i][j];
			}
			else{
				afterNode[i][j] = -1;
				length[i][j] = infinity;
			}
		}
	}
	for(int k = 0 ; k < graph.size ; k++){
		for(int i = 0 ; i < graph.size ; i++){
			for(int j = 0 ; j < graph.size ; j++){
				if(length[i][j] > length[i][k] + length[k][j]){
					length[i][j] = length[i][k] + length[k][j];
					afterNode[i][j] = afterNode[i][k];
				}
			}
		}
	}
	int start , finish ; 
//	cout<<"Enter start vertex : ";
//	cin >> start ;
//	cout<<"Enter finish vertex : ";
//	cin >> finish ; 
	for(int i = 0 ; i < graph.size; i++){
		start = i;
		for(int j = 0 ; j < graph.size; j++){
			finish = j;
			if(afterNode[start][finish] == -1){
				cout<<"Khong co duong di tu dinh ["<<start<<"] den dinh ["<<finish<<"] la : \n";
			}else{
				cout<<"Duong di ngan nhat tu dinh ["<<start<<"] den dinh ["<<finish<<"] la : \n";
				cout<<start;
				int temp = start;
				while(afterNode[temp][finish] != finish){
					temp = afterNode[temp][finish];
					cout<<"-->"<<temp;
				}
				cout<<"-->"<<finish;
				cout<<"\n\t voi tong trong so la : "<<length[start][finish];
			}
		}	
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
				graph.arr[i][j] = 1;
			}
		}
	}
}
//void pathOfTheVertices(Graph graph){	
//	for(int i = 0 ; i < graph.size ; i++){
//		Floyd(graph);
//	}
//}
int main(){
	Graph graph;
//	readFile("test1.txt",graph);
	matrix100(graph);
	Floyd(graph);
	return 0 ;
}
