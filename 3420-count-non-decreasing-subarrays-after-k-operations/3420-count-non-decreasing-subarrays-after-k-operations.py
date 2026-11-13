
from typing import List


class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)

        # Step 1: Next Greater Element
        nxt = [n] * n
        stack = []

        for i in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] <= nums[i]:
                stack.pop()

            nxt[i] = stack[-1] if stack else n
            stack.append(i)

        # Step 2: Prefix sums
        pref = [0] * (n + 1)

        for i in range(n):
            pref[i + 1] = pref[i] + nums[i]

        # Step 3: Binary lifting tables
        LOG = n.bit_length()

        up = [[n] * n for _ in range(LOG)]
        weight = [[0] * n for _ in range(LOG)]

        # One jump: i -> next greater element
        for i in range(n):
            j = nxt[i]
            up[0][i] = j

            weight[0][i] = (
                nums[i] * (j - i)
                - (pref[j] - pref[i])
            )

        # Build binary lifting tables
        for p in range(1, LOG):
            for i in range(n):
                mid = up[p - 1][i]

                if mid < n:
                    up[p][i] = up[p - 1][mid]

                    weight[p][i] = (
                        weight[p - 1][i]
                        + weight[p - 1][mid]
                    )
                else:
                    weight[p][i] = weight[p - 1][i]

        # Step 4: Calculate minimum operations
        # for subarray [l, r]
        def get_cost(l, r):
            cur = l
            total = 0

            for p in range(LOG - 1, -1, -1):
                j = up[p][cur]

                if j <= r:
                    total += weight[p][cur]
                    cur = j

            # Last incomplete block
            total += (
                nums[cur] * (r - cur + 1)
                - (pref[r + 1] - pref[cur])
            )

            return total

        # Step 5: Sliding window
        left = 0
        ans = 0

        for right in range(n):
            while left <= right and get_cost(left, right) > k:
                left += 1

            ans += right - left + 1

        return ans
