class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> end(26, 0);
        long long total = 0;

        for (char ch : s) {
            int i = ch - 'a';

            long long newCount = (total + 1) % MOD;

            total = (total - end[i] + newCount + MOD) % MOD;

            end[i] = newCount;
        }

        return total;
    }
};