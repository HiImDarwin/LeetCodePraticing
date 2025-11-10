class Solution:
    # def containsDuplicate(self, nums: List[int]) -> bool:
    #   st = set()
    #   for num in nums:
    #     if num in st:
    #       return True
    #     st.add(num)
    #   return False

    def containsDuplicate(self, nums: List[int]) -> bool:
      return len(nums) != len(set(nums))