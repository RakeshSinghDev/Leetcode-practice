class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
       const int mod = 1e9 +7;
       int even = 1;
       int odd = 0;

       int prefix = 0;
       int ans = 0;
        
        
        for(int num: arr){

            prefix +=num;

            if(prefix%2==0){
                ans  = (ans + odd)%mod;
                even++;
            }
            else{
                ans = (ans + even)%mod;
                odd++;
            }
        }
        return ans;
    }
};