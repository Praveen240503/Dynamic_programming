#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100001, vector<int>(4, -1));

int Fun(int ind, int n, vector<vector<int>>& arr, int prev) {
    if (ind >= n) return 0;
    if (dp[ind][prev] != -1) return dp[ind][prev];
    
    int ans = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (prev != i) {
            ans = max(ans, (arr[ind][i] + Fun(ind + 1, n, arr, i)));
        }
    }
    
    return dp[ind][prev] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << Fun(0, n, arr, 3);
}
