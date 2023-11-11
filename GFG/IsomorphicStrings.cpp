//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.size() != str2.size()){
            return 0;
        }
        
        unordered_map<char, char> u;
        unordered_map<char, char> mp;
        int i=0;
        
        while(str1[i] != '\0'){
            if(!u[str1[i]]){
                u[str1[i]] = str2[i];
            }
            else{
                if(u[str1[i]] != str2[i]){
                    return 0;
                }
            }
            
            if(!mp[str2[i]]){
                mp[str2[i]] = str1[i];
            }
            else{
                if(mp[str2[i]] != str1[i]){
                    return 0;
                }
            }
            i++;
        }
        return 1;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
