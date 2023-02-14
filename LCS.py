import numpy as np

def LCS_bottom_up(x:str, y:str) -> int:
    # Initialise dictionary
    dp = np.zeros((len(x)+1, len(y)+1), dtype=int)

    # For each entry dp[i][j], the value is
    # dp[i-1][j-1]+1 if characters are the same
    # max(dp[i][j-1], dp[i-1][j]) otherwise
    for i in range(len(x)):
        for j in range(len(y)):
            if x[i] == y[j]:
                dp[i+1][j+1] = dp[i][j]+1
            elif dp[i][j+1] > dp[i+1][j]:
                dp[i+1][j+1] = dp[i][j+1]
            else:
                dp[i+1][j+1] = dp[i+1][j]
                
    return dp[len(x)][len(y)]


if __name__ == "__main__":
    x = 'apple'
    y = 'ape'
    print(LCS_bottom_up(x, y))