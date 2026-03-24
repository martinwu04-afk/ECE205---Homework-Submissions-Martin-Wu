#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findmax(const vector<int>& scores) {
    int max = scores[0];
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

int findmin(const vector<int>& scores) {
    int min = scores[(scores.size() - 1)];
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    return min;
}


int main() {

    float difficulty;
    cout << "Degree of difficulty:" << endl;
    while (true) {
        cin >> difficulty;
        if (difficulty >= 1.2 && difficulty <= 3.8) {
            break;
        } else {
            cout << "Out of range (1.2 -> 3.8), try again: " << endl;
        }
    }



    cout << "Input the judges scores:" << endl;
    int total = 0;
    vector<int> scores(7);

    while (true) {
        total = 0;
        bool valid = true;
        for (int i = 0; i < 7; i++) {
            cin >> scores[i];
            if (scores[i] < 0 || scores[i] > 10) {
                cout << "Invalid score. (0 - 10) Try again." << endl;
                valid = false;
                break;
            }
            total += scores[i];
        }
        if (valid) break;
    }

    int max = findmax(scores);
    int min = findmin(scores);

    total = total - max - min;
    total = total * difficulty * 0.6;

    cout << "Diving score: " << total << endl;
    
    return 0;
}