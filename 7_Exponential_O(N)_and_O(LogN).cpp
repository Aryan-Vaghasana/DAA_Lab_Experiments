#include <bits/stdc++.h>
using namespace std;

long long linearPower(long long base, long long exp) {
    long long res = 1;
    for (long long i = 0; i < exp; i++) res *= base;
    return res;
}

long long fastPower(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

int main() {
    long long base, exp;
    cout << "Enter base and exponent: ";
    cin >> base >> exp;
    cout << "Linear O(N) power: " << linearPower(base, exp) << "\n";
    cout << "Fast O(logN) power: " << fastPower(base, exp) << "\n";
    return 0;
}
