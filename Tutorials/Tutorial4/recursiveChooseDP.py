import numpy as np

dp = None

def recursive_choose_dp(n, k):
    # Space = O(nk)
    # Time Complexity = O(nk)

    global dp
    if n >= 0 and k == 0:
        return 1
    elif n == 0 and k > 0:
        return 0

    if dp[n-1][k-1] < 0:
        recursive_choose_dp(n-1, k-1)
    if dp[n-1][k] < 0:
        recursive_choose_dp(n-1, k)
    dp[n][k] = dp[n-1][k-1] + dp[n-1][k]

    return dp[n-1][k-1] + dp[n-1][k]

    

if __name__ == "__main__":
    n = 100
    k = 50
    dp = -np.ones(shape=(n+1, k+1), dtype=np.int64)
    for i in range(n+1):
        dp[i][0] = 1
    for j in range(1, k+1):
        dp[0][j] = 0
    print(recursive_choose_dp(n, k))