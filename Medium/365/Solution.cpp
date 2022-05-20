class Solution {
public:
    bool canMeasureWater(int j1c, int j2c, int tc) {
        unordered_set<int> st;
        // This unordered_set works as visited array to mark all the caps that are visited
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            
            
            // Limits are: 1) Both the jugs are empty, 2) Both the jugs are full
            if (f >= 0 && f <= j1c + j2c)
            {
                vector<int> addCap = {j1c, j2c, -j1c, -j2c};
                for (int i = 0; i < 4; i++)
                {
                    int nxtCap = f + addCap[i];
                    if (nxtCap == tc)
                        return true;
                    else
                    {
                        if (st.find(nxtCap) == st.end())
                        {
                            st.insert(nxtCap);
                            q.push(nxtCap);
                        }
                        else
                            continue;
                    }
                }
            }
        }
        
        return false;
    }
};
