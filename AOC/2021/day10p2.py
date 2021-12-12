f = open("day10Input.txt", 'r')
chunkOpenClose = {'(': ')', '[': ']', '{': '}', '<': '>'}
starterVals = {'(': 1, '[': 2, '{': 3, '<': 4}
scores = []
for line in f.readlines():
    line = line.strip()
    chunks = []
    for char in line:
        currupted = False
        if char in chunkOpenClose.keys():
            chunks.append(char)
        else:
            starter = chunks.pop(-1)
            if char != chunkOpenClose[starter]:
                currupted = True
                break
    if currupted != True:
        lineScore = 0
        for starter in chunks[::-1]:
            lineScore *= 5
            lineScore += starterVals[starter]
        scores.append(lineScore)
    
print(sorted(scores)[len(scores) // 2])
        
    

            