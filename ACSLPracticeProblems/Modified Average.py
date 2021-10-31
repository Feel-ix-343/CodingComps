nums = int(input())
lst = []
for _ in range(nums):
    input_ = int(input("Enter a value: "))
    if input_ in range(0, 101):
        lst.append(input_)
    else:
        input_ = int(input("Enter another value: "))

print(sum(lst[1:]) // (len(lst) - 1))

