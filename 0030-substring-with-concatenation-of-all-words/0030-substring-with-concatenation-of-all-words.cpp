class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if(s.empty() || words.empty())
            return ans;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if(totalLen > s.length())
            return ans;

        unordered_map<string, int> need;

        
        for(string word : words) {
            need[word]++;
        }

        
        for(int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;

            unordered_map<string, int> window;

            int count = 0;

            while(right + wordLen <= s.length()) {

                
                string word = s.substr(right, wordLen);

                
                right += wordLen;

                
                if(!need.count(word)) {

                    window.clear();
                    count = 0;
                    left = right;

                    continue;
                }

                
                window[word]++;
                count++;

                
                while(window[word] > need[word]) {

                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                
                if(count == wordCount) {

                    ans.push_back(left);

                    
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};