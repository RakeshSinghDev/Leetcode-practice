
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long g = 0, l = 1;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                g = gcd(g, (long long)x);
                l = l / gcd(l, (long long)x) * x;

                long long target = g * l;

                // Check before multiplication to prevent overflow
                if (product > target / x)
                    break;

                product *= x;

                if (product == target) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

