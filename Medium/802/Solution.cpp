class Solution {
public:
    void detectCycle(int i,bool *isVis,bool *dfs,vector<vector<int>> &graph,const int &n){
        isVis[i] = dfs[i] = true;
        for(const int it:graph[i]){
            if(isVis[it] == 0) detectCycle(it,isVis,dfs,graph,n);
            if(dfs[it] == 1) return;
        }
        dfs[i] = false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        const int n = graph.size();
        bool *isVis = new bool[n]{false},*dfs = new bool[n]{false};
        for(int i = 0;i<n;i++)
            if(isVis[i] == 0) detectCycle(i,isVis,dfs,graph,n);
        for(int i = 0;i<n;i++) if(dfs[i] == 0) ans.emplace_back(i);
        return ans;
    }
};
