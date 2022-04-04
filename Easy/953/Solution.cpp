class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        std::vector<int> orders(26, -1);
        for(auto i = 0; i!= order.size(); ++i) {
            orders[order[i]-'a'] = i;
        }
      
        auto i = 1;
        std::transform(words[i-1].begin(), words[i-1].end(), words[i-1].begin(), [&](char c) -> char { return 'a' + orders[c-'a']; });
        for(; i != words.size(); ++i) {    
            std::transform(words[i  ].begin(), words[i].end(), words[i].begin(), [&](char c) -> char { return 'a' + orders[c-'a']; });
            if(words[i-1].compare(words[i]) > 0) {
                return false;
            }
        }
        
        return true;
    }
};
