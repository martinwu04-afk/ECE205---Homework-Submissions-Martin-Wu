#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ifstream fin("scores.txt");
    ofstream fout("output.txt");

    double scores[5];
    double sum = 0;

    // Read 5 scores
    for (int i = 0; i < 5; i++) {
        fin >> scores[i];
        sum += scores[i];
    }

    double mean = sum / 5;

    // Compute standard deviation
    double sqSum = 0;
    for (int i = 0; i < 5; i++) {
        sqSum += pow(scores[i] - mean, 2);
    }

    double stdev = sqrt(sqSum / 5);

    cout << fixed << setprecision(2);
    fout << fixed << setprecision(2);

    cout << "Average: " << mean << endl;
    cout << "Std Dev: " << stdev << endl;

    fout << "Average: " << mean << endl;
    fout << "Std Dev: " << stdev << endl;

    fin.close();
    fout.close();

    return 0;
}
