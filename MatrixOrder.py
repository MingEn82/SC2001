import numpy as np

def matrix_order(d:list):
    n = len(d)
    cost = np.zeros((n, n), dtype=int)
    last = np.zeros((n, n), dtype=int)

    for i in range(n-1):
        cost[i][i+1] = 0
    
    for l in range(2, n):
        for i in range(n-l):
            j = i+l
            cost[i][j] = 2147483647
            for k in range(i+1, j):
                c = cost[i][k] + cost[k][j] + d[i]*d[k]*d[j]
                if c < cost[i][j]:
                    cost[i][j] = c
                    last[i][j] = k

    print(cost)
    print(last)

if __name__ == "__main__":
    d = [30, 1, 40, 10, 25]
    matrix_order(d)