#include <bits/stdc++.h>
using namespace std;

vector<int> rabinKarp(const string &text, const string &pat) {
    const int d = 256;
    const int q = 101;
    int n = text.size(), m = pat.size();
    vector<int> res;
    if (m == 0 || m > n) return res;
    int h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * d) % q;
    int p = 0, t = 0;
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pat[j]) { ok = false; break; }
            }
            if (ok) res.push_back(i);
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
    return res;
}

int main() {
    string text, pat;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pat;
    vector<int> pos = rabinKarp(text, pat);
    if (pos.empty()) cout << "Pattern not found\n";
    else {
        cout << "Pattern found at indices: ";
        for (int p : pos) cout << p << " ";
    }
    return 0;
}
