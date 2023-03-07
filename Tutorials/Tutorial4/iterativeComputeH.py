import numpy as np

def iterative_compute_H(n):
    # Space = O(n)
    # Time = O(n^2)

    def sum_previous(n):
        for i in range(0, n, 2):
            dp[n] += dp[i]

    if n <= 0:
        return 1
    
    dp = np.zeros(n+1, dtype=np.int64)
    dp[0] = 1

    for i in range(2, n+1, 2):
        sum_previous(i) # O(n^2)
    if n % 2 == 1:
        sum_previous(n) # O(n/2)

    return dp[n]
    

if __name__ == "__main__":
    print(iterative_compute_H(100))