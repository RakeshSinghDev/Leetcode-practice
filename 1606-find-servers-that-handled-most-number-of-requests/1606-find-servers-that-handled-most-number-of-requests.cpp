
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Available servers: initially all servers are free
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {completion time, server ID}
        using P = pair<long long, int>;

        // Min heap: server with earliest completion time on top
        priority_queue<P, vector<P>, greater<P>> busy;

        // Number of requests handled by each server
        vector<int> count(k, 0);

        int n = arrival.size();

        for (int i = 0; i < n; i++) {

            int currentTime = arrival[i];

            // Step 1: Release all servers that have completed
            while (!busy.empty() && busy.top().first <= currentTime) {

                int server = busy.top().second;

                busy.pop();

                available.insert(server);
            }

            // Step 2: If all servers are busy, drop request
            if (available.empty()) {
                continue;
            }

            // Step 3: Find preferred server
            int preferred = i % k;

            auto it = available.lower_bound(preferred);

            // Step 4: Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            // Step 5: Assign request
            int server = *it;

            available.erase(it);

            count[server]++;

            // Step 6: Mark server as busy
            long long completionTime =
                (long long)arrival[i] + load[i];

            busy.push({completionTime, server});
        }

        // Step 7: Find maximum number of requests handled
        int maxRequests = *max_element(count.begin(), count.end());

        vector<int> result;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};
