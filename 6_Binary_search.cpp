#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int> &a, int key) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == key) return m;
        else if (a[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements (sorted):\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "Enter key to search: ";
    cin >> key;
    int idx = binarySearch(a, key);
    if (idx == -1) cout << "Element not found\n";
    else cout << "Element found at index " << idx << "\n";
    return 0;
}
