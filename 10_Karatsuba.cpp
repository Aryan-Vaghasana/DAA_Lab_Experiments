#include <bits/stdc++.h>
using namespace std;

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) return x * y;
    int n = max((int)to_string(x).size(), (int)to_string(y).size());
    int m = n / 2;
    long long p = 1;
    for (int i = 0; i < m; i++) p *= 10;
    long long a = x / p, b = x % p;
    long long c = y / p, d = y % p;
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long ad_bc = karatsuba(a + b, c + d) - ac - bd;
    return ac * p * p + ad_bc * p + bd;
}

int main() {
    long long x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "Product using Karatsuba: " << karatsuba(x, y) << "\n";
    return 0;
}
