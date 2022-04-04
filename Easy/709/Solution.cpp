class Solution {
public:
    string toLowerCase(string s) 
    {
        for (char& c : s)
        {
            if (std::isalpha(c))
                c |= 32;
        }
        
        return s;
    }
};
