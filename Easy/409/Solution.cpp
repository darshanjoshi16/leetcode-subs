class Solution {
public:
    int longestPalindrome(string s) {
        // unordered_map<char, bool> isUnpaired;

        bitset<26> lowerPairs;
        bitset<26> upperPairs;
        
        int length = 0;
        for (char c : s) {
            if (islower(c)) {
                if (lowerPairs[c - 'a'])
                    length += 2;
                lowerPairs[c - 'a'] = !lowerPairs[c - 'a'];
            }
            else {
                if (upperPairs[c - 'A'])
                    length += 2;
                upperPairs[c - 'A'] = !upperPairs[c - 'A'];
            }
        }
        
        // for (auto it : isUnpaired) {
        //     if (it.second) {
        //         length++;
        //         break;
        //     }
        // }
        
        return length + (lowerPairs.count() + upperPairs.count() > 0 ? 1 : 0);
    }
};
