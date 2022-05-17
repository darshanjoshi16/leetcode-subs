class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto itr:adj[node]){
            if(!vis[itr]){
                dfs(itr,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1) return -1;
        vector<int>adj[n];
        for(vector<int> &items:connections){
             adj[items[0]].push_back(items[1]);
             adj[items[1]].push_back(items[0]);
        }
        
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans-1;
    }
};
