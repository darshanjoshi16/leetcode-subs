class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> m;
        
        int l=0,r=0;
        
        int ans=0;
        
        int mx=INT_MIN;
        
        while(r<s.size()) {
            m[s[r]]++;

            mx = max(mx,m[s[r]]);
            
            if(((r-l)+1)-mx <= k) ans=max(ans,(r-l)+1);
            
            else{
                m[s[l]]--;
                l++;
            }
            
            r++;
        }
        return ans;
    }
};
