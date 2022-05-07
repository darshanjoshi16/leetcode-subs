class solution {
public:
    int dp[1001][1001];
int f(int i,int j,string &str1,string &str2)
{
	if(i<0)return j+1;
	if(j<0)return i+1;
	if(dp[i][j]!=-1)return dp[i][j];
	if(str1[i]==str2[j])
	{
		return dp[i][j]= 0+f(i-1,j-1,str1,str2);
	}
	else
	{
		int a=1+f(i,j-1,str1,str2); // insertion
		int b=1+f(i-1,j,str1,str2); // deletion
		int c=1+f(i-1,j-1,str1,str2); // replace
		return dp[i][j]=min(a,min(b,c));
	}
}
    int minDistance(string word1, string word2) {
          int n=word1.length();
	      int m=word2.length();
	     memset(dp,-1,sizeof(dp));
	    return f(n-1,m-1,word1,word2); 
    }
};
// DP || Tabulation solution
class Solution {
public:
    int minDistance(string word1, string word2) {
          int n=word1.length();
	      int m=word2.length();
          int dp[n+1][m+1];
	      memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
	    
    }
};
