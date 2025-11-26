#include <bits/stdc++.h>
using namespace std;

int partitionQS(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<int> &a, int l, int r) {
    if (l < r) {
        int p = partitionQS(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    quickSort(a, 0, n - 1);
    cout << "Sorted array:\n";
    for (int x : a) cout << x << " ";
    return 0;
}
