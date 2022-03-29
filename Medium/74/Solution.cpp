class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //row and col variable gives the count of rows and column respectively
        int row=matrix.size();
        int col=matrix[0].size();
        
        //initial checking for target value
        if(row==1 && col==1)
        {
            if(matrix[0][0]!=target)
                return false;
        }
        
        //creating variable for loop traversing
        int i;
        
        //using the binary searching technique partiton, if target is found then return true
        //otherwise return the subpartitoned array from new index
        for(i=0; i<row; i++){
            if(matrix[i][col-1] == target)
                return true;
            else if(matrix[i][col-1] < target){
                continue;
            }
            
            //subpartitoning of the vector using binary search technique
            else{
                int low=0;
                int high=col-1;

                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(matrix[i][mid]==target)
                        return true;
                    else if(matrix[i][mid]>target)
                        high=mid-1;
                    else
                        low=mid+1;
                }
            }
        }             
        return false;
    }
};
