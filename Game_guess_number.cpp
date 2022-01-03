/**
 *                              Game guess the number 
 * Implementation steps : 
 * step 1: Bot enter a random number [1..100]
 * step 2 : Player guess a number  [1..100]
 * step 3 : If player guesses a number is wrong . Request re-guess.
 * step 4 : if player guesses wrong more than 7 time. Player lose and end program.
 * step 5 : If player guesses true . player win .
 * step 6 : Program End. 
 */
#include <iostream> 
#include <time.h>
#include <stdlib.h>
using namespace std ; 
void Bot_enter(int &n) // Bot nhap mot gia tri ngau nhien trong doan  [1,100].
{
	srand(time(NULL));
	n = 1 + rand()%100;
}
void Player_guess(int &a, int n)
{
	int count=0;
	bool iswin = false;
	do
	{   
		cout<<"The bot has selected a number in the range , please guess the number : ";
	    cin>> a;
        count++;
        cout<<"You guessed the second time "<<count<<endl;
		if(a == n ) // kiem tra neu player dung 
		{
			cout<<"You guess righ,bot guess: "<<n<<endl;
			cout<<"\tYOU WIN."<<endl;
			iswin =true ;
			break;

		}
		else if (a > n ) // Neu player chon so lon hon bot chon
		{
			cout<<"The number you guessed is larger than the number entered by the bot "<<endl;
		}
		else // Neu player chon so nho hon bot chon
		{
			cout<<"The number you guessed is smaller than the number enter by the bot "<<endl;
		}
		if(count == 7) // neu player chon du 7 lan thi dung lai
		{
			break;//end program.
		}

	}while(true);
	if(iswin != true )
	{
		cout<<"\t GAME OVER \n";
	}
}
int main ()
{
	int n , a ;
	cout<<"\t\t\t*The game guess number* "<<endl;
	cout<<"\t\tStart Game"<<endl;
	Bot_enter(n);
	Player_guess(a , n );
	return 0;

}