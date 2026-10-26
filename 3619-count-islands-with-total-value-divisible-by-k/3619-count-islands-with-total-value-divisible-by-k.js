
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var countIslands = function(grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    let count = 0;

    function dfs(r, c) {
      
        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid[r][c] === 0) {
            return 0;
        }

        
        const value = grid[r][c];
        grid[r][c] = 0;

        
        let sum = value;
        sum += dfs(r - 1, c);
        sum += dfs(r + 1, c);
        sum += dfs(r, c - 1);
        sum += dfs(r, c + 1);

        return sum;
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                const sum = dfs(i, j);

                if (sum % k === 0) {
                    count++;
                }
            }
        }
    }

    return count;
};
