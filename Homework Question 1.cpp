#include <iostream>
#include <string>

using namespace std;

int time;
float hours, minutes, seconds;
float re_h, re_m;

int main() {

    cout << "What is the time" << endl;
    cin >> time;

    hours = time / 3600;
    minutes = (time % 3600) / 60;
    seconds = (time % 3600) % 60;

    cout << hours << " Hours, " << minutes << " Minutes, "  << seconds << " Seconds" << endl;

    re_h = float(time) / 3600;
    re_m = float(time) / 60;

    cout << re_h << " Real hours" << endl;
    cout << re_m << " Real minutes" << endl;

    return 0;
}

