// Question 2
#include <iostream>
#include <cmath>
using namespace std;

void calculator(double a, double b, double c, double &area, double &perimeter);


int main() {
    double a, b, c;
    double area, perimeter;

    cout << "Enter three side lengths: ";
    cin >> a >> b >> c;

    calculator(a, b, c, area, perimeter);

    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;

    return 0;
}


void calculator(double a, double b, double c, double &area, double &perimeter) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        area = 0;
        perimeter = 0;
        return;
    }   
    perimeter = a + b + c;
    double s = perimeter / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
}