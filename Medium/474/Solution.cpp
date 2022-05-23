#define ll long long
#define vb vector<bool>
#define vi vector<int>
#define vl vector<long long>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define f(i,s,e) for(int i = s; i < e; i++)
#define b(i,s,e) for(int i = s; i >= e; i--)

class Solution {
public:
    int dp[101][101][601];

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vvi cnts(sz,vi(2,0));
        f(i,0,sz) {
            for(char c:strs[i]) {
                if(c == '0') cnts[i][0]++;
                else cnts[i][1]++;
            }
        }

        f(i,0,m+1) {
            f(j,0,n+1) {
                f(k,0,sz+1) {
                    if(k == 0 or (i == 0 and k == 0)) dp[i][j][k] = 0;
                    else {
                        dp[i][j][k] = dp[i][j][k-1];
                        if(i >= cnts[k-1][0] and j >= cnts[k-1][1]) 
                            dp[i][j][k] = max(dp[i][j][k],1+dp[i-cnts[k-1][0]][j-cnts[k-1][1]][k-1]);
                    }
                }
            }
        }

        return dp[m][n][sz];
    }
};
