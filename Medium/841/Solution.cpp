 class Solution {
    void DFS(vector<vector<int>>& rooms, int src, vector<bool>& visited) {
        visited[src] = true;
        for(int i: rooms[src]) {
            if(!visited[i])
                DFS(rooms, i, visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<bool> visited(N, false);
        DFS(rooms, 0, visited);
        for(bool b: visited) if(!b) return false;
        return true;
    }
};
