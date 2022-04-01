class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int > ump;
        int i=0,j=0,ans = 0;
        while(j < s.size()){
            ump[s[j]]++;      //Storing the count of each character of the string
            if(ump[s[j]] > 1){       //To remove all the duplicates from the substring formed 
                while(ump[s[j]] > 1){
                    ump[s[i]]--;
                    if(ump[s[i]] == 0)
                        ump.erase(s[i]);
                    i++;
                }
            }
            else{    //If condition satisfies then calculate the maximum substring
                ans = max(ans,j-i+1);
            }
            j++;
        }
        return ans;    // Return max substring found.
    
    }
};
