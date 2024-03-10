#include <iostream>
using namespace std;
class User {
private:
    string name;
    int birth_year,birth_day,birth_month;
    float salary,increment;
public:
    User();
    User(string name_, int birthYear_, int birthDay_, int birthMonth_, float salary_){
        name = name_;
        birth_year = birthYear_;
        birth_month = birthMonth_;
        birth_day = birthDay_;
        salary = salary_;
    }
    string getName(){
        return name;
    }
    float getSalary(){
        return salary;
    }
 void addIncrement(int percentage) {
    increment = (float)percentage / 100.0f;
    salary += salary * increment;
}
    int compareAge(User obj) {
        if (this->birth_year < obj.birth_year||(this->birth_year == obj.birth_year&&this->birth_month<obj.birth_month)||(this->birth_year==obj.birth_year&&this->birth_month == obj.birth_month && this->birth_day < obj.birth_day)) {
            return 1; 
        } else if (this->birth_year == obj.birth_year && this->birth_month == obj.birth_month && this->birth_day == obj.birth_day) {
            return 0; 
        } else {
            return -1; 
        }
    }
};
int main() {
    int x;
    User Obj1("user1", 2024, 2, 8, 10000), Obj2("user2", 2025, 4, 8, 20000);
    int result = Obj1.compareAge(Obj2);
    if (result == 1) {
        cout << Obj1.getName() <<" is elder\n";
    } 
    else if (result == 0) {
        cout << "Both are equal in age\n";
    } 
    else {
        cout << Obj2.getName() << " is younger\n";
    }
    cout << "Average Salary: " << (Obj1.getSalary() + Obj2.getSalary()) / 2 << endl;
    cout<<"Increment percentage:";
    cin>>x;
    Obj1.addIncrement(x);
    cout << "After Increment\n";
    cout << "Average Salary: " << (Obj1.getSalary() + Obj2.getSalary()) / 2 << endl;

    return 0;
}