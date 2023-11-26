//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> plus(vector<int> &ans, int &n, int a){
        if(n == a){
            ans.push_back(n);
            return ans;
        }
        ans.push_back(n);
        n += 5;
        return plus(ans, n, a);
    }
    vector<int> minus(vector<int> &ans, int &n, int a){
        if(n <= 0){
            return plus(ans, n, a);
        }
        ans.push_back(n);
        n -= 5;
        return minus(ans, n, a);
    }
    vector<int> pattern(int N){
        // code here
        vector<int> ans;
        
        int a = N;
        return minus(ans, N, a);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
