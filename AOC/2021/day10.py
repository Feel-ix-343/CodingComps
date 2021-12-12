from collections import deque
f = open("day10Input.txt", "r")
score = 0
chunkOpenClose = {'(': ')', '[': ']', '{': '}', '<': '>'}
chunkValues = {')': 3, ']': 57, '}': 1197, '>': 25137}
for line in f.readlines():
    line = line.strip()
    opens = deque()
    for char in line:
        if char in chunkOpenClose.keys():
            opens.append(char)
        else:
            recentOpen = opens.pop()
            if char != chunkOpenClose[recentOpen]:
                score += chunkValues[char]
                break

print(score)
f.close()
