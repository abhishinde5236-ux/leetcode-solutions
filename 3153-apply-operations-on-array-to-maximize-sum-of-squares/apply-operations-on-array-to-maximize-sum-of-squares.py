
class Solution:
    def maxSum(self, nums: list[int], k: int) -> int:
        MOD = 10**9 + 7
        bits = [0] * 32

        # Count set bits at each position
        for num in nums:
            for b in range(32):
                if num & (1 << b):
                    bits[b] += 1

        ans = 0

        # Build k numbers with the maximum possible set bits
        for _ in range(k):
            x = 0
            for b in range(32):
                if bits[b] > 0:
                    x |= (1 << b)
                    bits[b] -= 1

            ans = (ans + x * x) % MOD

        return ans