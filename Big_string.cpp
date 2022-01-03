#include<iostream>
#include<string.h>
#define Max 100
using namespace std;

typedef struct Student
{
    char name[100];
    char mssv[11];
    int score;
    float average;
}sv;

struct List
{
	int n;
	Student *arr;
};

//khai báo hàm (prototype)
void Input(sv &d);
void Output(sv d);
void import_array(sv a[] , int &n);
void Export(sv a[] , int n);
void Add_student(int sl ,List ds);
int Delete_student(sv a[] , int n , char id[]);
void Edit_student(sv a[] , int n , char id[]);//sửa thông tin sinh viên
void Sort_student_list (sv a[] , int n);
void Search_studen (sv a[] , int n);//tìm kiếm sinh viên bằng tên
int  solve_average (sv a[] , int n);
void menu();

void Input(sv &d)
{
    fflush(stdin);
    cout<<"Enter name of student : ";
    gets(d.name);
    do
    {
       cout<<"Enter id : "; 
       fflush(stdin);
       cin >> d.mssv;
    } while (strlen(d.mssv) != 10);
    do
    {
        cout<<"Enter attendence point : ";
        cin >> d.score;
    } while (d.score < 60 || d.score > 100);
    
}

void Output(sv d)
{
    cout<<"Name of student : "<<d.name<<endl;
    cout<<"Student code : "<<d.mssv<<endl;
    cout<<"Attendance points: "<<d.score<<endl;
}

void Import_array(sv a[] , int &n)
{
    do
    {
        cout<<"Enter the number of student : ";
        cin >> n;
        if(n < 0)
        {
            cout<<"Request to re-enter , please ."<<endl;
        }
    } while ( n < 0);
    for(int i = 0 ; i < n ; i++)
    {
        Input(a[i]);
    }
}

void Export(sv a[] , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        Output(a[i]);
    }
}

void Add_student(int &n ,sv a[] , sv &d)
{
    Input(d);
   for(int i = n-1 ; i >=1 ; i--)
   {
       a[i+1] = a[i];
   }
   a[0] = d;
   n++;
}

int Delete_student(sv a[] , int n , char id[])
{
    int found = 0 ;
    for(int i = 0 ; i < n ; i ++)
    {
        if(strcmp(id,a[i].mssv)==0)
        {
            found = 1;
            for(int j = i ; j < n ; j++)
            {
                 a[j] = a[j+1];
            }
            cout<<"Deleted student with ID : "<<id<<endl;
            break; 
        }  
    }      
    if(found == 0 )
    {
        cout<<"Student with ID "<<id<<" isn't exist"<<endl;
        return 0 ;
    }
    else 
    {
        return 1 ;
    }
}

struct Student st;

void Edit_student(sv a[] , int n , char id[])
{
    for(int i = 0 ; i < n ; i++)//duyệt sinh viên 
    {
        if(strcmp(id,a[i].mssv)==0) // kiêm tra xem sv nào trùng với giá trị cần tìm 
        {
            fflush(stdin);
            cout<<"Enter name of student : ";
            gets(a[i].name);
            do
            {
                cout<<"Enter id "; 
                fflush(stdin);
                cin >> a[i].mssv;
            } while (strlen(a[i].mssv) != 10);
            do
            {
                cout<<"Enter attendence point : ";
                cin >> a[i].score;
            } while (a[i].score < 60 || a[i].score > 100);
        }
    }
}

