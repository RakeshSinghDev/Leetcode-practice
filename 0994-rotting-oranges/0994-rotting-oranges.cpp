
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        
        while (!q.empty() && fresh > 0) {

            int size = q.size();

            
            for (int i = 0; i < size; i++) {

                auto [row, col] = q.front();
                q.pop();

               
                for (int d = 0; d < 4; d++) {

                    int nr = row + dr[d];
                    int nc = col + dc[d];

                    
                    if (nr >= 0 && nr < rows &&
                        nc >= 0 && nc < cols &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        
                        fresh--;

                      
                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }

      
        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};
