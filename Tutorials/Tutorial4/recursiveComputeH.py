def recursive_compute_H(n):
    if n <= 0:
        return 1
    h = 0
    if n % 2 == 1:
        h += recursive_compute_H(n-1)
        n -= 1
    while n > 0:
        h += recursive_compute_H(n-2)
        n -= 2
    return h
    

if __name__ == "__main__":
    print(recursive_compute_H(8))