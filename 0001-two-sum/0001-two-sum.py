class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
      tmp = {}
      for i in range(len(nums)):
        complement = target - nums[i]
        if complement in tmp:
            return [tmp[complement], i]
        tmp[nums[i]] = i
      return []

        