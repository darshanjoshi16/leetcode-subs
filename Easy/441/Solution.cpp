class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 2)
            return 1;
        
        int level = 0;
        for(int i=1; i<=n; i++)
        {
            n -= i;
            level++;
            if(n<=0)
                return level;
        }
        
        return level;
    }
};
