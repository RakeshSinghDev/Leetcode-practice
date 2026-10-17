
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            arr.push_back({sum, nums[i]});
        }

        sort(arr.begin(), arr.end());

        vector<int> sortedNums;
        for (auto p : arr) {
            sortedNums.push_back(p.second);
        }

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != sortedNums[i]) {
                swaps++;

                int j = pos[sortedNums[i]];

                pos[nums[i]] = j;
                pos[nums[j]] = i;

                swap(nums[i], nums[j]);
            }
        }

        return swaps;
    }
};
