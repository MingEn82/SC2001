import numpy as np

def knapsack(weights:list, values:list, C:int, n:int) -> int:
    # Initialise dictionary
    profit = np.zeros((C+1, n+1), dtype=int)

    # Iterates through each capacity limit up to C
    # For each capacity, find maximum profit
    for c in range(1,C+1):
        for i in range(1,n+1):
            profit[c][i] = profit[c][i-1]
            if weights[i-1] <= c:
                profit[c][i] = max(profit[c][i], profit[c-weights[i-1]][i-1]+values[i-1])

    print(profit)
    
    return profit[C][n]

if __name__ == "__main__":
    weights = [4, 6, 8, 6]
    values = [7, 6, 9, 5]
    C = 20
    n = len(weights)
    print(knapsack(weights, values, C, n))