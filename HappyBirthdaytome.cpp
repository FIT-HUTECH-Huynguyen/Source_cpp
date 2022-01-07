// Happy birthday to me 
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <vector>
using namespace std;
void printLine(int n)
{
    cout<<"\t";
    for(int i = 0 ; i <= n ; i++)
    {
        cout<<"--";
    }
    cout<<endl;
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void printPhoto()
{
    string days;
	while (true)
	{
		system("cls");
		cout << endl << endl;
		cout << "\t\t DAY OF BIRTH ? ";
		getline(cin, days);
		if (days == "25/01")
		{
			cout << "\t\t---Happy Birthday to me !---" << endl <<endl;
			cout << "\t\t Happy Birthday to me " << endl;
			Sleep(1000);
			cout << "\t\t Happy Birthday to me " << endl; Sleep(1000);
			cout << "\t\t Happy Birthday to me " << endl; Sleep(1000);
			cout << "\t\t Happy Birthday to me " << endl; Sleep(1000);
			cout << "\t\t Happy Birthday to me " << endl; Sleep(1000);
			cout << "\t\t Happy Birthday to me " << endl; Sleep(1000);
			cout << "\t\t Happy Birthday to me " << endl << endl;

			vector <int> A;
			A.push_back(7);
			A.push_back(12);
			A.push_back(14);
			A.push_back(10);
			
			int i = 0;
			SetColor(A.at(i++ % A.size()));

			ifstream file;
			file.open("C:\\Users\\Admin\\Downloads\\banner.txt", ios_base::in); //import file thì copy đường dẫn rồi đổi \ thành \\ hoặc /
			string line;
			while (getline(file, line)) {
				cout << line << endl;
				Sleep(30); 
			}
			file.close();

			SetColor(A.at(i++ % A.size()));
			
			_getch();
		}
		else
		{
			cout << "\t\tSAI ROI ;((" << endl << endl;
			system("pause");
		}
	}
}
int main()
{
    char h = '\3';
    cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t"<<h<<" MY NAME IS NGUYEN MAI BAO HUY "<<h<<endl<<"\t\t\t   "<<h<<" DATE OF BIRTH :25/01/2003  "<<h<<endl<<"\t\t\t\t  "<<h<<" AGE : 19 "<<h<<endl;
    printLine(30);
    Sleep(3002);
    Beep(532,500);
    system("cls");
    cout<<endl<<endl<<endl<<"\t\t\t"<<h<<" copyright : huynguyen "<<h<<endl;
    Sleep(500);
    Beep(532,500);
    printLine(30);
    Sleep(500);
    Beep(532,500);
    cout<<endl<<endl<<"\t\t\t\t  "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<endl;
    Sleep(500);
    Beep(532,500);
    cout<<"\t\t\t\t  i i i i i"<<endl;
    Sleep(500);
    Beep(532,500);
    cout<<"\t\t\t\t__i_i_i_i_i__";
    Sleep(500);
    Beep(532,500); 
    cout<<endl<<"\t\t\t       |"<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h << "|";
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t\t      _________________";
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t\t     |"<< h << " Happy\t"<< h <<"     " << h << "|"; 
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t\t    _____________________";
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t\t   |"<< h << "\t "<< h <<"    Birthday  "<< h << "|";
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t\t  _________________________";
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t\t |"<< h <<"     To Me\t  "<< h <<"       "<< h << "|";
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t\t_____________________________";
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t       |"<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<" "<< h <<"|";
    Sleep(500);
    Beep(532,500);
    cout<<endl<<"\t\t       _______________________________"<<endl;
    Sleep(3002);
    printPhoto();
    Sleep(5000);

    return 0 ;
}   
