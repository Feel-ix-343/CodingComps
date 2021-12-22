n_of_cows = int(input())
cows = input()
discarded = 0

for i in range(3, n_of_cows + 1):
    for x in range(n_of_cows - i + 1):
        partition = set(cows[x:x+i])
        if ()