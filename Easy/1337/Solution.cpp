class Solution {
public:
    int searchOnes(vector<vector<int>>& mat, int t){
        int i =0, j = mat[t].size()-1;
        while(i<j){
            int mid = i+(j-i)/2;
            if(mat[t][mid]){
                i = mid+1;
            }else{
                j = mid;
            }
        }
        return mat[t][i] == 1 ? i+1:i; // handling condition when all the value are zero.
    }
    // Go through each row, find the number of 1's using binarySearch.
    // push the pair count,row in priority queue.
    // The number of data required pushed into a vector after pop and then return that value
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue <pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;  //to create min heap
        int m = mat.size(), n = mat[0].size();
        for(int i =0;i<m;i++){
            q.push({searchOnes(mat, i), i});
        }
        vector<int> ans;
        int p=0;
        while(!q.empty() && p<k){
            ans.push_back(q.top().second);
            q.pop();
            p++;
        }
        return ans;
    }
};
