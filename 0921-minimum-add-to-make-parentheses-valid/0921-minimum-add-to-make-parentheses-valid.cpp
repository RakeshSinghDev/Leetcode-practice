class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int additions = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            }
            else {
                if (balance > 0) {
                    balance--;
                }
                else {
                    additions++;
                }
            }
        }

        return additions + balance;
    }
};