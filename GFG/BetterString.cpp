//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctSubsequences(const string& str) {
        const int MOD = 1000000007;
        int n = str.length();
    
        int lastOccurrence[256];
        memset(lastOccurrence, -1, sizeof(lastOccurrence));
    
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
    
        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;
    
            if (lastOccurrence[str[i - 1]] != -1) {
                dp[i] = (dp[i] - dp[lastOccurrence[str[i - 1]] - 1] + MOD) % MOD;
            }
    
            lastOccurrence[str[i - 1]] = i;
        }
    
        return dp[n];
    }

    string betterString(const string& str1, const string& str2) {
        int count1 = countDistinctSubsequences(str1);
        int count2 = countDistinctSubsequences(str2);
    
        return (count1 >= count2) ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
