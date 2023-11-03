class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> op;
        stack<int> s;

        int targetIdx = 0;

        for(int i=1; i<=n; i++){
            if(targetIdx == target.size()){
                break;
            }

            if(target[targetIdx] == i){
                op.push_back("Push");
                targetIdx++;
            }
            else{
                op.push_back("Push");
                op.push_back("Pop");
            }
        }
        return op;
    }
};
