class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        
        int change = x < 0 ? -1 : 1;
        x = abs(x);
        
        int reversed = x % 10;
        x /= 10;
        while (x != 0) {
            if (reversed > INT_MAX/10) {
                return 0;
            }
            
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        return change * reversed;
    }
};
