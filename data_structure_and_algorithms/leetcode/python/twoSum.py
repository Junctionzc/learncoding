def twoSum(nums, target):
    retList = [] 
    for i in range(0, len(nums) - 1):
        for j in range(i, len(nums) - 1):
            if nums[i] + nums[j + 1] == target:
                retList.append(i)
                retList.append(j + 1)
                return retList
    return retList