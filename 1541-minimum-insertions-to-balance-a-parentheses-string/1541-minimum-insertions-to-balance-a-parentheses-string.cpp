
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
           
                if (i + 1 >= n || s[i + 1] != ')') {
                    insertions++;
                }
                else {
                  
                    i++;
                }

                
                if (open > 0) {
                    open--;
                }
                else {
               
                    insertions++;
                }
            }
        }

        return insertions + 2 * open;
    }
};
