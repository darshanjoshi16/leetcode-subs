//total steps = m+n-2, down = m-1 steps, right = n-1 steps => Ans = (m+n-2)!/(m-1)!(n-1)!
class Solution {
public:

    int uniquePaths(int m, int n) {
        long ans = 1;
        int max_m_n = max(m-1,n-1); 
        int j = 1;
        for(int i = max_m_n+1; i <= m+n-2; i++){
            ans = (ans*i)/j;
            j++;
        }
        return ans;
    }
};

//(m+n-2)!/(m-1)!(n-1)! = [(max(m-1, n-1)+1) * (max(m-1, n-1)+2) * ... * (m+n-2)] / min(m-1, n-1)!
