#include "bits/stdc++.h"

using namespace std;
bool check_adjacency(vector<int>& location, int new_candy_location, int& n) {

}
void traverse(vector<int>& candies, vector<int>& location, int& res, int& previous_value, int current_value, int first, int& n, int& m) {
    if (first == n) return;
    location[first] -= 1;
    current_value -= previous_value;
    previous_value += candies[first];
    current_value += candies[first] * (n - first + 1);
    first += 1;
    for (int i = n - 1; i > first; i--) {
        if (check_adjacency(candies, i, n)) {

        }
    }
}
void solve(int& m, vector<int>& candies) {
    int n;
    cin >> n;
    n -= m;
    int res = INT_MAX;

//    cout << res << " ";
}
int main() {
    int m, t;
    cin >> m >> t;
    vector<int> candies(m);
    vector<int> prefix_sum(m + 1);
    prefix_sum[0] = 0;
    for (int i = 0; i < m; i++) {
        cin >> candies[i];
        prefix_sum[i + 1] = prefix_sum[i] + candies[i];
    }
    prefix_sum.assign(prefix_sum.begin() + 1, prefix_sum.end());
    cout << prefix_sum.size();
    sort(candies.begin(), candies.end());
    while (t--) {
        solve(m, candies);
    }
    return 0;
}
