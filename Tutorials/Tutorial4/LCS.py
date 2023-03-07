import numpy as np

def lcs(s1, s2):
    cost = np.zeros(shape=(len(s1)+1,len(s2)+1))
    h = np.empty(shape=(len(s1)+1,len(s2)+1), dtype=str)
    for i in range(len(s1)):
        for j in range(len(s2)):
            if s1[i] == s2[j]:
                cost[i+1][j+1] = cost[i][j] + 1
                h[i+1][j+1] = "\\"
            elif cost[i][j+1] >= cost[i+1][j]:
                cost[i+1][j+1] = cost[i][j+1]
                h[i+1][j+1] = "|"
            else:
                cost[i+1][j+1] = cost[i+1][j]
                h[i+1][j+1] = "-"
    print(cost)
    print(get_lcs(h, s1, s2))

def get_lcs(h, s1, s2):
    lcs = ""
    len_s1 = len(s1)
    len_s2 = len(s2)
    while len_s1 > 0 and len_s2 > 0:
        if h[len_s1][len_s2] == "\\":
            lcs = s1[len_s1-1] + lcs
            len_s1 -= 1
            len_s2 -= 1
        elif h[len_s1][len_s2] == "|":
            len_s1 -= 1
        else:
            len_s2 -= 1
    return lcs


if __name__ == "__main__":
    lcs("CAGAG", "ACTGG")
