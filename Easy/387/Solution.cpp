class Solution {
public:
    int firstUniqChar(string s) {
        
        //creating the unordered map of integer type
        unordered_map<char,int> mp;
        
        //adding the sepearte character of strings into map 
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
        //checking the condition of mapping equal of 1
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        
        return -1;

        
        
    }
};
