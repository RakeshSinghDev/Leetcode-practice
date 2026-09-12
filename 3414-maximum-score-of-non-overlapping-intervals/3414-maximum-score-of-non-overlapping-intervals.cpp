class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({intervals[i][0], intervals[i][1],
                           intervals[i][2], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = arr[i][0];
        }

        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                arr[i][1]
            ) - starts.begin();
        }

        using Result = pair<long long, vector<int>>;

        vector<vector<Result>> dp(n + 1, vector<Result>(5));

        auto better = [](const Result& a, const Result& b) {
            if (a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                Result skip = dp[i + 1][k];

                Result take = dp[next[i]][k - 1];

                take.first += arr[i][2];
                take.second.push_back(arr[i][3]);

                sort(take.second.begin(), take.second.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].second;
    }
};