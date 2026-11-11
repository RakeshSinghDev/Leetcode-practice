/**
 * @param {number} cost1
 * @param {number} cost2
 * @param {number} costBoth
 * @param {number} need1
 * @param {number} need2
 * @return {number}
 */
var minimumCost = function(cost1, cost2, costBoth, need1, need2) {
    let a  =  need1*cost1 + need2*cost2;
    let b  = Math.max(need1,need2)*costBoth;

    let common  = Math.min(need1,need2);

    let c = common*costBoth
           +(need1-common)*cost1
           +(need2 - common)*cost2;

    return Math.min(a,b,c)
    
};