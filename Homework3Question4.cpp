// Question 4
#include <iostream>
using namespace std;

void getInput(double &lb, double &oz);
void convertnumbers(double lb, double oz, double &kg);
void unitconverter(double kg, int &wholeKg, int &grams);

int main() {
    double lb, oz, kg;
    int wholeKg, grams;

    getInput(lb, oz);
    convertnumbers(lb, oz, kg);
    unitconverter(kg, wholeKg, grams);
    
    cout << wholeKg << " kg " << grams << " g";

    return 0;
}

void getInput(double &lb, double &oz) {
    cout << "Input the pounds: ";
    cin >> lb;

    cout << "Input the ounces: ";
    cin >> oz;
}

void convertnumbers(double lb, double oz, double &kg) {
    double totalPounds = lb + (oz / 16.0);
    kg = totalPounds / 2.2046;
}

void unitconverter(double kg, int &wholeKg, int &grams) {
    double totalGrams = kg * 1000;

    wholeKg = (int) totalGrams / 1000;
    grams = (int) totalGrams % 1000;
}