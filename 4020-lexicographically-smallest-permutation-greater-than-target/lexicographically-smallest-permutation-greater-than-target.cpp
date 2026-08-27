class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string prefix;

        // Try to make the prefix equal to target
        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';

            // Match target[i] if possible
            if (cnt[t] > 0) {
                prefix += target[i];
                cnt[t]--;
            } 
            else {
                // Cannot match target[i].
                // Try the smallest character greater than target[i].
                for (int c = t + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        prefix += char('a' + c);
                        cnt[c]--;

                        // Add remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            prefix += string(cnt[j], char('a' + j));
                        }

                        return prefix;
                    }
                }

                break;
            }
        }

        // We either formed target completely or got stuck.
        // Backtrack to find the rightmost position we can increase.
        while (!prefix.empty()) {
            int pos = prefix.size() - 1;

            // Put the matched character back
            int old = prefix.back() - 'a';
            prefix.pop_back();
            cnt[old]++;

            int t = target[pos] - 'a';

            // Find the smallest character greater than target[pos]
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    prefix += char('a' + c);
                    cnt[c]--;

                    // Remaining characters in ascending order
                    for (int j = 0; j < 26; j++) {
                        prefix += string(cnt[j], char('a' + j));
                    }

                    return prefix;
                }
            }
        }

        return "";
    }
};