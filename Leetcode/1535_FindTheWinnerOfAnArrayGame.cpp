class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k == 1){
            return max(arr[0], arr[1]);
        }
        if(k >= arr.size()){
            return *max_element(arr.begin(), arr.end());
        }

        int curr_win = arr[0];
        int consecutive_wins = 0;

        for(int i=1; i<arr.size(); ++i){
            if(curr_win > arr[i]){
                consecutive_wins++;
            }
            else{
                curr_win = arr[i];
                consecutive_wins = 1;
            }

            if(consecutive_wins == k){
                return curr_win;
            }
        }
        return curr_win;
    }
};
