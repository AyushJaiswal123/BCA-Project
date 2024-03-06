#include <iostream>
using namespace std;
class computation{
public:
    int compute(int p,int q){
         return p+q;
         }  
    float compute(int p,float q){
         return p+q;
         }  
    double compute(int p,double q){
         return p+q;
         }  
    int compute(char p,char q){

        return (int) p + (int) q;
        } 
    int compute(char p,int q){ 

        return (int) p + q;
        }  
    int compute(){

         int p=0, q=0; 
         return p+q;
    } 
};
int main(){
    computation obj1;
    cout<<"Eg. no. 1: "<<obj1.compute(35,34)<<endl;
    cout<<"Eg. no. 2: "<<obj1.compute(90,29.5f)<<endl;
    cout<<"Eg. no. 3: "<<obj1.compute(17,35.5)<<endl;
    cout<<"Eg. no. 4: "<<obj1.compute('a','c')<<endl;
    cout<<"Eg. no. 5: "<<obj1.compute('z',60)<<endl;
    cout<<"Eg. no. 6: "<<obj1.compute()<<endl;
    return 0;
}