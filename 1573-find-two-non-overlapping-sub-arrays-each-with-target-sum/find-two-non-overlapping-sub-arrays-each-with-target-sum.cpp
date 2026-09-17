class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();


        vector<int> best(n, INT_MAX);

        unordered_map<long long, int> mp;
        mp[0] = -1;

        long long prefixSum = 0;
        int shortest = INT_MAX;
        int answer = INT_MAX;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];

            long long required = prefixSum - target;

            if (mp.find(required) != mp.end()) {
                int prevIndex = mp[required];

                int currentLength = i - prevIndex;
                int start = prevIndex + 1;

                if (start > 0 && best[start - 1] != INT_MAX) {
                    answer = min(answer,
                                 currentLength + best[start - 1]);
                }

                shortest = min(shortest, currentLength);
            }

            best[i] = shortest;

            mp[prefixSum] = i;
        }

        return answer == INT_MAX ? -1 : answer;
    }
};