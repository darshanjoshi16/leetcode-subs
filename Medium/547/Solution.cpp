class Solution {
public:
    int find_par(int node, int par[]) {
        if(node == par[node]) return node;
        return par[node] = find_par(par[node], par);
    }
    void add(int u, int v, int par[], int ran[]) {
        u = find_par(u, par);
        v = find_par(v, par);
        if(ran[u] < ran[v]) {
            par[u] = v;
        } else if(ran[u] > ran[v]) {
            par[v] = u;
        } else {
            par[v] = u;
            ran[u]++;
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        int par[n], ran[n];
        int count = 0;
        for(int i=0; i<n; i++) {par[i] = i, ran[i] = 0;}
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j && grid[i][j] == 1) continue;
                if(grid[i][j] == 1 && find_par(i, par) != find_par(j, par)) {
                    add(i, j, par, ran);
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(par[i] == i) count++;
        }
        return count;
    }
};
