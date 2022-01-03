/**
 *     Kiểm tra ma trận có đối xứng qua chéo chính khong
 */
#include<iostream>
#define Max 100
using namespace std;
void Import(int a[][Max] , int &n , int &m)
{
    do
    {
        cout<<"Enter the value rows : ";
        cin >> n ;
        cout<<"Enter the value column : ";
        cin >> m ;
        if(n < 0 && m < 0)
        {
            cout<<"Request to re-enter , please .";
        }
    } while ( n < 0 && m < 0);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]= ";
            cin>>a[i][j];
        }
    }
}
void Export_array(int a[][Max] , int n , int m)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int Check_Symmetry(int a[][Max] , int n , int m)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < m ; j++)
        {
            if(a[i][j] != a[j][i])
            {
                return 0;
            }
        }
    }
}
int main()
{
    int a[Max][Max] , n ,m;
    cout<<"Import the array "<<endl;
    Import(a,n,m);
    cout<<"Export the array "<<endl;
    Export_array(a , n , m);
    cout<<"Check symmetry across main diagonal: "<<endl;
    if(Check_Symmetry(a,n,m) == 0)
    {
        cout<<"\t\tNot semmetry"<<endl;
    }
    else
    {
        cout<<"\t\tSemmetry ."<<endl;
    }
    return 0 ;
}