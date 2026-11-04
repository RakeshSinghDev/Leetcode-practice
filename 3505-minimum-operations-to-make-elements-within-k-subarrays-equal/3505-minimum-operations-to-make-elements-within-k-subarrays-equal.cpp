
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        
        multiset<int> left, right;

        long long sumLeft = 0, sumRight = 0;

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }

           
            if (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumLeft -= v;

                right.insert(v);
                sumRight += v;
            }
            else if (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumRight -= v;

                left.insert(v);
                sumLeft += v;
            }
        };

        
        auto remove = [&](int val) {
            if (val <= *left.rbegin()) {
                left.erase(left.find(val));
                sumLeft -= val;
            } else {
                right.erase(right.find(val));
                sumRight -= val;
            }

           
            if (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumLeft -= v;

                right.insert(v);
                sumRight += v;
            }
            else if (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumRight -= v;

                left.insert(v);
                sumLeft += v;
            }
        };

        
        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *left.rbegin();

                long long operations =
                    median * (long long)left.size() - sumLeft
                    + sumRight - median * (long long)right.size();

                cost.push_back(operations);
            }
        }

       
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

               
                curr[i] = curr[i - 1];

             
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
