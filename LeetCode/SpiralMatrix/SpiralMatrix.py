"""
Link to problem:
https://leetcode.com/problems/spiral-matrix/description/
"""
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if len(matrix) == 0:
            return []
        if len(matrix[0]) == 0:
            return []
        return self.printEdge(matrix, 0)
    def printEdge(self, matrix, offset):
        l = []
        edgeC = len(matrix[0]) - offset - 1 # last column to print
        edgeR = len(matrix) - offset - 1 # last row to print
        if edgeC < offset or edgeR < offset:
            return []
        i = offset
        while i <= edgeC:
            l.append(matrix[offset][i])
            i += 1
        i = offset+1
        while i <= edgeR:
            l.append(matrix[i][edgeC])
            i += 1
        if edgeR == offset or edgeC == offset:
            return l
        i = edgeC-1
        while i >= offset:
            l.append(matrix[edgeR][i])
            i -= 1
        i = edgeR-1
        while i > offset:
            l.append(matrix[i][offset])
            i -= 1
        return l + self.printEdge(matrix, offset+1)