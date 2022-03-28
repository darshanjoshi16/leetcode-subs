class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        //initializing the rows and columns variables of matrix
        int row = mat.size();
        int col = mat[0].size();
        
        //creating the resulatant matrix
        vector<vector<int>> result;
        
        //here if row * col cant be matched with r * c then it will not change the dimensions
        if(row * col != r * c) return mat;
        
        //creating result pointer variable which is  size of row * col
        int *res = new int[row*col];
        int count = 0;
        
        //total count of elements is inserted into res 
        for(int rows=0;rows<row;rows++){
            for(int cols=0;cols<col;cols++){
                res[count] = mat[rows][cols];
                count++;
            }
        }
        count=0;
        
        //the temporary data is maintained and it is pushedback into resultant vector
        for(int rows=0;rows<r;rows++){
            vector<int> tmp;
            for(int cols=0;cols<c;cols++){
                tmp.push_back(res[count]);
                    count++;
            }
            result.push_back(tmp);
        }
        return result;
    }
};
