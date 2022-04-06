class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void combinations(int n,int k,int st=1, int idx=0)
    {
        if(idx==k) {
            res.push_back(temp);
            return;
        }
        for(int i=st;i<=n;i++)
        {
            temp.push_back(i);
            combinations(n,k,i+1,idx+1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        combinations(n,k);
        return res;
    }
};
