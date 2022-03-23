#include <iostream>
#include <math.h>
#include <limits>
using namespace std;
/*  Jennifer Cabrera
    calculator program using object oriented techniques
*/
struct Calculator {
    enum class operation {
        add, 
        subtract, 
        multiply, 
        divide, 
        sqrt
    } op;
    Calculator (operation x) { op = x; }

    double calculate(double a, double b){
        switch (op) {
            case operation::add:{
                return a+b;
            } break;
            case operation::subtract:{
                return a-b;
            }break;
            case operation::multiply:{
                return a*b;
            }break;
            case operation::divide:{
                return a/b;
            }break;
            case operation::sqrt:{
                return sqrt(a);
            }break;
        }
        return 0;
    }
};

void clear(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
bool valid(int n){
    if(n>0 && n<6){return true;}
    return false; 
}


Calculator::operation whichoperation (int math){
    Calculator::operation op;
    if (math == 1) {
        op = Calculator::operation::add;
    } else if (math == 2) {
        op = Calculator::operation::subtract;
    } else if (math == 3) {
        op = Calculator::operation::multiply;
    } else if (math == 4) {
        op = Calculator::operation::divide;
    } else {
        op = Calculator::operation::sqrt;
    }
    return op;
}

int main () {
    double num1, num2;
    double sum;
    double math;
    Calculator::operation op;
    
    do{
        cout << "Indicate the operation you want to perform.\n"
        "1 for addition \n"
        "2 for subtraction\n"
        "3 for multiplication\n"
        "4 for division\n"
        "5 for sqrt\n\n";

        if( ( !(cin>> math) ) || (valid(math) == false) ) {
            cout << "operation not valid.\n\n";
            clear();
            continue;
        }

        if(math == 5){
            cout << "enter your number.\n";
            while(!(cin>> num1)){
                cout << "numbers only please!\n\n";
                clear();
            }
            num2=0;
            break;
        }
        cout << "enter your first number.\n";
        if(!(cin>> num1)){
            cout << "numbers only please!\n\n";
            clear();
            continue;
        }
        cout << "enter your second number.\n";
        if(!(cin>> num2)){
            cout << "numbers only please!\n\n";
            clear();
            continue;
        }
        

        break;

    } while (true);

    Calculator calc(op);
    op = whichoperation (math);
    sum = calc.calculate (num1, num2);
    cout << "your total is "<< sum << "\n\n";

};