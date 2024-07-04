def maxSubArray(nums): 
        maxVal = nums[0]
        curSum = 0

        for n in nums:
            if curSum < 0:
                curSum = 0
            curSum +=n
            maxVal = max(maxVal, curSum)
        return maxVal


print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))