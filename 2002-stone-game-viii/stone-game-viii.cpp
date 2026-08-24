class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);

        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        vector<long long> dp(n, 0);

        long long best = prefix[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            dp[i] = best;
            best = max(best, prefix[i] - dp[i]);
        }

        return dp[0];
    }
};