#include <iostream>
#include <vector>
using namespace std;

void deleteRepeatedChars(vector<char>& myVector) {
    for (int i = 0; i < (int) myVector.size(); i++) {
        for (int j = 0; j < (int) myVector.size(); j++) {
            if (myVector[j] == myVector[i]) {
                myVector.erase(myVector.begin() + j);
            } else {
                j++;
            }
        }
    }
}

void selectionSort(vector<char>& myVector) {
    for (int i = 0; i < (int) myVector.size() - 1; i++) {
        int index = i;
        for (int j = i + 1; j < (int) myVector.size(); j++) {
            if (myVector[j] > myVector[index]) index = j;
        }
        char temp = myVector[index];
        myVector[index] = myVector[i];
        myVector[i] = temp;
    }
}

void printChars(vector<char>& v) {
    for (char c:v) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter characters one at a time (enter 0 to stop):" << endl;
    vector<char> chars;
    char input;

    while (cin >> input && input != '0') {
        chars.push_back(input);
    }
 
    cout << "Original: "; 
    printChars(chars);
 
    deleteRepeatedChars(chars);
    cout << "Repeats removed: "; 
    printChars(chars);
 
    selectionSort(chars);
    cout << "Sorted: "; 
    printChars(chars);
 
    return 0;
}

