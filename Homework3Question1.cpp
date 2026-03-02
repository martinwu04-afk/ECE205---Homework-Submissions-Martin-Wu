// Question 1
#include <iostream>
using namespace std;

void getInput(int &hour24, int &minute);
void convertTime(int hour24, int minute, int &hour12, char &amPm);
void displayTime(int hour12, int minute, char amPm);


int main() {
    char amPm;
    int hour24, minute, hour12;
    
    while (true) {
        getInput(hour24, minute);

        if (hour24 < 0 || minute < 0) {
            cout << "Program ended.\n";
            break;
        }

        if (hour24 > 23 || minute > 59) {
            cout << "Invalid time. Please try again.\n\n";
            continue;
        }

        convertTime(hour24, minute, hour12, amPm);
        displayTime(hour12, minute, amPm);

        cout << endl;
    }
    return 0;
}

void getInput(int &hour24, int &minute) {
    cout << "Enter hour (0-23) and minute (0-59) sequentially: ";
    cin >> hour24 >> minute;
}

void convertTime(int hour24, int minute, int &hour12, char &amPm) {

    if (hour24 == 0) {
        hour12 = 12;
        amPm = 'A';
    }
    else if (hour24 < 12) {
        hour12 = hour24;
        amPm = 'A';
    }
    else if (hour24 == 12) {
        hour12 = 12;
        amPm = 'P';
    }
    else {
        hour12 = hour24 - 12;
        amPm = 'P';
    }
}

void displayTime(int hour12, int minute, char amPm) {
    cout << "12-hour format: ";

    cout << hour12 << ":";

    if (minute < 10)
        cout << "0";

    cout << minute << " ";

    if (amPm == 'A')
        cout << "AM";
    else
        cout << "PM";

    cout << endl;
}