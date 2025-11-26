#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

double greedy01Knapsack(vector<Item> items, int W) {
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });
    int curW = 0;
    int totalVal = 0;
    for (auto &it : items) {
        if (curW + it.weight <= W) {
            curW += it.weight;
            totalVal += it.value;
        }
    }
    return totalVal;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) cin >> items[i].weight >> items[i].value;
    cout << "Enter capacity W: ";
    cin >> W;
    cout << "Greedy 0/1 knapsack value: " << greedy01Knapsack(items, W) << "\n";
    return 0;
}
