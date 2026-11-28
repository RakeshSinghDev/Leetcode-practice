class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        int  dr[] = {-1,1,0,0};
        int  dc[] = {0,0,-1,1};

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){

                if(grid[r][c]=='1'){
                    islands++;

                    queue<pair<int,int>>q;

                    grid[r][c] = '0';
                    q.push({r,c});

                    while(!q.empty()){

                        auto[row,col]= q.front();
                        q.pop();
                    

                    for(int i=0; i<4; i++){
                        int nr = row + dr[i];
                        int nc = col + dc[i];

                        if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]=='1'){

                            grid[nr][nc] = '0';

                            q.push({nr,nc});
                        }
                    }
                }
                }
            }
        }
        return islands;
    }
};