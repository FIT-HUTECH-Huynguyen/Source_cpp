#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n){
	if(n < 2) 
		return false;
	for(int i = 2 ;  i <=sqrt(n) ; i++){
		if(n% i == 0){
			return false;
		}
	}
	return true;
}
int solveSum(int arr[] , int n){
	if( n == 0)	return 0;
	if(isPrime(arr[n-1])){
		return arr[n-1] + solveSum(arr,n-1);
	}
	return solveSum(arr,n-1);
}
void evenNumber(int arr[] , int n){
	if(n == 0) return ;
	if(arr[n-1] % 2 == 0){
		cout<<arr[n-1]<<"\t";
	}
	return evenNumber(arr,n-1);
	
}
int main(){
	int arr[] = {1,5,8,9,7,4};
	int n = 6;
	cout<<"sum : "<<solveSum(arr,n);
	cout<<"\nEven Number : ";
	evenNumber(arr,n);
	return 0;
}
