class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.length();
         // if there is no string the return empty string
         if(n==0)
             return s;
         bool dp[n][n];
        // declaring boolean array to be false
         memset(dp, 0, sizeof(dp));
        // declaring all the substirng with single letter be true because they all are palindromic;
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        // this will store longest palindromic substring
         string ans = "";
        // if no palindromic substring found then the a single letter will always be the answer
        
         ans += s[0];
        
        // now iteratin to the boolean matrix where the 
        //row ans columns the start and end of the substring row == start and column == end
        
         for(int i = n-1; i >= 0; i--) {
             for(int j = i+1; j < n; j++) {
                 // if the start and end are equal then look for next conditions
                 if(s[i] == s[j]) {
                     // whether the substring is of length 2 or the substring inside the extremist is palindromic or not if yes then the whole current substring is pallindromic
                        if(j - i == 1 || dp[i+1][j-1]) {
                            dp[i][j] = true;
                            
                            // if the current substring size if greater then current then the previous ans stored then update the answer
                            if(ans.size() < j-i+1) {
                                ans = s.substr(i, j-i+1);
                            }
                        }
                 }
             }
         }
        return ans;
    }
};
