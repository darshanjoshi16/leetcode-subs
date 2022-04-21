class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        // We are tracking the interval of where
        // we are, the result is the number of jumps
        // and we need to track where we can reach
        // from wherever we are at that moment.
        pair<int, int> interval {0, 0};
        int result = 0, can_reach;
        
        while(true)
        {
            can_reach = -1;
            result++;
            
            // Loop from the start of the interval(index in the
            // array where we are), to the maximum we can reach
            // (the value in that spot in the array).
            for(int i = interval.first; i<= interval.second; i++)
                can_reach = max(can_reach, i + nums[i]);
            
            // If we ever see that we land on the goal or can land
            // beyond it, just return the number of jumps.
            if(can_reach >= nums.size() - 1)
                return result;
            
            // Reinitialize the interval.
            interval = {interval.second + 1, can_reach};
        }
    }
};
