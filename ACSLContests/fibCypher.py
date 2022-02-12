def fibCypher(num1, num2, key, msg):
    fibSequence = [num1, num2]
    for i in range(2, 20): 
        fibSequence.append(fibSequence[i - 2] + fibSequence[i - 1])
    print(fibSequence)

fibCypher(1, 7, 1, 1)


