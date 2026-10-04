class Solution(object):
    def isMatch(self, s, p):
        memo = {}

        def dp(i, j):
            if (i, j) in memo:
                return memo[(i, j)]

            # Pattern finished
            if j == len(p):
                return i == len(s)

            # Check current character match
            first_match = (
                i < len(s) and
                (p[j] == s[i] or p[j] == '.')
            )

            # If next character is '*'
            if j + 1 < len(p) and p[j + 1] == '*':
                result = (
                    dp(i, j + 2) or          # use preceding char 0 times
                    (first_match and dp(i + 1, j))  # use it 1+ times
                )
            else:
                result = first_match and dp(i + 1, j + 1)

            memo[(i, j)] = result
            return result

        return dp(0, 0)