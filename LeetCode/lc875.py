class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles) 

        def check(v: int) -> bool:
            cnt = 0
            for pile in piles:
                cnt += (pile + v - 1) // v
            return cnt <= h

        while l < r:
            mid = l + r >> 1
            if (check(mid)):
                r = mid
            else:
                l = mid + 1
        return l