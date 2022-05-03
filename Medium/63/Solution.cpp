class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int dp[101][101] = {0};
        if(og.size()==1&&og[0].size()==1&&og[og.size()-1][og[0].size()-1] ==0)
        {
            return 1;
        }
        if(og[0][0] ==1)
        {
            return 0;
        }
        for(int i=0;i<og.size();i++)
        {
            for(int j=0;j<og[0].size();j++)
            {
                if(og[i][j] == 1)
                   dp[i][j] = -1;
            }
        }
        bool t1=false,t2=false;
        for(int i=1;i<og[0].size();i++)
        {
            if(dp[0][i] == -1)
            {
                t1=true;
            }
            if(t1 == true&&dp[0][i] != -1)
            {
                dp[0][i] = 0;
            }
            if(t1 != true)
            {
                dp[0][i] = 1;
            }
        }
        for(int i=1;i<og.size();i++)
        {
            if(dp[i][0] == -1)
            {
                t2=true;
            }
            if(t2 == true&&dp[i][0] != -1)
            {
                dp[i][0] = 0;
            }
            if(t2!=true)
            {
                dp[i][0] = 1;
            }
        }
        for(int i=1;i<og.size();i++)
        {
            for(int j=1;j<og[0].size();j++)
            {
                if(dp[i][j]!=-1)
                {
                    if(dp[i-1][j]>=0)
                    {
                        dp[i][j]+=dp[i-1][j];
                    }
                    if(dp[i][j-1]>=0)
                    {
                        dp[i][j]+=dp[i][j-1];
                    }
                }
                
            }
        }
        if(dp[og.size()-1][og[0].size()-1] ==-1)
        {
            return 0;
        }
            return dp[og.size()-1][og[0].size()-1];
    }
};
