class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        unordered_map<int, int> cnt;

        // Number of windows containing each value
        unordered_map<int, int> windows;

        // First window
        for (int i = 0; i < k; i++)
            cnt[nums[i]]++;

        for (auto &[x, c] : cnt)
            windows[x]++;

        // Slide the window
        for (int i = k; i < n; i++) {
            int out = nums[i - k];
            int in = nums[i];

            if (--cnt[out] == 0)
                cnt.erase(out);

            cnt[in]++;

            for (auto &[x, c] : cnt)
                windows[x]++;
        }

        for (auto &[x, w] : windows) {
            if (w == 1)
                ans = max(ans, x);
        }

        return ans;
    }
};