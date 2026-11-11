
var validPath = function(n, edges, source, destination) {

    let adj = Array.from({ length: n }, () => []);

    for (let [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }

    let visited = new Array(n).fill(0);
    let q = [];
    let front = 0;

    visited[source] = 1;
    q.push(source);

    
    while (front < q.length) {

        let node = q[front];
        front++;

       
        if (node === destination) {
            return true;
        }

        
        for (let neighbor of adj[node]) {

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return false;
};
