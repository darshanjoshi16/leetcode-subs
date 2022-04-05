/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        //starting the 2 pointer approach
        int left=0;
        int right=n;
        
        //iterate the loop till we will complete the binary search approach
        while(left<=right)
        {
            //new middle key initialize
            int mid=left+(right-left)/2;
            
            //calling the predefined API
            if(guess(mid)==0){
                return mid;
            }
            else if(guess(mid)==1){
                left=mid+1;
            }
            else if(guess(mid)==-1){
                right=mid-1;
            }
        }
        return 0;        
        
    }
};
