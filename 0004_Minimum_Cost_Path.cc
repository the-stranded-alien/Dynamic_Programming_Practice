#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define PB push_back
#define POB pop_back
#define MP make_pair
#define F first
#define S second
#define nl '\n'
#define tab '\t'
#define pi pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function
// that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of
// the matrix represents a cost to traverse through that cell. The total cost of a
// path to reach (m, n) is the sum of all the costs on that path (including both
// source and destination). You can only traverse down, right and diagonally lower 
// cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1),
// and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.

int minCostPath(vii &cost, int m, int n) {
    if((m < 0) || (n < 0)) return INT_MAX;
    else if((m == 0) && (n == 0)) return cost[m][n];
    else return cost[m][n] + min(minCostPath(cost, m - 1, n - 1),
    min(minCostPath(cost, m - 1, n), minCostPath(cost, m, n - 1)));
}

int minCostPathTD(vii &cost, int m, int n, vii &dp) {
    if((m < 0) || (n < 0)) return INT_MAX;
    else if((m == 0) && (n == 0)) return (dp[m][n] = cost[m][n]);
    else if(dp[m][n] != -1) return dp[m][n];
    else {
        int op1 = minCostPathTD(cost, m - 1, n - 1, dp);
        int op2 = minCostPathTD(cost, m - 1, n, dp);
        int op3 = minCostPathTD(cost, m, n - 1, dp);
        return (dp[m][n] = cost[m][n] + min(op1, min(op2, op3)));
    }
}

int minCostPathBU(vii &cost, int m, int n) {
    vector<vector<int> > dp((m + 1), vector<int>((n + 1), 0));
    dp[0][0] = cost[0][0];
    for(int i = 1; i <= m; i++) dp[i][0] = (dp[i - 1][0] + cost[i][0]);
    for(int j = 1; j <= n; j++) dp[0][j] = (dp[0][j - 1] + cost[0][j]);
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = cost[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    // for(int i = 0; i <= m; i++) {
    //     for(int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    return dp[m][n];
}

int main() {
    FIO;
    int m = 2;
    int n = 2;
    vii cost{{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    cout << minCostPath(cost, m, n) << nl;
    vector<vector<int> > dp((m + 1), vector<int>((n + 1), -1));
    cout << minCostPathTD(cost, m, n, dp) << nl;
    cout << minCostPathBU(cost, m, n) << nl;
    return 0;
}