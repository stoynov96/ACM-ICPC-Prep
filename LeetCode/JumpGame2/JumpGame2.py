"""
Link to problem:
https://leetcode.com/problems/jump-game-ii/description/
"""
from collections import deque
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return 0
        leastSteps = [0] + ([-1] * (len(nums)-1))

        q = deque()
        q.append(0)
        qsize = 1
        goal = len(nums)-1
        while qsize > 0:
            front = q.popleft()
            qsize -= 1
            lastIndex = front + nums[front]
            if lastIndex >= len(nums):
                lastIndex = len(nums)-1
            for i in range (lastIndex, front, -1):
                if i == goal:
                    return leastSteps[front] + 1
                if leastSteps[i] < 0 or leastSteps[front] + 1 < leastSteps[i]:
                    leastSteps[i] = leastSteps[front] + 1
                    q.append(i)
                    qsize += 1
        return leastSteps[len(nums)-1]