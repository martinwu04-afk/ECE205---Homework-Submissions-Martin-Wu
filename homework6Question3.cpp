#include <iostream>
#include <vector>
using namespace std;

void sieve(int n) {
    if (n < 2) {
        cout << "No primes less than " << n << endl;
        return;
    }

    vector<int> isPrime;
    for (int i = 2; i < n; i++) {
        isPrime.push_back(i);
    }

    cout << "Original Vector " << n << ":" << endl;
    for (int p:isPrime) {
        cout << p << " ";
    }

    for (int i = 0; i < (int)isPrime.size(); i++) {
        int p = isPrime[i];
        for (int j = i + 1; j < (int)isPrime.size();) {
            if (isPrime[j] % p == 0) {
                isPrime.erase(isPrime.begin() + j);
            } else {
                j++;
            }
        }
    }

    cout << "\nPrimes less than " << n << ":" << endl;
    for (int p:isPrime) {
        cout << p << " ";
    }
    cout << endl;

}


int main() {
    cout << "Enter N:" << endl;
    int n;
    cin >> n;
    sieve(n);
    return 0;
}