class Solution {
    string getMinDigits(int r2, int r3, int r5, int r7) {
        int c5 = r5;
        int c7 = r7;
        
        int c9 = r3 / 2; 
        r3 %= 2;
        
        int c8 = r2 / 3; 
        r2 %= 3;
        
        int c4 = r2 / 2; 
        int c2 = r2 % 2;
        
        int c3 = r3;
        int c6 = 0;
        
        if (c2 == 1 && c3 == 1) {
            c2 = 0; c3 = 0; c6 = 1;
        } else if (c4 == 1 && c3 == 1) {
            c4 = 0; c3 = 0;
            c2 = 1; c6 = 1;
        }
        
        string res = "";
        res += string(c2, '2');
        res += string(c3, '3');
        res += string(c4, '4');
        res += string(c5, '5');
        res += string(c6, '6');
        res += string(c7, '7');
        res += string(c8, '8');
        res += string(c9, '9');
        
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        vector<int> req(4, 0);
        int primes[4] = {2, 3, 5, 7};
        
        for (int i = 0; i < 4; ++i) {
            while (t % primes[i] == 0) {
                req[i]++;
                t /= primes[i];
            }
        }
        
        if (t > 1) {
            return "-1";
        }
        
        int df[10][4] = {
            {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0}, 
            {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}  
        };
        
        int n = num.length();
        vector<vector<int>> pref(n + 1, vector<int>(4, 0));
        int valid_len = 0;
        
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') break;
            
            int d = num[i] - '0';
            for (int j = 0; j < 4; ++j) {
                pref[i + 1][j] = pref[i][j] + df[d][j];
            }
            valid_len++;
        }
        
        if (valid_len == n) {
            bool isValid = true;
            for (int j = 0; j < 4; ++j) {
                if (pref[n][j] < req[j]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) return num;
        }
        
        for (int i = min(n - 1, valid_len); i >= 0; --i) {
            int start_d = (i < n) ? (num[i] - '0' + 1) : 1;
            
            for (int d = start_d; d <= 9; ++d) {
                int rem[4];
                for (int j = 0; j < 4; ++j) {
                    rem[j] = max(0, req[j] - pref[i][j] - df[d][j]);
                }
                
                string needed = getMinDigits(rem[0], rem[1], rem[2], rem[3]);
                int space_left = n - 1 - i;
                
                if (needed.length() <= space_left) {
                    string pad(space_left - needed.length(), '1');
                    return num.substr(0, i) + char('0' + d) + pad + needed;
                }
            }
        }
        
        string needed = getMinDigits(req[0], req[1], req[2], req[3]);
        int new_len = max(n + 1, (int)needed.length());
        string pad(new_len - needed.length(), '1');
        
        return pad + needed;
    }
};