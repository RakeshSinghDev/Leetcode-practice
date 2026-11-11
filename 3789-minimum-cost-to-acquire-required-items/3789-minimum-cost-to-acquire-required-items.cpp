class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a = 1LL*cost1*need1 + 1LL*cost2*need2;

        long long b = 1LL*max(need1,need2)*costBoth;

        int common = min(need1,need2);

        long long c  =1LL *common*costBoth +1LL*(need1-common)*cost1 +1LL*(need2-common)*cost2;

        return min({a,b,c});
    }
};