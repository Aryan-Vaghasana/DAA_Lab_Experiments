#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

vector<Activity> selectActivities(vector<Activity> a) {
    sort(a.begin(), a.end(), [](const Activity &x, const Activity &y) {
        return x.finish < y.finish;
    });
    vector<Activity> res;
    if (a.empty()) return res;
    res.push_back(a[0]);
    int lastFinish = a[0].finish;
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i].start >= lastFinish) {
            res.push_back(a[i]);
            lastFinish = a[i].finish;
        }
    }
    return res;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    vector<Activity> a(n);
    cout << "Enter start and finish time of each activity:\n";
    for (int i = 0; i < n; i++) cin >> a[i].start >> a[i].finish;
    vector<Activity> chosen = selectActivities(a);
    cout << "Selected activities (start finish):\n";
    for (auto &act : chosen) cout << act.start << " " << act.finish << "\n";
    return 0;
}
