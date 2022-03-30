class Solution {
public:
bool canConstruct(string ransomNote, string magazine) {
//Initialize variables
unordered_map<char, int> magazineLetters;
int counter = 0;

	//Insert into map and incrementing the number of chars
    for (int i = 0; i < magazine.size(); i++){
        magazineLetters[magazine[i]]++;
    }
    
	//find char and see if enough chars are left / if enough, increment counter
    for (int j = 0; j < ransomNote.size();j++){
        if (magazineLetters.find(ransomNote[j]) != magazineLetters.end()){
            if(magazineLetters[ransomNote[j]] != 0){
                magazineLetters[ransomNote[j]]--;
                counter++;
            }    
        }
    }
    
	//if counter equals size, return true
    if (counter == ransomNote.size()){
        return true;
    }
    
	//else return false
    return false;
}
};
