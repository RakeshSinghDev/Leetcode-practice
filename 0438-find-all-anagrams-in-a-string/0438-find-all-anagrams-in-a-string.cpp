class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;

        if(p.length()>s.length()){
            return ans;
        }
        vector<int>need(26,0);
        vector<int>window(26,0);

        for(char c: p){
            need[c-'a']++;
        }

        int left=0;

        for(int right=0; right<s.length(); right++){

            window[s[right]-'a']++;

            if(right-left+1==p.length()){
                
                if(window==need){
                    ans.push_back(left);
                }
                window[s[left]-'a']--;

                left++;
            }
        }
      return ans;

    }
};