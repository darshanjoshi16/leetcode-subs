class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        
        //initial the 2 pointer start and end
        int start = 0;
        int end = s.size() - 1;

        //swapping the indexes which will return the array of reversed characters
        while (start < end)

        {
    
            swap(s[start++], s[end--]);

        }
    
        
    }
};
