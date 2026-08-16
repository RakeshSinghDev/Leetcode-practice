class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int ans = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        for(int right = 0; right < s.length(); right++) {

           
            freq[s[right] - 'A']++;

           
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

           
            int windowSize = right - left + 1;

            while(windowSize - maxFreq > k) {

                freq[s[left] - 'A']--;

                left++;

                windowSize = right - left + 1;
            }

            
            ans = max(ans, windowSize);
        }

        return ans;
    }
};