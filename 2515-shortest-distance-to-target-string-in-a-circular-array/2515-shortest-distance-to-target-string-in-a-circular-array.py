class Solution:
    def closetTarget(self, w: List[str], t: str, ss: int) -> int:
        if t not in w:
            return -1
        return min((w[ss:] + w).index(t), (w + w[:ss])[::-1].index(t) + 1)