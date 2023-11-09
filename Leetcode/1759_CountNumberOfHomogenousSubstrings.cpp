class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9+7;
        int ans = 0;
        int curr = 1;
        ans += 1;

        for(int i=1; i<s.size(); i++){
            if(s[i] != s[i-1]){
                curr = 1;
                ans += 1;
            }
            else{
                curr++;
                ans += curr;
                ans = ans % mod;
            }
        }
        return ans;
    }
};
