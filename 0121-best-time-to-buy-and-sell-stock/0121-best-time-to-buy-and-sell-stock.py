class Solution:
    def maxProfit(self, prices: List[int]) -> int:
      minVal = float('inf')
      maxProfit = 0

      for price in prices:
        minVal = min(minVal, price)
        profit = price - minVal
        maxProfit = max(maxProfit, profit)
      
      return maxProfit
        