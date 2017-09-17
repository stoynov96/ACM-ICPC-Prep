"""
Link to problem:
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
"""
class Solution(object):
	def __init__(self):
		self.used = [-1] * 260
	def lengthOfLongestSubstring(self, s):
		maxLen = 0
		cLen = 0
		start = 0
		end = 0
		for i in range(len(s)):
            # Check if this char is used
			if self.used[ord(s[i])] >= 0:
				if cLen > maxLen:
					maxLen = cLen
				newStart = self.used[ord(s[i])] + 1
				self.resetUsed(s, start, newStart)
				cLen -= (newStart - start)
				start = newStart        
            # Mark this char used
			self.used[ord(s[i])] = i
			cLen += 1
		if cLen > maxLen:
			maxLen = cLen
		return maxLen
	def resetUsed(self, s, start, newStart):
		for i in range(start, newStart):
			self.used[ord(s[i])] = -1