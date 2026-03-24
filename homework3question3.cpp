#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printarray(int arr[]) {

    char cols[] = {'A', 'B', 'C', 'D'};

    for (int i = 0; i < 40; i++) {
        if (i % 4 == 0) {
            int row = (i / 4) + 1;
            if (row == 10) {
                cout << row << " ";
            } else {
                cout << row << "  ";
            }
        }
        if (arr[i] == 1) {
            cout << "X ";
        } else {
            cout << cols[i % 4] << " ";
        }
        if ((i + 1) % 4 == 0) {
            cout << endl;
        }
    }


    return;
}

int creatingarray(const vector<string>& storage) {

    int arr[40] = {};
    int num = -1;

    for (int i = 0; i < storage.size(); i++) {
        string input = storage[i]; 
        int row = stoi(input.substr(0, input.size() - 1));
        string col = input.substr(input.size() - 1);

        num = (row - 1) * 4;

        if (col == "A") {
            num += 0;
        } else if (col == "B") {
            num += 1;
        } else if (col == "C") {
            num += 2;
        } else {
            num += 3;
        }
        arr[num] = 1; 
        num = -1;
    }

    printarray(arr);

    return 0;
}






int main() {

    vector<string> storage;

    while (true) {

        string input;
        string answer;

        cout << "Seat ID: ";
        while (true) {
            cin >> input;
            bool duplicate = false;
            for (string s : storage) {
                if (s == input) {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate) {
                cout << "Seat already taken, enter a different seat ID: ";
            } else {
                storage.push_back(input);
                break;
            }
        }

        creatingarray(storage);


        cout << "Continue? ";
        cin >> answer;
        if (answer == "No") {
            break;
        }
    }
}