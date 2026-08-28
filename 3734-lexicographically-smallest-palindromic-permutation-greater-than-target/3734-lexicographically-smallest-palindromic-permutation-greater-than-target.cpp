class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }


        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

     
        int halfLen = n / 2;

      
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        string prefix;

       
        auto feasible = [&]() -> bool {

            string left = prefix;

            // to create the largest possible completion.
            for (int c = 25; c >= 0; c--) {
                left += string(halfCnt[c], char('a' + c));
            }

            string right = left;

            reverse(right.begin(), right.end());

            string palindrome = left;

            if (middle != 0) {
                palindrome += middle;
            }

            palindrome += right;

            return palindrome > target;
        };

        for (int pos = 0; pos < halfLen; pos++) {

            bool chosen = false;

            for (int c = 0; c < 26; c++) {

                if (halfCnt[c] == 0) {
                    continue;
                }

                halfCnt[c]--;
                prefix.push_back(char('a' + c));

               
                if (feasible()) {
                    chosen = true;
                    break;
                }

                prefix.pop_back();
                halfCnt[c]++;
            }

          
            if (!chosen) {
                return "";
            }
        }

        
        string answer = prefix;

        if (middle != 0) {
            answer += middle;
        }

        string right = prefix;
        reverse(right.begin(), right.end());

        answer += right;

        if (answer > target) {
            return answer;
        }

        return "";
    }
};