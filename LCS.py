import numpy as np

def LCS_bottom_up(x:str, y:str) -> int:
    # Initialise dictionary
    dp = np.empty((len(x)+1, len(y)+1), dtype=int)

    # Initialise hint dictionary
    hint = np.empty((len(x)+1, len(y)+1), dtype=str)

    # Initialise inital values
    for i in range(len(x)+1):
        dp[i][0] = 0
        hint[i][0] = "|"
    for j in range(len(y)+1):
        dp[0][j] = 0
        hint[0][j] = "-"

    # For each entry dp[i][j], the value is
    # dp[i-1][j-1]+1 if characters are the same
    # max(dp[i][j-1], dp[i-1][j]) otherwise
    for i in range(len(x)):
        for j in range(len(y)):
            if x[i] == y[j]:
                dp[i+1][j+1] = dp[i][j]+1
                hint[i+1][j+1] = '\\'
            elif dp[i][j+1] > dp[i+1][j]:
                dp[i+1][j+1] = dp[i][j+1]
                hint[i+1][j+1] = "|"
            else:
                dp[i+1][j+1] = dp[i+1][j]
                hint[i+1][j+1] = "-"

    # prints lcs
    i, j = len(x), len(y)
    lcs = ''
    while i > 0 and j > 0:
        if hint[i][j] == '\\':
            lcs += x[i-1]
            i -= 1
            j -= 1
        elif hint[i][j] == "|":
            i -= 1
        else:
            j -=1
    print(lcs[::-1])

    return dp[len(x)][len(y)]


if __name__ == "__main__":
    x = 'AAACCGTGAGTTATTCGTTCTAGAA'
    y = 'CACCCCTAAGGTACCTTTGGTTC'
    print(LCS_bottom_up(x, y))