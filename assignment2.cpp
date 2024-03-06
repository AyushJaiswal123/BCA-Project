#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
class randgame{
 int number,number_guess,number_of_attempts;
 public:
 void game(){
    srand(time(0));
 number=rand() % 100 +1;
    cout<<"****RANDOM NUMBER HAS BEEN GENERATED BETWEEN 1 TO 100****"<<endl;
 
  for (int i = 0; i < 120; i++)
  {
    cout<<"guess the number:"<<endl;
    cout<<"attempt no. "<<i+1<<endl;
    cin>>number_guess;
    if(number_guess<number){
        cout<<"number entered is smaller than computer generated number!!!"<<endl;
    }
    else if (number_guess>number)
    {
        cout<<"number entered is greater than computer generated number!!!"<<endl;
    }
    else if(number==number_guess){
        cout<<"congratulations!! u won the game in "<<i+1<<" no. of attempts"<<endl;
        break;
    }
    
  }
 }
};
int main(){
   
    randgame r1;
    r1.game(); 
  
    return 0;
}