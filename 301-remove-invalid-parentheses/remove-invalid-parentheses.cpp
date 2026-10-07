class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {

            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                // Too many closing brackets
                if (balance < 0)
                    return false;
            }
        }

        // Equal number of '(' and ')'
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        unordered_set<string> current;
        current.insert(s);

        while (true) {

            // Check current level
            for (string str : current) {
                if (isValid(str)) {
                    ans.push_back(str);
                }
            }

            // If we found valid strings,
            // this is the minimum-removal level.
            if (!ans.empty()) {
                return ans;
            }

            // Generate next level
            unordered_set<string> next;

            for (string str : current) {

                for (int i = 0; i < str.length(); i++) {

                    // We only remove parentheses.
                    if (str[i] != '(' && str[i] != ')')
                        continue;

                    string nextString =
                        str.substr(0, i) +
                        str.substr(i + 1);

                    next.insert(nextString);
                }
            }

            current = next;
        }
    }
};