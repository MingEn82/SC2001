import numpy as np

def iterative_choose_dp(n, k):
    # Space Complexity = O(nk)
    # Time Complexity = O(nk)

    dp = np.zeros(shape=(n+1, k+1), dtype=np.int64)
    for i in range(n+1):
        dp[i][0] = 1
    
    for i in range(1, n+1):
        for j in range(1, k+1):
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    
    return dp[n][k]

    

if __name__ == "__main__":
    n = 5
    k = 3
    print(iterative_choose_dp(n, k))