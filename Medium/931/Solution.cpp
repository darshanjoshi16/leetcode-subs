class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int min_e = matrix[i + 1][j];
                if (j > 0)
                    min_e = min(min_e, matrix[i + 1][j - 1]);
                if (j < m - 1)
                    min_e = min(min_e, matrix[i + 1][j + 1]);
                matrix[i][j] += min_e;
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};
