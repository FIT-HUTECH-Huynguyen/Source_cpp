#include <iostream>
#include <math.h>
using namespace std;

void Import (int *ptr , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Enter : ptr["<<i<<"]= ";
        cin >>ptr[i];
    }
}

void Export(int *ptr , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<ptr[i]<<"\t";
    }
}

bool Check_symmetric(int n)//kiểm tra đảo ngược
{
    int inverted = 0 ;
    int temp = n ;
    while(temp !=0 )
    {
        inverted = inverted*10 + temp%10;//ex : inverted = 0*10 + 101%10 = 1
        temp = temp /10 ;// ex : temp = 101/10 = 10 ;
    }
    if(inverted == n) // số đảo ngược giống số ban đầu .
    {
        return true; // trả về đúng 
    }
    return false ;//trả về sai 
}

int Find_symmetric_number(int *ptr , int n) // tìm số nghịch đảo giống số ban đầu 
{
    for(int i = 0 ; i< n ; i++)
    {
        bool Check = Check_symmetric(ptr[i]);// gán biến check = hàm check_symmetric;
        if(Check == true) // kiểm tra điều kiện đúng 
        {
            return ptr[i];//trả ra giá trị đó 
        }
    }
    return -1 ;// sai thì trả về -1 
}

bool Check_odd_first_number(int n)//kiểm tra số nào có chữ số đầu tiền là số lẻ 
{
    int temp = n;
    while( temp > 9)
    {
        temp = temp /10; // rút gọn số <=> lấy số ban đầu 
    }
    if(temp % 2 !=0) // kiểm tra số lẻ 
    {
        return true ; // trả về đúngg
    }
    return false;// trả về sai 
}

int Find_odd_first_number(int *ptr , int n) // tìm sso nào có chữ số đầu tiên là số lẻ trong dãy 
{
    for(int i = 0 ; i < n ; i++)
    {
        bool check = Check_odd_first_number(ptr[i]); // gán biến check 
        if(check == true ) // kiểm tra điều kiện đúng
        {
            return ptr[i]; // trả về giá trị đó 
        }
    }
    return -1 ; // trả về giá trị -1 
}

bool Check_Number_2(int n) // kiểm tra số đó có phải là 2^k
{
    for(int i = 0 ; i < n ;i++)
    {
        if(n == pow(2,i)) // điều kiện kiểm tra 
        {
            return true ;// trả về đúng
        }
    }
    return false; // trả về sai 
}

int Number_2(int *ptr , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        bool check = Check_Number_2(ptr[i]);//gán giá trị biến check 
        if(check == true) // check đúng 
        {
            cout<<ptr[i]<<"\t"; // print ra giá trị đó 
        }
    }
}

int Find_max(int *ptr , int n ) // tìm giá trị lớn nhất
{
    int Max = ptr[0];
    for(int i = 0 ; i < n ; i++)
    {
        if(Max < ptr[i]) // max nhỏ hơn ptr[i]
        {
            Max = ptr[i]; //gán max = ptr[i]
        }
    }
    return Max ; //trả về giá trị lớn nhất

}

int Find_BCNN(int *ptr , int n) // tìm bội chung nhỏ nhất 
{
    int Max = Find_max(ptr , n); // gán max bằng hàm tìm giá trị lớn nhất 
    int BCNN = Max ; // BCNN bằng Max
    
    while(true) // vòng lặp chạy gặp False sẽ dừng
    {
        bool check = true ; 
        for(int i = 0 ; i < n ; i++)
        {
            if(BCNN % ptr[i] != 0) // BCNN chia cho phần từ trong mảng => khác 0
            {
                check = false ; //vòng lặp dừn
                break;
            }
        }
        if(check == true) // check true thì vòng lặp chạy
        {
            return BCNN; // trả về bcnn 
        }
        BCNN += Max;
    }
}

int Listtheleastvisibledigit(int *ptr , int n )
{
    int count[10] = {0};
    for(int i = 0 ; i < n ; i++)
    {
        if(ptr[i] == 0)
        {
            count[0]++;
        }
        else
        {
            int temp = ptr[i];
            while(temp != 0 )
            {
                int num = temp % 10 ; 
                count[num]++;
                temp /= 10 ;
            }
        }
    }
    int min = 0 ; 
    for(int i = 0 ; i < n ; i++)
    {
        if(count[i] != 0 )
        {
            if(min == 0)
            {
                min = count[i];
            }
            else 
            {
                if(count[i] < min)
                {
                    min = count[i];
                }
            }
        }
    }
    cout<<"List the element the appear at least : ";
    for(int i = 0 ; i < n ; i++)
    {
        if(count[i] == min )
        {
            cout<<i<<"\t";
        }
    }
}

int Solve_sum_odd_first_number(int *ptr , int n)
{
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        bool check = Check_odd_first_number(ptr[i]);
        if(check == true)
        {
            sum += ptr[i];
        }
    }
    return sum ;
}

