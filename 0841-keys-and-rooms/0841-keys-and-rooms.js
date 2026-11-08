/**
 * @param {number[][]} rooms
 * @return {boolean}
 */
var canVisitAllRooms = function(rooms) {
    let n = rooms.length;

    let visited = new Array(n).fill(0);

    let q =[];

    visited[0] =1;
    q.push(0);

    let count = 0;
    let front = 0;

    while(front<q.length){
        let room = q[front];
        front++;

        count++;

        for(let key of rooms[room]){

            if(!visited[key]){
                visited[key] =1;
                q.push(key);
            }
        }
    }
    return count ===n;
};