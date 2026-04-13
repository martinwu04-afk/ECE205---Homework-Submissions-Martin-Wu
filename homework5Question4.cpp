// Martin Wu Question 4

#include <iostream>
using namespace std;

class PrimeNumber {
private:
    int prime;

    bool isPrime(int n) const {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int nextPrime(int n) const {
        int candidate = n + 1;
        while (!isPrime(candidate)) {
            candidate++;
        }
        return candidate;
    }

    int prevPrime(int n) const {
        int candidate = n - 1;
        while (candidate >= 2 && !isPrime(candidate)) {
            candidate--;
        }

        if (candidate >= 2) {
            return candidate;
        } else {
            return 1;
        }
    }

public:
    PrimeNumber() {
        prime = 1;
    }

    PrimeNumber(int p) {
        prime = p;
    }

    int getPrime() const {
        return prime;
    }

    PrimeNumber operator++() {
        prime = nextPrime(prime);
        PrimeNumber result(prime);
        return result;
    }

    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;
        prime = nextPrime(prime);
        return temp;
    }

    PrimeNumber operator--() {
        prime = prevPrime(prime);
        PrimeNumber result(prime);
        return result;
    }

    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        prime = prevPrime(prime);
        return temp;
    }
};

int main() {
    PrimeNumber p1;
    cout << "Default: " << p1.getPrime() << endl;

    PrimeNumber p2(11);
    cout << "Starting overload test: " << p2.getPrime() << endl; 

    ++p2;
    cout << "After ++: " << p2.getPrime() << endl;

    --p2;
    cout << "After --: " << p2.getPrime() << endl;

    p2++;
    cout << "After postfix ++: " << p2.getPrime() << endl; 

    p2--;
    cout << "After postfix --: " << p2.getPrime() << endl;  

    return 0;
}