bool Check_prime(int x)
{
    if(x < 2 )
    {
        return false;
    }
    if(x == 2)
    {
        return true;
    }
    for(int i = 2 ; i < x ; i++)
    {
        if( x % i == 0 )
        {
            return false ;
        }
    }
    return true ;
}

int Sovle_sum_prime(int *ptr , int n)
{
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        bool check = Check_prime(ptr[i]);
        if(check == true)
        {
            sum += ptr[i];
        }
    }
    return sum ;
}

int Count_prime(int *ptr , int n)
{
    int count = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        bool check = Check_prime(ptr[i]);
        if(check == true )
        {
            count++;
        }
    }
    return count;
}

int Delete_elements(int *ptr , int n ,int vt)
{
    for(int i = vt ; i < n-1 ; i++ )
    {
        ptr[i] = ptr[i-1];
    }
    n--;
    ptr = (int*)realloc(ptr,(n--)*sizeof(int)); // xoá bộ nhớ đã cấp phát 
}

int Removeduplicateelementsandkeepone(int *ptr , int &n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n ; j++) // kiểm tra xem đăng sau còn đứa nào trùng khong 
        {
            if(ptr[i] == ptr[j])
            {
                Delete_elements(ptr , n ,j);
                j--;
            }
        }
    }
}

int Add_elements(int *&ptr ,int &n ,int vt ,int add )
{
    n++;
    ptr =(int*)realloc(ptr,n*sizeof(int));
    for(int i = n - 1 ; i >vt ; i--)
    {
        ptr[i]=ptr[i-1];
    }
    ptr[vt]=add;
}

void Add_number0_even_positive(int *&ptr , int &n )
{
    for(int i = 0 ; i < n ; i++)
    {
        if(ptr[i] % 2 == 0 && ptr[i] > 0)
        {
            Add_elements(ptr , n , i+1 , 0);
            i++;
        }
    }
}

int Find_min_odd_number(int *ptr , int n )
{
    int min = 0 ; 
    for(int i = 0 ; i < n ; i++)
    {
        if(ptr[i] % 2 != 0)
        {
            min =ptr[i];
            break;
        
        }
    }
    if(min == 0)
    {
        return min ;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(ptr[i] < min && ptr[i] % 2 != 0)
        {
            min = ptr[i];
        }
    }
    return min ;
}

int Permutation(int *ptr , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n; j++)
        {
            if(ptr[i] < ptr[j])
            {
               swap(ptr[i], ptr[j]);
               /*
               int temp = ptr[i];
               ptr[i] = ptr[j];
               ptr[j] = temp;
               */
            }
        }
    }
}

//Hàm Huyền Thoại
bool Check_duplicate(int *ptr , int n ,int index)
{
    for(int i = 0 ; i < index ; i++)
    {
        if(ptr[i] = ptr[index])
        {
            return true ; // bị trùng số đằng trước 
        }
    }
    return false ;
}

int Count_occurrences_ofX(int *ptr ,int n,int x )
{
    int count = 0 ; 
    for(int i = 0 ; i < n ; i++)
    {
        if(ptr[i] == x)
        {
            count++;
        }
    }
    return count;
}

int List_frequency(int *ptr , int n)
{
    Permutation(ptr, n);
    cout<<endl;
    Export(ptr , n);
    for(int i = 0 ; i < n ; i++)
    {
        if(Check_duplicate(ptr,n,i))
        {
            continue;
        }
        
        else
        {
            int count = Count_occurrences_ofX(ptr , n ,ptr[i]);
            cout<<ptr[i]<<"frequency is"<<count<<endl;
        }
    }
}

bool Check_symmetric_array(int *ptr , int n)
{
    for(int i = 0 ; i < n/2 ; i++)
    {
        if(ptr[i] != ptr[n - 1 - i])
        {
            return false;
        }
    }
    return true ;
}

