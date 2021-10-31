n_of_inputs = int(input())
words = [input() for i in range(n_of_inputs)]
for word in words:
    if len(word) > 10:
        print(word[0] + str(len(word[1:-1])) + word[-1])
    else:
        print(word)
        