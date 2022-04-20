

const int Limit = 100000;

class Solution {
public:
    vector<int> dp, values; unordered_map<int,int> Memo;
    
    int helper(int i){
        // base-case:
        if (i == 0) return values[0];
        if (i == 1) return max(values[0],values[1]);
        if (Memo.find(i) != Memo.end()) return Memo[i];
        
        // recurrence-relation
        return Memo[i] = max( helper(i-1), helper(i-2) + values[i] );
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        // initialization: 
        int SearchLimit = 0; 
        dp.resize(Limit,0); values.resize(Limit,0);
        
        // count the frequencies, and aggregate the points
        unordered_map<int,int> Freq; for (auto i:nums) Freq[i]++;
        for (auto it=Freq.begin(); it!=Freq.end(); it++){
            values[it->first] = it->first * it->second;
            SearchLimit = max(SearchLimit, it->first);
        }
        
        // top-down DP
        return helper(SearchLimit);
    }
};
