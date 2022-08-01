class Solution {
public:
    //to return the reversed string
    string reverse(string s){
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            ans+=s[i];
        }
        return ans;
    }
    //to check if the word has same letters
    bool same_letters(string s){
        if(s[0]==s[1])
            return true;
        else
            return false;
    }
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto i:words){
            mp[i]++;
        }
        int ans=0;
        bool mid=false;  //to check if a word has been selected to be inserted in the middle
        for(auto i:words){
            string rev=reverse(i);
            bool isSame=same_letters(i);
            if(isSame){
                //if count is odd the select all the words leaving one
                if(mp[i]%2!=0){
                    ans+=(2*(mp[i]-1));
                    mp[i]=1;
                    if(mid==false){   //if no word is selected for middle, select this word and erase it from map
                        mid=true;
                        ans+=2;
                        mp.erase(i);
                    }
                }
                //if count is even select all the words
                else{
                    ans+=(2*(mp[i]));
                    mp.erase(i);
                }
            }
            //if word does not have same letters, and the word and its reverse exists in the map, add the word and its reverse and reduce their count
            //if count reaches 0 then erase from the map to prevent further addition
            else if(mp.find(i)!=mp.end() && mp.find(rev)!=mp.end()){
                ans+=4;
                mp[i]--;
                if(mp[i]==0)
                    mp.erase(i);
                mp[rev]--;
                if(mp[rev]==0)
                    mp.erase(rev);
            }
        }
        return ans;
    }
};
