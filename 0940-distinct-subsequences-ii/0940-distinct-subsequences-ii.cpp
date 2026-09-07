class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        long long dp = 1;

        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';

            long long old = dp;

            dp = (2 * dp - last[idx] + MOD) % MOD;

            last[idx] = old;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};