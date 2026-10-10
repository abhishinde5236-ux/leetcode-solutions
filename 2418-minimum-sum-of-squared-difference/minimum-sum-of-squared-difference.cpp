
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long k = (long long)k1 + k2;
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (k >= total)
            return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            int finalDiff = min(d, low);
            ans += 1LL * finalDiff * finalDiff;

            if (d > low)
                used += d - low;
        }

        long long remaining = k - used;
        ans -= remaining * (2LL * low - 1);

        return ans;
    }
};
