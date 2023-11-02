//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int count1 = -1, count2 = -1;
        int mn = INT_MAX;
        
        for(int i=0; i<n; i++){
            if(a[i] == x){
                count1 = i;
                if(count2 != -1){
                    mn = min(mn, abs(count1 - count2));
                }
            }
            else if(a[i] == y){
                count2 = i;
                if(count1 != -1){
                    mn = min(mn, abs(count1 - count2));
                }
            }
        }
        if(count1 == -1 || count2 == -1){
            return -1;
        }
        return mn;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends
