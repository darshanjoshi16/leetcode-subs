class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        //creating the base case of numerical rows is 1
        if(numRows==1)
            return {{1}};
        
        //creating the base case for numerical rows is 2
        if(numRows==2)
            return {{1},{1,1}};
        
        //for further logic
        //created the resultant 2 dimensional vector named result
        vector<vector<int>> result;
        
        //base case of 1 and 2 rows are bydefault entered
        result.push_back({1});
        result.push_back({1,1});
        
        //created a loop which will run till size-2 because 2 tuples are already entered by us in form of 0 and 1 row value
        while(numRows-2){
            
            //remaining portion size
            int n=result.size();
            //temporary vector creation and logic for adding the new element in vector
            vector<int> t(n+1);
            t[0]=1;t[n]=1;
            for(int i=1;i<n;i++){
                t[i]=result[n-1][i-1]+result[n-1][i];
            }
            result.push_back(t);
            numRows--;
        }
        return result;
    }
};
