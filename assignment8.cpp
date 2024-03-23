#include<iostream>
using namespace std;
class Series_sum{
int n;
public:
void get(){
cout<<"enter value of n"<<endl;
cin>>n;
}
void compute(){
    int sum = (n * (n + 1) * (n + 2)) / 6;
   cout<<"Value of Sum is:"<<sum<<endl;
}
};
int main(){
    Series_sum s1;
    s1.get();
    s1.compute();
    return 0;
}