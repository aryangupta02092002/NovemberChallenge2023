//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int sz = S.size();
        string D = "1", ans = "";
        int count = 1;
        
        for(int i=0; i<sz; i++){
            if(S[i] == 'D'){
                count++;
                D = to_string(count) + D;
            }
            else{
                ans += D;
                count++;
                D = to_string(count);
            }
        }
        ans += D;
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
