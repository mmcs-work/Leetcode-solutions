class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = [1]
        while len(ans)<n:
            cur = ans[-1]*10
            while cur > n:
                cur = cur//10
                cur+=1
                while cur%10 == 0:
                    cur//=10
            ans.append(cur)
        return ans