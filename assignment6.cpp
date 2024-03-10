#include<iostream>
#include<cstdlib>
using namespace std;
class samp{
public:
    int Compute(int (samp::*func)(int), int n) {
        return (this->*func)(n);
    }
    int findFactorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
    }
    int findSquare(int n) {
        return n * n;
    }
    int findCube(int n) {
        return n * n * n;
    }
};
int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage:" << argv[0] << " <N>" << endl;
        return 1;
    }
    int N = atoi(argv[1]);
     samp obj;
    int result = obj.Compute(&samp::findFactorial, N);
    cout << "Factorial: " << result << endl;
    result = obj.Compute(&samp::findSquare, N);
    cout << "Square: " << result << endl;
    result = obj.Compute(&samp::findCube, N);
    cout << "Cube: " << result << endl;

    return 0;
}
