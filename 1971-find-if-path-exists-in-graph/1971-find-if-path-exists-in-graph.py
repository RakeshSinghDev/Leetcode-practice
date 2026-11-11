
from collections import deque

class Solution:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:

        # Step 1: Build adjacency list
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # Step 2: Initialize visited and queue
        visited = [0] * n
        q = deque()

        visited[source] = 1
        q.append(source)

        # Step 3: BFS traversal
        while q:

            node = q.popleft()

          
            if node == destination:
                return True

        
            for neighbor in adj[node]:

                if not visited[neighbor]:
                    visited[neighbor] = 1
                    q.append(neighbor)

       
        return False
