class Solution {
public:
    int getnext(int n){
        int sum =0;

        while(n>0){
            int digit = n%10;
            sum += digit*digit;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {

        int slow =n;
        int fast =n;

        while(true){

            slow= getnext(slow);
            fast = getnext(getnext(fast));

            if(slow==fast)
            break;
        }
      
      return slow==1;
    }
    
};