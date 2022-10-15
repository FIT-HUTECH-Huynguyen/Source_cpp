#include<iostream>
#include<math.h>
using namespace std;

void input(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		cout<<"Nhap arr["<<i<<"]= ";
		cin>>arr[i];
	}
}
void output(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		cout<<arr[i]<<"\t";
	}
}
void evenNumber(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		if(arr[i] % 2 == 0){
			cout<<arr[i]<<"\t";
		}
	}
}
void interchangeSort(int arr[] , int n){
	for(int i = 0  ; i < n-1 ; i++){
		for(int j = i+1 ; j < n ; j++){
			if(arr[i] <= arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
bool isPrime(int n){
	if(n < 2)
		return false;
	for(int i = 2 ; i <= sqrt(n) ; i++){
		if(n % i == 0 )
			return false;
	}
	return true;
}
int primeNumber(int arr[] , int n){
	int sum = 0;
	for(int i = 0 ; i < n ; i++){
		if(isPrime(arr[i])){
			sum += arr[i] ;
		}
	}
	return sum;
}
int main(){
	int n ;
	do{
		cout<<"Enter n : ";
		cin >> n ;
		if( n < 0 || n > 100){
			cout<<"re-enter,please ! \n";
		}
	}while( n < 0 || n > 100);
	int arr[n];
	cout<<"Input : \n";
	input(arr,n);
	cout<<"\nOutput : ";
	output(arr,n);
	cout<<"\nOdd Number : ";
	evenNumber(arr,n);
	cout<<"\nDecreasing : ";
	interchangeSort(arr,n);
	output(arr,n);
	cout<<"\nSum prime number : "<<primeNumber(arr,n);
	
	return 0;
}
