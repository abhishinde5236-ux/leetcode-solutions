class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll getLCM(ll a, ll b, ll limit) {
        ll g = gcd(a, b);
        a /= g;

        if (a > limit / b)
            return limit + 1;

        return a * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());

        int n = coins.size();

        auto count = [&](ll x) -> ll {
            ll ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                ll L = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        L = getLCM(L, coins[i], x);

                        if (L > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid)
                    continue;

                ll ways = x / L;

                if (bits % 2)
                    ans += ways;
                else
                    ans -= ways;
            }

            return ans;
        };

        ll low = 1;
        ll high = 1LL * coins[0] * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};