class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int sz = dist.size();
        vector<double> time(sz);

        for(int i=0; i<sz; i++){
            time[i] = ceil(dist[i]/(double)speed[i]);
        }

        sort(time.begin(), time.end());

        for(int i=0; i<sz; i++){
            if(time[i] <= i){
                return i;
            }
        }

        return sz;
    }
};
