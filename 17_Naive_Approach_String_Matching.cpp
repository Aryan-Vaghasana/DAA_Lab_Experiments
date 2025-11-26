#include <bits/stdc++.h>
using namespace std;

vector<int> naiveSearch(const string &text, const string &pat) {
    vector<int> pos;
    int n = text.size(), m = pat.size();
    for (int i = 0; i + m <= n; i++) {
        int j = 0;
        while (j < m && text[i + j] == pat[j]) j++;
        if (j == m) pos.push_back(i);
    }
    return pos;
}

int main() {
    string text, pat;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pat;
    vector<int> pos = naiveSearch(text, pat);
    if (pos.empty()) cout << "Pattern not found\n";
    else {
        cout << "Pattern found at indices: ";
        for (int p : pos) cout << p << " ";
    }
    return 0;
}
