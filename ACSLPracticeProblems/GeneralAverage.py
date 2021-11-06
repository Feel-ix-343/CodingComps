nums = int(input("Enter num of nums: "))
lst = []
for _ in range(nums):
    input_ = int(input("Enter a value: "))
    if input_ in range(0, 101):
        lst.append(input_)
    else:
        input_ = int(input("Enter another value: "))
print(sum(lst) // len(lst))


def test():
    print("Test")
