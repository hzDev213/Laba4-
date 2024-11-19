#include <iostream>
#include <cmath>

using namespace std;


double f(double x, bool pro) {
    if (pro)
    {
        return exp(x); // Возвращает e^x
    }
    else 
    {
        return x * x; // Возвращает x^2
    }
}


double one(double x, double p) {
        double fx = f(x, true); // e^x
        return 2 * pow(fx, 3) + 3 * pow(p, 2); // vozvrat formuli 
}


double two(double x, double p) {
        double fx = f(x, true); // e^x
        return abs(fx - p); 
}


double three(double x, double p) {
        double fx = f(x, false); // x^2
        return pow((fx - p), 2);
}

int main() {
    double x,p;
    cout << "enter x ";
    cin >> x;
    cout << "enter p ";
    cin >> p;

double result;

if (x>abs(p)) {
   result = one(x,p); // peredaem x kak 1 parametr, a p kak 2 
}
    else if (x>3 && x < abs(p)) {
    result = two(x, p);
}
 else if (x == abs(p)) {
     result = three(x, p);
    }
 else {
     result = 0; 
    }

cout << "result is: "<< result << endl;

}


