"""
Link to problem:
https://leetcode.com/problems/integer-to-english-words/description/
"""
class Solution(object):
    digLabels = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
    digLabelsDec = ["","Ten","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
    digLabelsBig = ["", " Thousand", " Million", " Billion"]

    def numberToWords(self, num):
    	if (not num): return "Zero"
    	triples = []
    	result = ""
    	bigLabelsCounter = 0
    	while num>0:
    		newTripple = num%10 + 10*(int(num/10)%10) + 100 * (int(num/100)%10)

    		connector = self.digLabelsBig[bigLabelsCounter]
    		if result != "":	connector += " "

    		if newTripple:	result = connector.join( (self.chunksOfThree(newTripple) , result ) )
    		# print (self.chunksOfThree(newTripple))

    		num = int(num/1000)
    		bigLabelsCounter += 1
    	return result

    def chunksOfThree(self, num):
    	"""Receives a number from 0 to 999 (inclusive) and translates it to english"""
    	result = ""
    	hunDig = int(num / 100)
    	decDig = int(num % 100)
    	oneDig = int(num % 10)
    	if (hunDig): result += self.digLabels[hunDig] + " Hundred"
    	if (hunDig and decDig): result += " "
    	if (decDig >= 20):
    		decDig = int(decDig/10)
    		result += self.digLabelsDec[decDig]
    	elif (decDig):
    		oneDig = 0
    		result += self.digLabels[decDig]
    	if (oneDig and decDig): result += " "
    	if (oneDig): result += self.digLabels[oneDig]
    	return result