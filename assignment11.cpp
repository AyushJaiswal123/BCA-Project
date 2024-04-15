#include <iostream>
using namespace std;
class Add_matrix {
private:
    int m1[3][3];
public:
    Add_matrix() {}
    Add_matrix(int initData[3][3]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m1[i][j] = initData[i][j];
            }
        }
    }
    Add_matrix operator+(const Add_matrix& other) const {
        Add_matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.m1[i][j] = this->m1[i][j] + other.m1[i][j];
            }
        }
        return result;
    }
    void display() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << m1[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    int data1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int data2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    Add_matrix OBJ1(data1);
    Add_matrix OBJ2(data2);
    Add_matrix OBJ3 = OBJ1 + OBJ2;
    cout << "Sum of matrices:" << endl;
    OBJ3.display();
    return 0;
}
