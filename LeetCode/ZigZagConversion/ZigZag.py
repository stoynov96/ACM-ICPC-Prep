class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1 or numRows >= len(s):
            return s
        result = []
        
        first = (numRows-1)*2
        second = 0
        lenS = len(s)

        j = 0
        while j < lenS:
            result.append(s[j])
            j+= first
        first -= 2
        second += 2

        for i in range(1,numRows-1):
            j = i
            while True:
                result.append(s[j])
                j += first
                if j >= lenS: break
                result.append(s[j])
                j += second
                if j >= lenS: break
                
            first -= 2
            second += 2

        j = numRows-1
        while j < lenS:
            result.append(s[j])
            j += second
        second += 2
        
        return "".join(result)

sol = Solution()
print (sol.convert("PAYPALISHIRINGRIGHTNOW",4))
