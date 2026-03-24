#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findMax(const vector<int>& inputarray) {
    int max = inputarray[0];
    for (int i = 1; i < inputarray.size(); i++) {
        if (inputarray[i] > max) {
            max = inputarray[i];
        }
    }
    return max;
}

vector<int> bincalc(int maxvalue) {
    std::vector<int> bins;

    while (maxvalue >= 10) {
        bins.push_back(10);
        maxvalue = maxvalue - 10;
    }

    if (maxvalue > 0) {       
        bins.push_back(maxvalue);
    }

    return bins;
}

int sortingoutput(const vector<int>& inputarray, const vector<int> bins) {
    int count = 0;
    cout << "Bin Range  Number of values" << endl;
    if (bins.size() == 1) { 
        cout << "  0-9:       ";
        for (int i = 0; i < inputarray.size(); i++) {
            count = count + 1;
        }
        cout << count << endl;
    } else {
        for (int i = 0; i < bins.size(); i++) {
            if (i == 0) {
                cout << (10*i) << "-" << (9 + (10*i)) << ":       ";
            } else {
                cout << (10*i) << "-" << (9 + (10*i)) << ":     ";
            }
            for (int j = 0; j < inputarray.size(); j++) {
                if (inputarray[j] >= (10*i) && inputarray[j] <= (9 + (10*i))) {
                    count = count + 1;
                }
            }
            cout << count << endl;
            count = 0;
        }
    }
    
    return 0;
}

int main() {
    int size;

    cout << "Enter number of elements: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size." << endl;
        return 1;
    }

    std::vector<int> inputarray(size);

    for (int i = 0; i < size; i++) {
        std::cin >> inputarray[i];
    }

    int maxvalue;
    maxvalue = findMax(inputarray);

    vector<int> bins = bincalc(maxvalue);
    
    sortingoutput(inputarray, bins);

    return 0;
}