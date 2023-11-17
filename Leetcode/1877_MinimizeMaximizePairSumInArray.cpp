//Brute - Sorting
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx = 0;
        int sz = nums.size();

        for(int i=0; i<sz/2; i++){
            mx = max(mx, nums[i] + nums[sz-1-i]);
        }
        return mx;
    }
};

//Optimized - Two Pointers
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int freq[100001] = {0};

        for(int x : nums){
            freq[x]++;
        }
        int left = 0, right = 100000, mx = 0, pair=1, r=0, l=0;

        while(left < right){
            while(l < pair){
                l += freq[left++];
            }

            while(r < pair){
                r += freq[right--];
            }

            mx = max(mx, left+right);
            pair++;
        }
        return mx;
    }
};
