/**
 * @param {number[][]} grid
 * @return {number}
 */
var equalPairs = function(grid) {
    const n = grid.length;
    let count = 0;

    for(let i=0; i<n; i++){
        for(let j= 0; j<n; j++){
            let equal = true;


            for(let k=0; k<n; k++){
                if(grid[i][k] !== grid[k][j]){
                    equal = false;
                    break;
                }
            }
            if(equal){
                count++;
            }
        }
    }
    return count 
};