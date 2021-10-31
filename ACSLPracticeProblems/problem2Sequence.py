def return_value(position):
    value = [1, 2]
    for i in range(2, position):
        value.append(i + 1 + value[-1] - value[-2])
    return value[- 1]


while True:
    print(return_value(int(input("Enter a position: "))))
