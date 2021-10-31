input_ = int(input())
for i in range(2, input_, 2):
    for x in range(2, input_, 2):
        if i + x == input_:
            print("YES")
            quit()
print("NO")

    