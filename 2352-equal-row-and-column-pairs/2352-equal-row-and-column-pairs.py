
class Solution:
    def equalPairs(self, grid: list[list[int]]) -> int:
        n = len(grid)
        count = 0

        for i in range(n):
            for j in range(n):
                equal = True

                for k in range(n):
                    if grid[i][k] != grid[k][j]:
                        equal = False
                        break

                if equal:
                    count += 1

        return count
