class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        const long long MOD = 1e9 + 7;

        long long totalSum = 0;
        long long prefixSum = 0;
        long long maxPrefix = 0;

        long long maxSub = 0;
        long long current = 0;

        
        for(int x : arr) {

            totalSum += x;

            prefixSum += x;
            maxPrefix = max(maxPrefix, prefixSum);

            current = max(0LL, current + x);
            maxSub = max(maxSub, current);
        }

        // k = 1
        if(k == 1)
            return maxSub % MOD;

        
        long long suffixSum = 0;
        long long maxSuffix = 0;

        for(int i = arr.size() - 1; i >= 0; i--) {

            suffixSum += arr[i];

            maxSuffix = max(maxSuffix, suffixSum);
        }

        
        long long answer = max(
            maxSub,
            maxPrefix + maxSuffix
        );

       
        if(totalSum > 0) {

            answer = max(
                answer,
                maxPrefix +
                maxSuffix +
                (long long)(k - 2) * totalSum
            );
        }

        return answer % MOD;
    }
};