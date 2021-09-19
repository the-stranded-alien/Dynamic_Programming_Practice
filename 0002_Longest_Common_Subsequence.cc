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

// Given two sequences, find the length of longest subsequence present in both of them.
// A subsequence is a sequence that appears in the same relative order, but not necessarily
// contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences
// of “abcdefg”. 

int longestCommonSubsequenceBU(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int> > dp((n1 + 1), vector<int>((n2 + 1), 0));
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n1][n2];
}   

int longestCommonSubsequenceTD(string s1, string s2, int i, int j, vii &dp) {
    // Base Case
    if(i == s1.length() || j == s2.length()) return 0;
    // LookUp
    if(dp[i][j] != -1) return dp[i][j];
    // Recursive Case
    if(s1[i] == s2[j]) return (dp[i][j] = 1 + longestCommonSubsequenceTD(s1, s2, i + 1, j + 1, dp));
    else return (dp[i][j] = max(
        longestCommonSubsequenceTD(s1, s2, i + 1, j, dp),
        longestCommonSubsequenceTD(s1, s2, i, j + 1, dp)
    ));
}

int main() {
    FIO;
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout << longestCommonSubsequenceBU(s1, s2) << nl;
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int> > dp((n1 + 1), vector<int>((n2 + 1), -1));    
    cout << longestCommonSubsequenceTD(s1, s2, 0, 0, dp) << nl;
    return 0;
}