int main()
{
    int *ptr = NULL;
    int n = 0 ; 
    int select ;
    do
    {
        system("cls");
        cout<<"\t\t\t------------------------------MENU---------------------------------"<<endl;
        cout<<"\t\t\t|1. |    Import the array                                       | |"<<endl;
        cout<<"\t\t\t|2. |    Export the array                                       | |"<<endl;
        cout<<"\t\t\t|3. |    Find sysmetric number                                  | |"<<endl;
        cout<<"\t\t\t|4. |    Find the first odd digit                               | |"<<endl;
        cout<<"\t\t\t|5. |    List number of the form 2^k                            | |"<<endl;
        cout<<"\t\t\t|6. |    Find the max number                                    | |"<<endl;
        cout<<"\t\t\t|7. |    Find the BCNN                                          | |"<<endl;
        cout<<"\t\t\t|8. |    List the element the appears at least                  | |"<<endl;
        cout<<"\t\t\t|9. |    Sum of the first odd digit                             | |"<<endl;
        cout<<"\t\t\t|10.|    Average of the prime number                            | |"<<endl;
        cout<<"\t\t\t|11.|    Remove dupicate elements , keep only the first element | |"<<endl;
        cout<<"\t\t\t|12.|    Sort array descending                                  | |"<<endl;
        cout<<"\t\t\t|13.|    Add element                                            | |"<<endl;
        cout<<"\t\t\t|14.|    Add number 0 after even element                        | |"<<endl;
        cout<<"\t\t\t|15.|    Find minimum value of odd element                      | |"<<endl;
        cout<<"\t\t\t|16.|    Count occurrences of x                                 | |"<<endl;
        cout<<"\t\t\t|17.|    List frequency                                         | |"<<endl;
        cout<<"\t\t\t|18.|    Check sysmetric array                                  | |"<<endl;
        cout<<"\t\t\t|0. |    Quit                                                   | |"<<endl;
        cout<<"\t\t\t-------------------------------------------------------------------"<<endl;
        cout<<"Inviting you select : ";
        cin >> select;
        switch(select)
        {
            case 1 : 
            {
                do
                {
                    cout<<"Enter the value n : "<<endl;
                    cin >> n ;
                    if( n < 0)
                    {
                        cout<<"Request to re-enter , please "<<endl;
                    }
                } while ( n < 0);
                //cấp phát động bộ nhớ con trỏ
                ptr = new int[n];
                Import(ptr , n);
                break; 
            }
            case 2 : 
            {
                Export(ptr , n);
                system("pause");
                break;
            }
            case 3 :
            {
                cout<<"Symmetric number in array "<<Find_symmetric_number(ptr , n)<<endl;
                system("pause");
                break;
            }
            case 4 :
            {
                cout<<"Odd numbers whose first number is odd is"<<Find_odd_first_number(ptr , n)<<endl;
                system("pause");
                break;
            }
            case 5 :
            {
                cout<<"List number of the form 2^k is "<<Number_2(ptr , n)<<endl;
                system("pause");
                break;
            }
            case 6 :
            {
                cout<<"The number max : "<<Find_max(ptr , n)<<endl;
                system("pause");
                break;
            }
            case 7 : 
            {
                cout<<"BCNN is : "<<Find_BCNN(ptr , n);
                system("pause");
                break;
            }
            case 8 : 
            {
               Listtheleastvisibledigit(ptr ,n);
                system("pause");
                break;
            }
            case 9 :
            {
                cout<<"Sum of the first odd digit : "<<Solve_sum_odd_first_number(ptr , n)<<endl;
                system("pause");
                break;
            }
            case 10:
            {
                float avg = 0 ;
                int count = 0 ;
                for(int i = 0 ; i < n ; i++)
                {
                    if(Check_prime(ptr[i])== true)
                    {
                        count++;
                    }
                }
                avg = (float)Sovle_sum_prime(ptr,n)/count;
                cout<<"Average of the prime number is "<<avg<<endl;
                system("pause");
                break;
            }
            case 11 :
            {
                cout<<"The array after removing dupicate elemnets , keep only the first elemnt : "<<endl;
                Removeduplicateelementsandkeepone(ptr , n);
                Export(ptr ,n);
                system("pause");
                break;
            }
            case 12 : 
            {
                cout<<"The array descending : "<<endl;
                Permutation(ptr , n);
                Export(ptr , n);
                system("pause");
                break;
            }
            case 13 :
            {
                int add , vt;
                cout<<"Enter the element : ";
                cin >> add;
                cout<<"Enter the located : ";
                cin >> vt ;
                cout<<"The array after adding element : "<<endl;
                Add_elements(ptr , n ,vt ,add);
                Export(ptr ,n );
                system("pause");
                break;
            }
            case 14 :
            {
                cout<<"The array after adding number O behind even number : " <<endl;
                Add_number0_even_positive(ptr ,n );
                Export(ptr ,n);
                system("pause");
                break;
            }
            case 15 : 
            {
                cout<<"The minimum value of odd element : "<<Find_min_odd_number(ptr , n)<<endl;
                system("pause");
                break;
            }
            case 16 : 
            {
                int x ;
                cout<<"Enter the value x : ";
                cin >> x;
                cout<<"Count occurrences of x :"<<Count_occurrences_ofX(ptr , n ,x)<<endl;
                system("pause");
                break;
            }
            case 17:
            {
                List_frequency(ptr,n);
                system("pause");
                break;
            }
            case 18:
            {
                if(Check_symmetric_array(ptr , n) == true)
                {
                    cout<<"The array is symmetric "<<endl;
                }
                else
                {
                    cout<<"The array isn't symmetric"<<endl;
                }
                system("pause");
                break;
            }
            case 0 : return 0 ; break;
            default:
            {
                cout<<"You entered it wrong , request to re-enter , please !"<<endl;
                break;
            }
        }
    } while (select != 0);
    if(ptr != NULL)
    {
        delete[] ptr;
    }

    return 0;
}