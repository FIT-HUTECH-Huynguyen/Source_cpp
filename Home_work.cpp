#include<iostream>
#define Max 100
using namespace std;

//prototype
void printLine(int d);
void input(int  a[][Max] , int &n , int &m);
void output(int a[][Max] , int n , int m);
int Solve_sum(int a[][Max] , int n , int m);
int Solve_Sum_notdiagonalline(int a[][Max] , int n , int m);
void symmetric_matrix(int a[][Max] , int n , int m);
void transfer_matrix(int a[][Max] , int n , int m , int b[][Max]);
void SumOftwoArray(int a[][Max] , int n , int m , int b[][Max]);
void MinusOftwoArray(int a[][Max] , int n , int m , int b[][Max]);
void ProductofTwoarrays(int a[][Max] , int n , int m , int b[][Max] , int p , int q);

//function
void printLine(int d)
{
    for(int i = 0 ; i <=d ;i++)
    {
        cout<<"==";
    }
    cout<<endl;
}
void input(int a[][Max] , int &n , int &m)
{
    do
    {
        cout << " Enter size of rows : ";
        cin >> n;
        cout << " Enter size of column: ";
        cin >> m;
    } while ( n < 0 || m < 0);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]= ";
            cin >> a[i][j];
        }
    }
}

void output(int a[][Max] , int n , int m)
{
    for(int i = 0 ; i< n ; i++)
    {
        for(int j = 0 ;j < m ; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

//tổng các phần tử lẻ
int Solve_sum(int a[][Max] , int n , int m)
{
    int sum = 0 ;
    for(int i =0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(a[i][j] % 2 == 0)
            {
                sum += a[i][j];
            }
        }
    }
    return sum ;
}

// tính tổng các phẩn tử trừ đường chéo chính
int Solve_Sum_notdiagonalline(int a[][Max] , int n , int m)
{
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if( i != j )
            {
                sum += a[i][j];
            }
        }
    }
    return sum ;
}

//ma trận đối xứng
void symmetric_matrix(int a[][100], int n , int m)
{
    if(n != m)
    {
        cout <<"this isn't matrix square."<<endl;
    }
    else
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(a[i][j] != a[j][i] )
                {
                    cout<<"This isn't symmetric matrix "<<endl;
                    return;
                }
            }
        }
        cout <<"This is symmetric matrix "<<endl;
    }    
}

//chuyển vị
void transfer_matrix(int a[][Max] ,int n , int m , int b[][Max])
{
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            b[i][j] = a[j][i];
        }    
    }
}

//tổng hai ma trận
void SumOftwoArray(int a[][Max] , int n , int m ,int b[][Max])
{
    int c[Max][Max] ;
    if(n != m)
    {
        cout<<" A and B are not the same size "<<endl;
    }
    else
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                c[i][j] = a[i][i] + b[i][j];
            }
        }
    }    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout<<c[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

//Hiệu hai ma trận
void MinusOftwoArray(int a[][Max] , int n , int m ,int b[][Max])
{
    int c[Max][Max] ;
    if(n != m)
    {
        cout<<" A and B are not the same size "<<endl;
    }
    else
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                c[i][j] = a[i][i] - b[i][j];
            }
        }
    }    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout<<c[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

//tích hai ma trận
void ProductofTwoarrays(int a[][Max] , int n , int m , int b[][Max] , int p , int q)
{
    int c[Max][Max] ;
    if(m != p)
    {
        cout<<"Can't do calculation."<<endl;
    }
    else
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < q ; j++)
            {
                c[i][j] = 0;
                for(int k = 0 ; k < p; k++)
                {
                    c[i][j] += a[i][k]*b[k][j];
                }
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < q ; j++)
            {
                cout<<c[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }

}

int main()
{
    int a[Max][Max] , n , m  , b[Max][Max] ;
    
    printLine(20);
    cout<<"Matrix A : "<<endl;
    input(a,n,m);
    output(a,n,m);
    printLine(20);
    cout<<"Matrix B :"<<endl;
    input(b,n,m);
    output(b,n,m);

    printLine(20);
    cout<<"\nSum odd number of matrix : "<<Solve_sum(a,n,m)<<endl;
    printLine(20);
    cout<<"\nSum of the parts from minus the main diagonal of the matrix : "<<Solve_Sum_notdiagonalline(a,n,m)<<endl;

    printLine(20);
    cout<<"\nCheck matrix symmetric"<<endl;
    symmetric_matrix(a,n,m);

    printLine(20);
    cout<<"\nThis is the transpose matrix : "<<endl;
    transfer_matrix(a,n,m,b);
    output(b,m,n);
    
    printLine(20);
    cout<<"\n Sum of two array : "<<endl;
    SumOftwoArray(a,n,m,b);

    printLine(20);
    cout<<"\n Minus of two array: "<<endl;
    MinusOftwoArray(a,n,m,b);

    printLine(20);
    cout<<"\nProduct of two array"<<endl;
    ProductofTwoarrays(a,n,m,b,n,m);

    return 0 ;
}
