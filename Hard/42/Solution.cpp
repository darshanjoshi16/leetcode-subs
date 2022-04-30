class Solution {
public:
    int trap(vector<int>& height) { 
        int sum=0;
        //vector<int> water;
        vector<int> leftmax;
        vector<int> rightmax;
        //max left---case 1 = 0 1 1 2 2 2 2 3 3 2 2 2
        int left=height[0];
        for(int i=0;i<height.size();i++){
            left=max(left,height[i]);
            leftmax.push_back(left);
        }
        //max right---case 3 3 3 3 3 3 3 3 2 2 2 1 
        int right=height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            right=max(right,height[i]);
            rightmax.push_back(right);
        }
        
        reverse(rightmax.begin(), rightmax.end());
        
        for(int i=0;i<height.size();i++){
                        sum=sum+(min(rightmax[i], leftmax[i])-height[i]);
        }
        
        return sum;
    }
};
