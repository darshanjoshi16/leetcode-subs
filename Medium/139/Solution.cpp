class Solution {
    int dp[301][301]{}; //0 not filled. 1 is false. 2 is true.
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &word: wordDict){
            //fill dp use word and s, as the base case.
            if(word.size() > s.size())  continue;
            for(int start = 0; start + word.size() <= s.size(); start++){
                int i = 0;
                for(; i < word.size() and word[i] == s[start + i]; i++);
                if(i == word.size()) dp[start][start + word.size()] = 2;
            }  
        }
        return recurse(s, 0, s.size()) == 1 ? false : true;
    }
    //[i,j). tell if it is breakable
    int recurse(const string &s, int i, int j) {
        if (dp[i][j] !=0) return dp[i][j];
        //test break point
        for(int b = i; b < j - 1; b++)
            if(recurse(s, i, b+1) == 2 and recurse(s, b+1, j) == 2)
                return dp[i][j] = 2;
        return dp[i][j] = 1;
    }
};
