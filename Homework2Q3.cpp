#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    // Defining our variables
    double height, weight;
    int age;

    // Inputs
    cout << "Enter height (inches): ";
    cin >> height;
    cout << "Enter weight (pounds): ";
    cin >> weight;
    cout << "Enter age (years): ";
    cin >> age;

    // Calculation of the hat size
    double hat = 2.9 * weight / height;

    // Calculation of the jacket size
    double jacket = height * weight / 288.0;
    if (age > 30) {
        int decadesOver30 = (age - 30) / 10;
        jacket += decadesOver30 * 0.125;
    }
    
    // Calculation of the waist size
    double waist = weight / 5.7;
    if (age > 28) {
        int twoY = (age - 28) / 2;
        waist += twoY * 0.1;
    }

    // Outputs at a precision of two decimal places
    cout << fixed << setprecision(2);
    cout << "\nClothing Sizes:\n";
    cout << "Hat size: " << hat << "\n";
    cout << "Jacket size: " << jacket << "\n";
    cout << "Waist size: " << waist << "\n";

    return 0;
}
