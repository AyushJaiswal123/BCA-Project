#include <iostream>
using namespace std;
class B;
class A {
private:
    int a;
public:
    A(int a_val) : a(a_val) {}
    friend int sum(const A& objA, const B& objB);
};
class B {
private:
    int b;
public:
    B(int b_val) : b(b_val) {}
    friend int sum(const A& objA, const B& objB);
};
int sum(const A& objA, const B& objB) {
    return objA.a + objB.b;
}
int main() {
   
    A objA(5);
    B objB(10);
    int result = sum(objA, objB);
    cout << "Sum of private members:"<<result<<endl;

    return 0;
}
