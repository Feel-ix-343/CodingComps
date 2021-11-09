sequence = [1, 1]
i = 1
while i < 25:
    sequence.append(sequence[-1] + sequence[-2])
    i += 1

print(sequence)
print(list(map(lambda x: bin(x), sequence)))