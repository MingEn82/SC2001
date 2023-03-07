def recursive_choose(n, k):
    if n >= 0 and k == 0:
        return 1
    elif n == 0 and k > 0:
        return 0

    return recursive_choose(n-1, k-1) + recursive_choose(n-1, k)

if __name__ == "__main__":
    print(recursive_choose(100, 50))