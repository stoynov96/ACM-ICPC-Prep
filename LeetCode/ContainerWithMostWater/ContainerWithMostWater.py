"""
Link to problem:
https://leetcode.com/problems/container-with-most-water/description/
"""
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxarea = -1
        left = 0
        right = len(height)-1
        while left < right:
            # advancing
            if height[left] < height[right]:
                area = (right-left) * height[left]
                left += 1
            else :
                area = (right-left) * height[right]
                right -= 1
            if area > maxarea:
                maxarea = area
        return maxarea