//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(int ind1, int ind2, string x, string y, int m, int n, vector<vector<int>> &dp)
    {
        if(ind1 >= m || ind2 >= n){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(x[ind1] == y[ind2]){
            return 1 + lcs(ind1+1, ind2+1, x, y, m, n, dp);
        }
        return dp[ind1][ind2] = max(lcs(ind1+1, ind2, x, y, m, n, dp), lcs(ind1, ind2+1, x, y, m, n, dp));
    }
    
    int lowestCommonSubsequence(string x, string y, int m, int n){
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        int lcsLen = lcs(0, 0, x, y, m, n, dp);
        return lcsLen;
    }
    
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        int len = lowestCommonSubsequence(x, y, m, n); 
        return ((m-len) + (n-len) + len);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
