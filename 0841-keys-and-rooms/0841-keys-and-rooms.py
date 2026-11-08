from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms: list[list[int]]) -> bool:
        n = len(rooms)

        visited = [0]*n
        q = deque()

        visited[0] =1
        q.append(0)

        count = 0

        while q:
            room = q.popleft()
            count +=1

            for key in rooms[room]:

                if not visited[key]:

                    visited[key] = 1
                    q.append(key)
        return count == n