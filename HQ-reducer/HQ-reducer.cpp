#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
using namespace std;

const static int PRIMES_INTO = 1000000000;
const static int NUMBERT_TO_REDUCT = 126;

vector<int> primes;

void sieve(int n) {
    vector<bool> isPrime = vector<bool>(n, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int h = 2; h*i < n; ++h) {
                isPrime[i*h] = 0;
            }
        }
    }
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
void reduce(int n) {
    cout << "Reduce " << n << endl << "Loading primes..." << endl;
    while (true) {
        cout << "";
        if (primes.size() > 0 && n < primes.at(primes.size() - 1)) {
            break;
        }
    }

    vector<int> reductions = reduction(NUMBERT_TO_REDUCT, primes);

    cout << NUMBERT_TO_REDUCT << " WAS REDUCTED WITH: ";
    for (int i = 0; i < reductions.size(); i++) {
        cout << "\n" << reductions[i];
    }
    cout << "\nREDUCTION LENGTH: " << reductions.size();

}


int main() {

    //vector<int> primes = sieve(PRIMES_INTO);

    thread th1(sieve, PRIMES_INTO);
    thread th2(reduce, NUMBERT_TO_REDUCT);
    th2.join();
    th1.join();

    cout << endl << "Number of primes between 0 and " << PRIMES_INTO << ": " << primes.size() << endl;

    system("pause");
}