#include <iostream>
#include <vector>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime = vector<bool>(n, true);
    vector<int> primes = vector<int>();
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int h = 2; h*i < n; ++h) {
                isPrime[i*h] = 0;
            }
        }
    }
    return primes;
}

int nearest(int n, vector<int> primes) {
    for (int i = primes.size() - 1; i >= 0; i--) {
        int lastPrime = primes.at(i);
        if (lastPrime == 2) {
            return n;
        }
        int subtractionBetweenNumberAndLast = n - lastPrime;
        int subtractionBetweenNumberAndPrelast = n - primes.at(i - 1);

        if (subtractionBetweenNumberAndLast > 0 && subtractionBetweenNumberAndLast < subtractionBetweenNumberAndPrelast) {
            return lastPrime;
        }
    }
}

vector<int> reduction(int n, vector<int> primes) {
    vector< int > reductions;

    do {
        int nearestPrime = nearest(n, primes);
        n -= nearestPrime;
        reductions.push_back(nearestPrime);
    } while (n >= 1);

    return reductions;
}

int main() {

    vector<int> primes = sieve(300000);
    int number = 40;
    vector<int> reductions = reduction(number, primes);

    cout << number << " WAS REDUCTED WITH: ";
    for (int i = 0; i < reductions.size(); i++) {
        cout << "\n" << reductions[i];
    }
    cout << "\nREDUCTION LENGTH: " << reductions.size();
}

