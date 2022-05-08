class Solution {
public:
int numSquares(int n) {
vector <int> dp(n+1);
return help(n,dp);
}

int help(int n,vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;
    
    
for(int i=2;i<=n;i++){
    int ans = INT_MAX;
    for(int j=1;j*j <= i;j++){
        int count = 1+dp[(i-(j*j))];
        ans = min(ans,count);
    }
    dp[i] = ans;
}
     return dp[n];
}
};
