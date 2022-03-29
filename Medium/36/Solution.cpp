class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //created a valid board method
        return isValid(board);
    }
    
    bool isValid(vector<vector<char>>& board)
  {
    //initialize the vectors which will contain the row,column and subject
    vector<int> row(9);
    vector<int> col(9);
    vector<int> subj(9);

    //m and n variable determines the size of the board row and column wise
    int m = board.size();
    int n = board[0].size();
    
    //running the loop for traversing the board
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
          //checking the input and performing the operation according to it
        if (board[i][j] == '.') continue;
        int c = (1 << (board[i][j] - '0'));
        if (row[i] & c) return false;
        if (col[j] & c) return false;

          //logic for valid sudoku
        int subIdx = getSubIndex(i, j);
        if (subj[subIdx] & c) return false;

        row[i] |= c;
        col[j] |= c;
        subj[subIdx] |= c;
      }
    }

    return true;
  }

  int getSubIndex(int a, int b)
  {
    return ((a / 3) * 3) + (b / 3);  
  }
};
