class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<list<int>> adj_list(n);
        
        for (int i = 0; i < manager.size(); ++i) {
            // Add an edge from a manager to their subordinate.
            // Ignore adding an edge for headID, who does not have a manager.
            if (i != headID) 
                adj_list[manager[i]].push_back(i);
        }
        
        int time = 0;
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        q.emplace(headID, 0);
        visited.insert(headID);
        
        while (!q.empty()) {
            int id = q.front().first;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            
            for (auto it : adj_list[id]) {
                if (!visited.count(it)) {
                    q.emplace(it, t + informTime[id]);
                }
            }
        }
        
        return time;
    }
};
