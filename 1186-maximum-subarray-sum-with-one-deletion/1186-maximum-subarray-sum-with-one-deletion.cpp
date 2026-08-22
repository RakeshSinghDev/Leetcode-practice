class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        int onedelete = arr[0];

        int answer = arr[0];

        for(int i=1; i<arr.size(); i++){
            int oldnodelete = nodelete;
            int oldonedelete = onedelete;

            nodelete =max({arr[i], arr[i]+oldnodelete});

            onedelete = max({oldnodelete, oldonedelete+arr[i]});

            answer = max({answer,nodelete, onedelete});
        }
        return answer;
    }
};