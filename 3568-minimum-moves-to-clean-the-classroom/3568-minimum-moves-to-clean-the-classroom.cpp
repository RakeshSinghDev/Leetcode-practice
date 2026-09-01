class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int, int>> litter;

        // Find starting position and all litter positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // Give every litter cell a bit number
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            litterId[litter[i].first][litter[i].second] = i;
        }

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        // State = {row, col, remaining energy, collected litter mask}
        struct State {
            int r;
            int c;
            int e;
            int mask;
            int moves;
        };

        queue<State> q;

       
        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int fullMask = (1 << k) - 1;

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

           
            if (cur.mask == fullMask) {
                return cur.moves;
            }

            
            if (cur.e == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

              
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

               
                if (classroom[nr][nc] == 'X') {
                    continue;
                }

               
                int newEnergy = cur.e - 1;

             
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                
                int newMask = cur.mask;

                if (classroom[nr][nc] == 'L') {
                    int id = litterId[nr][nc];
                    newMask |= (1 << id);
                }

               
                if (!visited[nr][nc][newEnergy][newMask]) {
                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        cur.moves + 1
                    });
                }
            }
        }

        return -1;
    }
};