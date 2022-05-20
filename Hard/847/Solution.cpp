class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        if(graph.size() == 1){
           return 0;
        }
        
        int n = graph.size();
        int ending_mask = (1<<n)-1;

        vector<vector<int>> seen(n ,vector<int>(ending_mask, 0));
        vector<pair<int,int>> q;

        for(int i = 0; i<n ; i++){
            q.push_back({i, 1<<i});
            seen[i][1<<i] = true;
        }
        
        int steps = 0;
        while(!q.empty()){
            vector<pair<int,int>> next_q;
            for(int i=0 ; i<q.size() ; i++){
                pair<int,int> curr_pair = q[i];
                int u = curr_pair.first;
                int mask = curr_pair.second;
                for(auto& v : graph[u]){
                    int next_mask = (mask|(1<<v)) ;
                    if(next_mask == ending_mask){
                        return 1+steps;
                    }
                    
                    if(!seen[v][next_mask]){
                        seen[v][next_mask] = true;
                        next_q.push_back({v,next_mask});
                    }
                }
            }
            steps++;
            q = next_q;
        }
        return -1;
    }
};
