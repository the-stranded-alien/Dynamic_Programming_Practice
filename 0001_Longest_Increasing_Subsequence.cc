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

// The Longest Increasing Subsequence (LIS) problem is to find the length of the longest
// subsequence of a given sequence such that all elements of the subsequence are sorted
// in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80}
// is 6 and LIS is {10, 22, 33, 50, 60, 80}

int longestIncSubBU(vi arr) {
    int n = arr.size();
    vi dp(n, 1);
    int len = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], (1 + dp[j]));
                len = max(len, dp[i]);
            }
        }
    }
    return len;
}

int main() {
    FIO;
    vi arr{10, 22, 9, 33, 21, 50, 41, 60, 80, 5, 200};
    cout << longestIncSubBU(arr) << nl;
    return 0;
}