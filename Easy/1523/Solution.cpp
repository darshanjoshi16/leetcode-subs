class Solution {
public:
    int countOdds(int low, int high) {
    
        int output = 0; //initialize the variable for count of odd numbers
        
        //if the lower range is odd then it will increase low and output variables
        if (low%2 != 0) {low += 1; output += 1;}
        
        //if the higher range is odd then it will decrease high and increase the ouput variable
        if (high%2 != 0) {high -= 1; output += 1;}
        
        //it will return of count odd numbers
        return output + (high-low)/2;
        
    }
};
