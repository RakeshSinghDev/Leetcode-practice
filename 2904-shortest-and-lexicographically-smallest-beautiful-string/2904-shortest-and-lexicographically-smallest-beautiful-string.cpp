class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;

        int bestLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            
            if (s[right] == '1') {
                ones++;
            }

          
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            
            if (ones == k) {

                
                while (s[left] == '0') {
                    left++;
                }

                int len = right - left + 1;
                string current = s.substr(left, len);

                
                if (len < bestLen) {
                    bestLen = len;
                    ans = current;
                }
                else if (len == bestLen && current < ans) {
                    ans = current;
                }
            }
        }

        return ans;
    }
};