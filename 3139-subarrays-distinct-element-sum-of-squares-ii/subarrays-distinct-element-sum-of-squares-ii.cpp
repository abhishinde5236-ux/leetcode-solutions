class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> sum1, sum2, lazy;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        sum2[node] = (sum2[node] + 2 * val * sum1[node]
                      + len * val * val) % MOD;

        sum1[node] = (sum1[node] + len * val) % MOD;
        lazy[node] += val;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);
        int mid = (l + r) / 2;

        if (ql <= mid)
            update(node * 2, l, mid, ql, qr, val);

        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr, val);

        sum1[node] = (sum1[node * 2] + sum1[node * 2 + 1]) % MOD;
        sum2[node] = (sum2[node * 2] + sum2[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum1.assign(4 * n, 0);
        sum2.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> lastSeen;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];
            int prev = lastSeen.count(x) ? lastSeen[x] : -1;

            // Increase distinct counts for valid left endpoints.
            update(1, 0, n - 1, prev + 1, r, 1);

            lastSeen[x] = r;

            // Add squared distinct counts of subarrays ending at r.
            ans = (ans + sum2[1]) % MOD;
        }

        return ans;
    }
};