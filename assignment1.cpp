 #include<iostream>
using namespace std;
class ATM{
    int id,pass,logid,logpass,starting_bal=0,label,amount_deposited,amount_withdrawn;
    char option,choice;
    bool cont;
public:

void printIntroMenu(){
 cout<<"Hi this is Ayush's ATM Machine !!!"<<endl;
    cout<<"please select an option from below"<<endl;
    cout<<"l -> login"<<endl;
     cout<<"c -> create new account"<<endl;
      cout<<"q -> quit"<<endl;
    cin>>option;
}
void createIDpass(){
     cout<<"creating a new account !!"<<endl;
     cout<<"Enter your user ID"<<endl;
     cin>>id;
      cout<<"Enter your password"<<endl;
     cin>>pass;
     cout<<"** Your account has been created **"<<endl;

}
void loginIDpass(){
cout<<"You are logging in"<<endl;
cout<<"enter your ID"<<endl;
cin>>logid;
cout<<"Enter your passworrd"<<endl;
cin>>logpass;
}
void choicefunc(){
     cout<<"d -> deposit money"<<endl;
     cout<<"w -> withdraw money"<<endl;
      cout<<"r -> request balance"<<endl;
    cin>>choice;
}
void start(){
printIntroMenu();
int label;
switch(option){
    case 'l':
    loginIDpass();
    if(logid==id &&logpass==pass){
        cout<<"you are successfully logged in"<<endl;
    }
    else{
        case 'c':
        cout<<"******Login Failed*****"<<endl;
        createIDpass();
    }
    case 'q':break;

}
label:
choicefunc();
switch(choice){
    case 'd':
    cout<<"enter your amount to be deposited !!"<<endl;
    cin>>amount_deposited;
    starting_bal+=amount_deposited;
    cout<<"do u want to continue??"<<endl;
    cout<<"press 1 for continue...0 for not";
    cin>>cont;
    if(cont==1){
        goto label;
    }
    else{
    break;}
    case 'w':
    cout<<"enter amount to be withdrawn"<<endl;
    cin>>amount_withdrawn;
    starting_bal-=amount_withdrawn;
     cout<<"do u want to continue??"<<endl;
    cout<<"press 1 for continue...0 for not";
    cin>>cont;
    if(cont==1){
        goto label;
    }
    else{
    break;}
case 'r':
cout<<"your balance is:"<<starting_bal<<endl;

}
}
};
int main(){
    ATM a1;
    a1.start();
   return 0;
}
