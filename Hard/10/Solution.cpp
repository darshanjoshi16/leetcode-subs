class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		bool dp[n+1][m+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(i==0 && j==0)dp[i][j]=true;
				else if(i==0)dp[i][j]=false;
				else if(j==0){
					if(p[i-1]=='*')dp[i][j]=dp[i-2][j];
					else dp[i][j]=false;
				}else {
					if(p[i-1]=='*'){
						dp[i][j]=dp[i-2][j];
						if(s[j-1]==p[i-2] || p[i-2]=='.') dp[i][j] |= dp[i][j-1];
					}else if(s[j-1]==p[i-1] || p[i-1]=='.')dp[i][j]=dp[i-1][j-1];
					else dp[i][j]=false;
				}
			}
		}
		return dp[n][m];
	}
};
