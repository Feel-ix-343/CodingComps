class Solution(object):
    def countTriples(self, n):
        """
        :type n: int
        :rtype: int
        """
        answer = 0
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                for c in range(1, n + 1):
                    if a * a + b * b == c * c:
                        answer += 1
        return answer

