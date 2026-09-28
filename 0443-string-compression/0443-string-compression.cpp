class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        int count=0;
        int write=0;

        for(int i=0; i<n;){
            char ch = chars[i];
            int j=i;

            while(j<n && chars[j]==ch){
                j++;
            }
            count =j-i;

            chars[write++]=ch;
           if(count>1){
            string s = to_string(count);

            for(char c:s){
                chars[write++]=c;
            }
           } 
           i=j;
        }
        return write;
    }
};