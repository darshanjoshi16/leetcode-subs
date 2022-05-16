class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>res;
        res.push_back(0);
        dfs(ans,graph,res,0);
        return ans;
    }
    void dfs(vector<vector<int>> &ans,vector<vector<int>>& graph,vector<int>&res,int i){
      
        if(i==graph.size()-1){
            ans.push_back(res);
           return;
       }
        for(auto j:graph[i]){
            res.push_back(j);
                dfs(ans,graph,res,j);
            res.pop_back();
        }
    };

};
