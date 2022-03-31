class Solution {
public:
    string reverseWords(string s) {
        
        //created the vector of strings and stream object with variable of words and answer
        vector<string>v;
        stringstream str(s);
        string words,ans="";
        
        //add words into vector
        while(str>>words){
            v.push_back(words);
        }
        
        //traversing the loop and reverse the vectored words
        for(int i=0;i<v.size();i++){
            string tmp=v[i];
            reverse(tmp.begin(),tmp.end());
            ans+=tmp;
            ans+=" ";
        }
        
        //return the answer
        return ans.substr(0,ans.length()-1);
        
    }
};
