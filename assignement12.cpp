#include <iostream>
using namespace std;
class largeUnit; 
class smallUnit {
private:
    int inches;
public:
    smallUnit(int inches) : inches(inches) {}
    operator largeUnit();
    void display() const {
        std::cout << "Measurement in inches: " << inches << " inches" << std::endl;
    }
};
class largeUnit {
private:
    int feet;
public:
    largeUnit(int feet) : feet(feet) {}
    void display() const {
        std::cout << "Measurement in feet: " << feet << " feet" << std::endl;
    }
};
smallUnit::operator largeUnit() {
    return largeUnit(inches / 12); 
}

int main() {
    smallUnit smallUnit_OBJ(36); 
    largeUnit largeUnit_OBJ = smallUnit_OBJ; 
    smallUnit_OBJ.display();
    largeUnit_OBJ.display();

    return 0;
}
