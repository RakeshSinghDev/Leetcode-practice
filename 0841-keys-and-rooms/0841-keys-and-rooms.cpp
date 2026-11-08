class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n =  rooms.size();
        vector<int> visited(n,0);

        queue<int>q;

        visited[0] = 1;
        q.push(0);

        int count = 0;

        while(!q.empty()){

            int room = q.front();
            q.pop();

            count++;

            for(int key : rooms[room]){

                if(!visited[key]){
                    visited[key] =1;
                    q.push(key);
                }
            }
        }

        return count == n;
        
    }
};