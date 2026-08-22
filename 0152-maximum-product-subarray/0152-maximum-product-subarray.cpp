class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentmin = nums[0];
        int currentmax = nums[0];
        int answer = nums[0];

        for(int i=1; i<nums.size(); i++){
            int oldmax = currentmax;
            int oldmin = currentmin;

            currentmax = max({nums[i], oldmax*nums[i], oldmin*nums[i]});
            currentmin = min({nums[i], oldmax*nums[i], oldmin*nums[i]});

            answer = max(answer,currentmax);
        }

        return answer;
        
    }
};