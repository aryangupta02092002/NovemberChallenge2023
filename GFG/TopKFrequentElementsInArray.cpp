//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        vector<int> ans;
        unordered_map<int, int> u;
        vector<pair<int, int>> tmp;
        
        for(int i=0; i<nums.size(); i++){
            u[nums[i]]++;
        }
        
        for(auto it=u.begin(); it!=u.end(); it++){
            tmp.push_back({it->first, it->second});
        }
        
        sort(tmp.begin(), tmp.end(), cmp);
        
        for(int i=0; i<k; i++){
            ans.push_back(tmp[tmp.size()-1].first);
            tmp.pop_back();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
