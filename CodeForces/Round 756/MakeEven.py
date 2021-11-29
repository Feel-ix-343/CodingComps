n_of_test_cases = int(input())
nums = [input() for _ in range(n_of_test_cases)]

for num in nums:
    if not any([int(i) % 2 == 0 for i in num]):
        print(-1)
    elif int(num) % 2 == 0:
        print(0)
    elif int(num[0]) % 2 == 0:
        print(1)
    else:
        print(2)