void Sort_student_list(sv a[] , int n )
{
    sv temp ;
    for (int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(a[i].score  < a[j].score)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void Search_student(sv a[] , int n)
{
    int select;
    char id[100] , names[100];
    int flag = 0 ;
    cout<<"\n---------------\n";
    cout<<"Search Information"<<endl;
    cout<<"------------------"<<endl;
    cout<<"1.Search with ID"<<endl;
    cout<<"2.Search with name"<<endl;
    cout<<"select : ";cin >> select;
    switch(select)
    {
        case 1 : 
        {
            cout<<"Enter ID : ";
            cin >>id;
            struct Student find;
            for(int i = 0 ; i < n ; i++)
            {
                if(strcmp(id,a[i].mssv)==0)
                {
                    find =  a[i];
                    flag = 1;
                    break;
                }
            }
            if ( flag == 0)
            {
                cout << "Not Found ";
            }
            else 
            {
                cout<<"Name of student : "<<find.name<<endl;
                cout<<"Student code : "<<find.mssv<<endl;
                cout<<"Attendance points: "<<find.score<<endl;
            }
            break;
        }
        case 2 :
        {
            cout<<"Enter name : ";
            cin >> names;
            for(int i = 0 ; i < n ; i++)
            {
                if(strcmp(names,a[i].name)==0)
                {
                    flag = 1;
                    cout<<"Name of student : "<<a[i].name<<endl;
                    cout<<"Student code : "<<a[i].mssv<<endl;
                    cout<<"Attendance points: "<<a[i].score<<endl;
                }
            }
            if(flag == 0)
            {
                cout << "Not Found"<<endl;
            }
            break;
        }
    }
    
}

int solve_average(sv a[] , int n)
{
    int avg = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        avg += a[i].score;
    }
    return avg/n;
}

void Rank_student(sv a[] , int n)
{
    cout <<" | "<<"STT"<<" | "<<" name "<<" | "<<"  rank"<<" | "<<endl;
    for(int i = 0 ; i <  n ; i++)
    {
        if(a[i].score >= 60 && a[i].score < 80)
        {
            cout<<" |  "<<i+1<<" | "<<a[i].name<<" | "<<"Good student     "<<" | "<<endl;
        }
        else if(a[i].score >= 80 && a[i].score <= 100)
        {
            cout<<" |  "<<i+1<<" | "<<a[i].name<<" | "<<"Excellent student"<<" | "<<endl;
        }
    }
}

void menu()
{
        cout<<"\t\t\t-----------------------MENU------------------------"<<endl;
        cout<<"\t\t\t|1. |    Input                                  | |"<<endl;
        cout<<"\t\t\t|2. |    Add student                            | |"<<endl;
        cout<<"\t\t\t|3. |    Delete student                         | |"<<endl;
        cout<<"\t\t\t|4. |    Edit student                           | |"<<endl;
        cout<<"\t\t\t|5. |    Sort student list                      | |"<<endl;
        cout<<"\t\t\t|6. |    Search student                         | |"<<endl;
        cout<<"\t\t\t|7. |    Average attendance point of class      | |"<<endl;
        cout<<"\t\t\t|8. |    Rank of student                        | |"<<endl;
        cout<<"\t\t\t|0. |    Quit                                   | |"<<endl;
        cout<<"\t\t\t---------------------------------------------------"<<endl;
}
int main()
{
    sv a[Max];
    List ds;
    int n ;
    int select,sl;
    do
    {
        system("cls");
        menu();
        cout<<"Select : ";
        cin >>select;
        switch(select)
        {
            case 1: 
            {
                cout<<"\t----------Input----------"<<endl;
                Import_array(a,n);
                break;
            }
            case 2 : 
            {
                cout<<"\t---------Add Student---------"<<endl;
                sv d ;
                Add_student(n,a,d);
                system("pause");
                break;
            }
            case 3:
            {
                char id[11];

                cout<<"\t-----------Delete student-------------"<<endl;
                cout<<"Enter Id to delete : ";
                cin >>id;
                if(Delete_student(a,n,id) == 1)
                {
                    n--;
                }
                system("pause");
                break;
            }
            case 4 :
            {
                char id[11];

                cout<<"\t------------Edit Student--------------"<<endl;
                cout<<"Enter Id  : ";
                cin >>id;
                Edit_student(a,n,id);
                system("pause");
                break;
            }
            case 5:
            {
                cout<<"\t-----------Sort student list------------"<<endl;
                Sort_student_list(a,n);
                Export(a,n);
                system("pause");
                break;
            }
            case 6 :
            {
                cout<<"\t-----------Search Student----------------"<<endl;
                Search_student(a,n);
                system("pause");
                break;
            }
            case 7:
            {
                cout<<"\t-------------Average----------------"<<endl;
                cout<<"Average attendance point of class :"<<solve_average(a,n)<<endl;
                system("pause");
                break;
            }
            case 8:
            {
                cout<<"\t-------------Rank--------------"<<endl;
                Rank_student(a,n);
                system("pause");
                break;
            }
            case 0 : 
            {
                return 0;
            }
            default:
            {
                Export(a,n);
                system("pause");
                break;
            }
        }
    } while (true);
    
    return 0 ;
}