class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        //initliaize the variable for count of 1
        unsigned int count = 0;
        
        //it will run the loop till pointer traverse the whole unsigned number 
        while(n>0){
            
            //it will increase the count when it finds the 1 in the number by doing logical AND Opeartion
            count +=n & 1;
            
            // it will perform the right shift into the unsigned int number
            n>>=1;
        }
        return count;
        
        
    }
};
