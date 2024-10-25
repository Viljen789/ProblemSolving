class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0  # Pointer for the position of non-val elements
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]  # Move non-val element to the front
                k += 1  # Increment the position for the next non-val element
        return k  # Ret