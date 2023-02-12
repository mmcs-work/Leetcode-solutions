class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        sorted_arr = sorted(arr, key = lambda num:abs(x-num))
        
        result = sorted_arr[:k]
        return sorted(result)