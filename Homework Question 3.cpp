#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

float cost;
float monthlyinterest;
int monthlypayment;
int months;
float interestpayment;
float finalpayment;
float principal;
float suminterest;
float totalpaid;
float interestrate;

int main() {

    months = 0;

    cout << "Cost of item?" << endl;
    cin >> cost;

    cout << "Interest (%)?" << endl;
    cin >> monthlyinterest;

    interestrate = monthlyinterest / 100;
    monthlyinterest = (monthlyinterest / 100) + 1;

    cout << "Monthly Payment?" << endl;
    cin >> monthlypayment;

    cout << "Month#   Interest   Principal   Balance   Total Interest   Total Paid" << endl;

    suminterest = 0;
    months = 0;
    totalpaid = 0;

    while (cost > 0) {
        months = months + 1;
        interestpayment = cost * interestrate;
        principal = monthlypayment - interestpayment;
        finalpayment = cost - principal;
        cost = finalpayment;
        suminterest = suminterest + interestpayment;
        totalpaid = totalpaid + monthlypayment;

        if (finalpayment < 0) {
            principal = principal + finalpayment;
            finalpayment = 0;
        } else {
            finalpayment = finalpayment;
        }

        cout << fixed << setprecision(2) << months << "        $" << interestpayment << "     $" << principal << "      $" << finalpayment << "   $" << suminterest <<  "           $" << totalpaid << endl;
    }

    return 0;
}