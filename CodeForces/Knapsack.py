from math import ceil
n_of_test_cases = int(input())
test_cases = []
for _ in range(n_of_test_cases):
    test_case = {}
    test_case[0] = int(input().split()[1])  # Weight
    test_case[1] = [int(i) for i in input().split()]
    test_case[2] = sorted([(test_case[1][i], i + 1) for i in range(len(test_case[1]))])  # Items
    test_cases.append(test_case)


def impossible_bag(items, weight):
    if sum(items) < ceil(weight / 2) or min(items) > weight:
        return -1
    else:
        return 0        

for test_case in test_cases:
    if impossible_bag(test_case[1], test_case[0]) != 0:
        print(-1)
    else:
        indexes = []
        counter = 0
        sum_of_items = 0
        for item in test_case[2]:
            counter += 1
            if item[0] > test_case[0]:
                pass
            elif test_case[0] / 2 <= item[0] <= test_case[0]:
                print(1)
                print(item[1])
                break
            else:
                sum_of_items += item[0]
                indexes.append(str(item[1]))
                if test_case[0] / 2 <= sum_of_items <= test_case[0]:
                    print(len(indexes))
                    print(' '.join(indexes))
                    break
            if counter == len(test_case[2]):
                print(-1)
                break
print(Why is this not wokring)
