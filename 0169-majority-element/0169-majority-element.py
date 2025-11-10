class Solution:
    # def majorityElement(self, nums: List[int]) -> int:
    #   n = len(nums) // 2
    #   mp = {}
    #   for num in nums:
    #     mp[num] = mp.get(num, 0) + 1
    #     if (mp[num] > n):
    #       return num
    #   return -1
    def majorityElement(self, nums: List[int]) -> int:
      count = 0
      candidate = None

      for num in nums:
        if count == 0:
          candidate = num
        count += (1 if num == candidate else -1)
      return candidate
