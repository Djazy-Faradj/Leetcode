# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        upperBound = n
        lowerBound = 1

        while (guess(n) != 0):
            if (guess(n) == -1):
                upperBound = n
                n = math.trunc((n-lowerBound)/2)
            else:
                lowerBound = n
                n += math.trunc((upperBound-n)/2)
        return n