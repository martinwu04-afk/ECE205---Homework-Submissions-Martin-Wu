#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int hours;
int depend;
float normpay, overtimepay, socialsec, fedtax, statax, localtax;
float totalpay;


int main() {

    cout << "How long has the employee worked?" << endl;
    cin >> hours;

    cout << "How many depedents does the employee have?" << endl;
    cin >> depend;

    if (hours > 40) {
        overtimepay = hours % 40;
        overtimepay = (hours % 40) * (1.5 * 36.75);
        normpay = 40 * 36.75;
    } else {
        overtimepay = 0;
        normpay = hours * 36.75;
    }

    totalpay = normpay + overtimepay;

    socialsec = totalpay * 0.06;
    fedtax = totalpay * 0.15;
    statax = totalpay * 0.04;
    localtax = totalpay * 0.01;

    totalpay = totalpay - socialsec - fedtax - statax - localtax - 20;

    if (depend > 2) {
        totalpay = totalpay - 40;
    } else {
        totalpay = totalpay;
    }


    cout << fixed << setprecision(2) << "Overtime Pay: " << overtimepay << endl;
    cout << fixed << setprecision(2) << "Normal Pay: " << normpay << endl;
    cout << fixed << setprecision(2) << "Net Pay: " << totalpay << endl;

    return 0;
}

