class Solution {
public:
    void dfs(int src,vector<int>adjIn[],vector<int>adjOut[],vector<int>&vis,int &res)
    {
        vis[src]=1;
        for(int i=0;i<adjIn[src].size();i++)
        {
            if(!vis[adjIn[src][i]])
                dfs(adjIn[src][i],adjIn,adjOut,vis,res);
        }
        
        for(int i=0;i<adjOut[src].size();i++)
        
            if(!vis[adjOut[src][i]])
            {
                res++;
                dfs(adjOut[src][i],adjIn,adjOut,vis,res);
            }
            
        }
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<int>adjIn[n];
        vector<int>adjOut[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adjOut[u].push_back(v);
            adjIn[v].push_back(u);
        }
        int res=0;
        vector<int>vis(n,0);
        dfs(0,adjIn,adjOut,vis,res);
        return res;
    }
};
