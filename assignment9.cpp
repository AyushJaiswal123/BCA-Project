#include<iostream>
using namespace std;
class OP_overload{
float a;
public:
OP_overload(float A) {
    a=A;
    }
void display() { 
    cout<<a<<endl; 
    }
int friend operator + (float h, OP_overload obj); 
};
int operator + (float h, OP_overload obj) {
return h + obj.a ;
}
int main() {
OP_overload obj1(290.2);
OP_overload obj2 = 500.34f + obj1;
obj2.display();
return 0;
}