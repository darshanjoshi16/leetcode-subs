class Solution {
public:
    bool dfs(vector<int>& arr, vector<bool>& visited, int current){
        if(!visited[current]){
            visited[current] = true;
            if(arr[current] == 0){
                return true;
            }
            
            if(current + arr[current] < arr.size()){
                if(dfs(arr, visited, current + arr[current])){
                    return true;
                }
            }
            if(current - arr[current] >= 0){
                if(dfs(arr, visited, current - arr[current])){
                    return true;
                }
            }
            return false;
        }
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        vector<bool> visited(len);
        return dfs(arr, visited, start);
    }
};
