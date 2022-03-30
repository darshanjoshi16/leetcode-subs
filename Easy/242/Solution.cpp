class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        //if size of strings are different return false//
        if(s.size()!=t.size())
            return false; 

        // after sorting both the strings will become same if they are anagrams otherwise not//
        sort(s.begin(),s.end()); 
        sort(t.begin(),t.end());

        if(s==t)
            return true;

        else 
            return false;
    }
        
};
