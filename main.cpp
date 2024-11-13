#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long MOD = 10e9 + 7;
long long res = 0;

void
traversal(int currentInvest, int currentConstruct, long long left, unordered_set<string> &visited,
          vector<long long> &constructs,
          vector<long long> &invests, string currentPlan, int &n, int &m) {
//    if (currentPlan[currentInvest] != -1 or currentInvest >= m) return;
//    if (currentConstruct >= n) {
//        res = (res + 1) % MOD;
//        return;
//    }
    currentPlan[currentInvest] = static_cast<char>(currentConstruct + 65);
    if (visited.count(currentPlan)) return;
//    for (int i = 0; i < m; i++)
//    if (visited.count(currentPlan)) return;
//    visited.insert(currentPlan);
//    if (visited[currentInvest][currentConstruct]) return;
    if (left > invests[currentInvest]) {
        left -= invests[currentInvest];
//        currentPlan[currentInvest] = currentConstruct;
//        if (visited.count(currentPlan)) return;
//        visited.insert(currentPlan);
        visited.insert(currentPlan);
        for (int i = currentInvest + 1; i < m; i++) {
            if (currentPlan[currentInvest + 1] == '#')
                traversal(currentInvest + 1, currentConstruct, left, visited, constructs, invests, currentPlan, n, m);
        }
    } else if (left == invests[currentInvest]) {
//        currentPlan[currentInvest] = currentConstruct;
//        if (visited.count(currentPlan)) return;
//        visited.insert(currentPlan);
        if (currentConstruct + 1 == n) {
            res = (res + 1) % MOD;
//            cout << currentPlan << endl;
            return;
        }
        visited.insert(currentPlan);
        for (int i = 0; i < m; i++) {
            if (currentPlan[i] == '#' and invests[i] <= constructs[currentConstruct + 1])
                traversal(i, currentConstruct + 1, constructs[currentConstruct + 1], visited, constructs, invests,
                          currentPlan, n, m);
        }
    } else {
//        for (int i = currentInvest + 1; i < invests.size(); i++) {
//            traversal(i, currentConstruct, left, visited, constructs, invests, currentPlan);
//        }
    }
//    visited[currentInvest][currentConstruct] = true;
    return;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> constructs(n);
    vector<long long> invests(m);
    for (int i = 0; i < n; i++) {
        cin >> constructs[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> invests[j];
    }
    sort(invests.begin(), invests.end(), greater<>());
    sort(constructs.begin(), constructs.end(), greater<>());
//    vector<vector<bool>> visited(m, vector<bool>(n, false));
//    set<vector<int>> visited;
    unordered_set<string> visited;
    res = 0;
    for (int i = 0; i < m; i++) {
        string currentPlan;
        for(int j = 0; j < m; j++) currentPlan += "#";
        traversal(i, 0, constructs[0], visited, constructs, invests, currentPlan, n, m);
    }

    cout << res % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}

