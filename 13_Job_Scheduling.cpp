#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

int jobSequencing(vector<Job> jobs) {
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
        return a.profit > b.profit;
    });
    int maxD = 0;
    for (auto &j : jobs) maxD = max(maxD, j.deadline);
    vector<int> slot(maxD + 1, -1);
    int totalProfit = 0;
    for (auto &j : jobs) {
        for (int t = j.deadline; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = j.id;
                totalProfit += j.profit;
                break;
            }
        }
    }
    return totalProfit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Job> jobs(n);
    cout << "Enter id, deadline, profit for each job:\n";
    for (int i = 0; i < n; i++) cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    cout << "Max profit: " << jobSequencing(jobs) << "\n";
    return 0;
}
