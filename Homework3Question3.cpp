// Question 3
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int starttime, endtime, diff;

    cout << "Give me the start time: ";
    cin >> starttime;

    cout << "Give me the end time: ";
    cin >> endtime;

    starttime = ((starttime / 100) * 60) + (starttime % 100);
    endtime = ((endtime / 100) * 60) + (endtime % 100);

    diff = endtime - starttime;
    
    if (diff <= 0) {
        cout << "Invalid start time" << endl;
    } else {
        cout << "Difference in time: " << diff << endl;
    }
    return 0;
}
