class Solution {
public:
    int maxArea(vector<int>& height) {
        //we are solving the problem using 2 pointers approach
        
        //initializing the pointers at start and end index for traversing the vector
        int left = 0;
        int right = height.size() - 1;
        
        //initializing the maximum area covered by the lines
        int maxi = 0;
        
        //it will run the loop till left pointer doesn't cross right
        while(left < right)
        {
            //determining the current width
            int w = right - left;
            
            //determining the current height
            int h = min(height[left], height[right]);
            
            //determining the current area
            int area = h * w;
            
            //it will determine the current maximum with instance of maxi and area
            maxi = max(maxi, area);
            
            //for moving the pointers
            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else {
                left++;
                right--;
            }
        }
        return maxi;
    }
};
