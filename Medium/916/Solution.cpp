class Solution {
public:
    bool check( string word, vector<int> freq){  // check if all chars in freq are present in word
        
        for(char i : word){                    
            if(freq[i-'a']!=0)freq[i-'a']--;
        }
        
        for(int i =0;i<26;i++){
            if(freq[i]>0)return false;
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      
        vector<int> freq(26,0);   // constructing frequency Array (freq of each char is the max multiplicity of that char in any word )
        for(string i : words2){
            vector<int> temp(26,0);
            for(char j : i){
                temp[j-'a']++;
            }
          for(int k =0;k<26;k++)freq[k] = max(freq[k],temp[k]);
        }                                 //         ****************
        
        vector<string> ans;
        for(string i : words1){                  
            if(check(i,freq))ans.push_back(i);
        }
        
        return ans;
        
    }
};
