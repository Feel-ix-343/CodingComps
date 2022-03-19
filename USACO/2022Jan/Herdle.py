guess = list(input() + input() + input())
ans = list(input() + input() + input())

g = 0
y = 0

for i in range(len(guess)):
    if ans[i] == guess[i]:
        g += 1
        guess[i] = 0
    else:
        try:
            prevTest = -1
            while True:
                index = guess.index(ans[i], prevTest + 1)
                if ans[index] == guess[index]:
                    prevTest = index
                    continue
                y += 1
                guess[index] = 0
                break
        except ValueError:
            continue

print(g)
print(y)

