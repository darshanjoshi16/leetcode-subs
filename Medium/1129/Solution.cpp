class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
        vector<vector<int>> r(n);
        vector<vector<int>> b(n);
        for(auto v: re) r[v[0]].push_back(v[1]);
        for(auto v: be) b[v[0]].push_back(v[1]);
        vector<int> ans(n, -1);
        vector<int> ansb(n, -1);
        ans[0] = 0;
        ansb[0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0}); q.push({0, 1});
        set<pair<int, int>> sr;
        set<pair<int, int>> sb;
        while(!q.empty()){
            auto temp = q.front();
            // cout<<temp.first<<" "<<(temp.second==0?'r':'b')<<endl;
            q.pop();
            if(temp.second==0){
                for(auto i: r[temp.first]){
                    if(sr.find({temp.first, i}) == sr.end()){
                        q.push({i, 1});
                        sr.insert({temp.first, i});
                    }
                    if(ans[i]==-1 || ans[i]>ansb[temp.first]+1){
                        ans[i] = ansb[temp.first]+1;
                    }
                }
            }
            else{
                for(auto i: b[temp.first]){
                    if(sb.find({temp.first, i}) == sb.end()){
                        q.push({i, 0});
                        sb.insert({temp.first, i});
                    }
                    if(ansb[i]==-1 || ansb[i]>ans[temp.first]+1){
                        ansb[i] = ans[temp.first]+1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            int temp = min(ans[i] == -1?INT_MAX:ans[i], ansb[i] == -1?INT_MAX:ansb[i]);
            ans[i] = temp==INT_MAX?-1:temp; 
        }
        return ans;
    }
};
