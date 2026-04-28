#include <iostream>
#include <vector>

using namespace std;

int getBin(int num) {
    return num / 10;
}

void printHistogram(vector <int> & nums) {
    if (nums.empty()) {
        cout << "No numbers entered." << endl;
        return;
    }

    int maxbin = 0;
    for (int n:nums) {
        if (getBin(n) > maxbin) {
            maxbin = getBin(n);
        }
    }

    vector<int> bins (maxbin + 1, 0);

    for (int n:nums) {
        bins[getBin(n)]++;
    }

    cout << "\n" << endl;
    cout << "Histogram: " << endl;
    for (int i = 0; i <= maxbin; i++) {
        cout << (i*10) << "-" << (i*10 + 9) << ": " << bins[i] << endl;
    }
}

int main() {
    cout << "Enter non-negative integers (enter a negative number to stop):" << endl;
 
    vector<int> nums;
    int input;
    while (cin >> input && input >= 0) {
        nums.push_back(input);
    }
 
    printHistogram(nums);
    return 0;
}
