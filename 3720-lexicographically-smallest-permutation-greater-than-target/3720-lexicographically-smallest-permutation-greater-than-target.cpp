class Solution {
public:
    string lexGreaterPermutation(string nums, string target) {
        int n = nums.size();

        vector<int> freq(26, 0);

        for (char c : nums) {
            freq[c - 'a']++;
        }

     
        for (int i = n - 1; i >= 0; i--) {

            vector<int> rem = freq;
            bool possible = true;

           
            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (rem[x] == 0) {
                    possible = false;
                    break;
                }

                rem[x]--;
            }

            if (!possible)
                continue;

         
            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {

                if (rem[c] > 0) {

                    string ans = target.substr(0, i);

                    
                    ans += char('a' + c);
                    rem[c]--;

                
                    for (int x = 0; x < 26; x++) {
                        while (rem[x] > 0) {
                            ans += char('a' + x);
                            rem[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};