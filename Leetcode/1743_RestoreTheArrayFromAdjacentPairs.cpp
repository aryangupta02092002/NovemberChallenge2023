//Recursive : DFS | Hashmap
class Solution {
public:
    void dfs(vector<int> &ans, map<int, vector<int>> &g, int root, int prev){
        ans.push_back(root);
        for(int it : g[root]){
            if(it != prev){
                dfs(ans, g, it, root);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        map<int, vector<int>> g;
        for(auto it : adjacentPairs){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }

        int root = 0;
        for(auto it : g){
            if(it.second.size() == 1){
                root = it.first;
                break;
            }
        }
        dfs(ans, g, root, INT_MAX);
        return ans;
    }
};


//Iterative
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> pairs;
        for(const vector<int> &val : adjacentPairs){
            pairs[val[0]].push_back(val[1]);
            pairs[val[1]].push_back(val[0]);
        }

        vector<int> ans;
        int start = INT_MIN;

        for(auto &e: pairs){
            if(e.second.size() == 1){
                start = e.first;
                break;
            }
        }

        int left = INT_MIN;
        ans.push_back(start);

        for(int i=1; i<adjacentPairs.size()+1; i++){
            vector<int> &val = pairs[start];
            int newVal = (val[0] == left) ? val[1] : val[0];
            ans.push_back(newVal);
            left = start;
            start = newVal;
        }
        return ans;
    }
};
