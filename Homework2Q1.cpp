#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Defining set variables
    const double gravconst = 6.673e-8;
    char repeat = 'y';

    while (repeat == 'y' || repeat == 'Y') {

        // Defining our variables
        double m1_g, m2_g, d_cm;

        // Taking in our inputs
        cout << "Enter mass m1 (kg): ";
        cin >> m1_g;
        cout << "Enter mass m2 (kg): ";
        cin >> m2_g;
        cout << "Enter distance d (cm): ";
        cin >> d_cm;

        // Caculations
        m1_g = m1_g * 1000.0;
        m2_g = m2_g * 1000.0;

        double F = (gravconst * m1_g * m2_g) / pow(d_cm, 2.0);

        // Output
        cout << "Gravitational force F = " << F << " dynes\n";

        // Repeating loop
        cout << "Run again? (y/n): ";
        cin >> repeat;
        cout << "\n";
    }
    return 0;
}