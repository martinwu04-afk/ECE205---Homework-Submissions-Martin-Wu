#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int winners[4];
    int count = 0;

    while (count < 4) {
        // Random number generator 
        int pick = rand() % 25 + 1;  
        
        // Assume that the number is not picked twice
        bool alreadyPicked = false;

        // checking statement to make sure that number is not repeated, redifining the boolean if it is
        for (int i = 0; i < count; i++) {
            if (winners[i] == pick) {
                alreadyPicked = true;
                break;
            }
        }

        // putting the picked number into the winners array
        if (!alreadyPicked) {
            winners[count] = pick;
            count++;
        }
    }

    // Pritning out the winning numbers
    cout << "Winners: ";
    for (int i = 0; i < 4; i++) {
        cout << winners[i] << " ";
    }

    return 0;
}
