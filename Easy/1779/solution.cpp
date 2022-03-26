class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        
        //initiliazing the smallest distance and index variable
        int small = INT_MAX;
        int index = -1;
        
        //it will traverse the loop for size of vector of points
        for(int i = 0 ; i < points.size(); i++)
        {
            //it will compare if the x is matching with first coordinates with points vector's element
            //or y is matching with second coordinate of points vector's element
            if(points[i][0]==x || points[i][1]==y)
            {
                //this formula will calculate the manhatten distance 
                int distance = (abs(x-points[i][0])+abs(y-points[i][1]));
                
                //if the distance is smaller than predefined small, it will update the value of small and it will update the index also
                if(distance < small)
                {
                    small = distance;
                    index = i;
                    
                    
                }
            }
        }
        
        // it will return the index which are the valid points
        return index;
        
    }
};
