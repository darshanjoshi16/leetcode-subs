class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //created a set  of slopes which will be giving the slope of given points
        set<int> slopes{};
        //initialize the size variable
        int len = coordinates.size();
        //sort the vector
        sort(coordinates.begin(), coordinates.end());
        
        //traversing the vector
        for(int i{len - 1}; i > 0; i--)
        {
            //logic for the slope checking
            if(i - 1 >= 0){
                int rise = (coordinates[i][1] - coordinates[i - 1][1]);
                int run = (coordinates[i][0] - coordinates[i - 1][0]);
                int slope{};
                
                if(!run)
                    slope = INT_MIN;
                else slope =  rise / run;
                
                slopes.insert(slope);
                
                //if there are more values of slope than 1 then it will prove that the points are not in same line
                if(slopes.size() > 1)
                    return false;
            }
        }
        
        return slopes.size() == 1;
    }
};
