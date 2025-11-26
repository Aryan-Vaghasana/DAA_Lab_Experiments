#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &a) {
    if (a.empty()) return;
    int maxVal = *max_element(a.begin(), a.end());
    vector<int> cnt(maxVal + 1, 0);
    for (int x : a) cnt[x]++;
    int idx = 0;
    for (int v = 0; v <= maxVal; v++) {
        while (cnt[v]--) a[idx++] = v;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter non-negative elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    countingSort(a);
    cout << "Sorted array:\n";
    for (int x : a) cout << x << " ";
    return 0;
}
