class Solution {
public:

int minMutation(string start, string end, vector<string>& bank) {

    set<string>s(bank.begin(),bank.end());
    if(s.size()==0)
        return -1;
    
    if(s.find(end)==s.end())
        return -1;
    
	// making a queue of strings 
    queue<string>q;
    q.push(start);
    
    int level{};
    
    while(!q.empty()){
        
        int sz = q.size();
            while(sz--){
                auto s1 = q.front();
                q.pop();
       
                if(s1==end) return level;
        
		        // Generating all combinations of the current string s1
				// with the given function getstring
                for(auto &newstrings : getstring(s1)){
                 
				 // checking in the gene bank as well
                    if(s.find(newstrings)!=s.end()){
                        q.push(newstrings);
                        s.erase(newstrings);
                    }
                }
        }
        level++;// increasing the level
    }
    
    return -1;
}

set<string> getstring(string &s1){
    //this function will generate every possible combinations of string s1
    set<string>st;
    string s2 ="ACGT";
    
    for(int i=0;i<s1.size();i++){
        char ch = s1[i];
        
        for(int j=0;j<4;j++){
          
                s1[i]=s2[j];
                st.insert(s1);
            
        }
        s1[i] = ch;
    }
    
    return st;
}
};
