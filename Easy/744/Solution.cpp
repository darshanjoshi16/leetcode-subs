class Solution {
public:
    char nextGreatestLetter(vector<char>&A, char t) {
        int n = A.size();
        int l = 0;
        int r = n;
        while(l < n and l < r)
        {
            int mid = (l + r) / 2;
            if(A[mid] <= t)
                l = mid + 1;
            else
                r = mid; 
        }
        if(r == n)
            return A[0];
        return A[r];
            
        
    }
};
