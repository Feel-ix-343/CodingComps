def fibCypher(num1, num2, key, msg):
    fibSequence = [num1, num2]
    for i in range(2, 20): 
        fibSequence.append(fibSequence[i - 2] + fibSequence[i - 1])
    key = ord(key)
    out = []
    for index, char in enumerate(msg):
        keyMult = (key - 97 + fibSequence[index]) % 26 + 97
        print(key)
        print(fibSequence[index])
        print(keyMult)
        print()
        out.append(ord(char) + 3 * keyMult)
    return " ".join(map(str, out))

print(fibCypher(3, 7, 'h', "ACSL c2"))


