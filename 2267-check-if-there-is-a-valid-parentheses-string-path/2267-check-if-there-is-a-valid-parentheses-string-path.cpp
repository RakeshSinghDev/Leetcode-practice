class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        if (len % 2 == 1)
            return false;

        
        if (grid[0][0] == ')')
            return false;

        
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(len + 1, false)
            )
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                
                if (i == 0 && j == 0)
                    continue;

                for (int bal = 0; bal <= len; bal++) {

                    int newBal;

                    if (grid[i][j] == '(')
                        newBal = bal + 1;
                    else
                        newBal = bal - 1;

                    if (newBal < 0)
                        continue;

                    bool possible = false;

                    
                    if (i > 0 && dp[i - 1][j][bal])
                        possible = true;

                   
                    if (j > 0 && dp[i][j - 1][bal])
                        possible = true;

                    if (possible)
                        dp[i][j][newBal] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};