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

// Given two strings str1 and str2 and below operations that can performed on str1.
// Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  
// Operations : Insert, Remove, Replace
// All of the above operations are of equal cost.

int editDistanceRec(string s1, string s2, int m, int n) {
    // If first string is empty, then insert all characters of second string into first.
    if(m == 0) return n;
    // If second string is empty, then remove all characters of first string.
    if(n == 0) return m;
    if(s1[m - 1] == s2[n - 1]) return editDistanceRec(s1, s2, m - 1, n - 1);
    int opt1 = editDistanceRec(s1, s2, m, (n - 1)); // Insert
    int opt2 = editDistanceRec(s1, s2, (m - 1), n); // Remove
    int opt3 = editDistanceRec(s1, s2, (m - 1), (n - 1)); // Replace
    return (1 + min(opt1, min(opt2, opt3)));
}

int editDistanceTD(string s1, string s2, int m, int n, vii &dp) {
    if(m == 0) return n;
    if(n == 0) return m;
    if(dp[m - 1][n - 1] != -1) return dp[m - 1][n - 1];
    if(s1[m - 1] == s2[n - 1]) return editDistanceTD(s1, s2, (m - 1), (n - 1), dp);
    int opt1 = editDistanceTD(s1, s2, m, (n - 1), dp); // Insert
    int opt2 = editDistanceTD(s1, s2, (m - 1), n, dp); // Remove
    int opt3 = editDistanceTD(s1, s2, (m - 1), (n - 1), dp); // Replace
    return (dp[m - 1][n - 1] = 1 + min(opt1, min(opt2, opt3)));
}

int editDistanceBU(string s1, string s2, int m, int n) {
    vector<vector<int> > dp((m + 1), vector<int>((n + 1), 0));
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            // If first string is empty, only option is to insert
            // all characters of second string 
            if(i == 0) dp[i][j] = j;
            // If second string is empty, only option is to
            // remove all characters of second string
            else if(j == 0) dp[i][j] = i;
            // If last characters are same, ignore last characters
            else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert
                                   min(dp[i - 1][j], // Remove
                                   dp[i - 1][j - 1])); // Replace
            }
        }
    }
    return dp[m][n];
}

int main() {
    FIO;
    string s1 = "sunday";
    string s2 = "saturday";
    cout << editDistanceRec(s1, s2, s1.length(), s2.length()) << nl;
    vii dp(s1.length(), vi(s2.length(), -1));
    cout << editDistanceTD(s1, s2, s1.length(), s2.length(), dp) << nl;
    cout << editDistanceBU(s1, s2, s1.length(), s2.length());
    return 0;
}