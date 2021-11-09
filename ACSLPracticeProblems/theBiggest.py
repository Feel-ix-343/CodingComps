from functools import reduce


def function(number, target_):
    sums = [sum([int(i) for i in number])]
    for i in range(2, len(target_) + 1):
        for x in range(len(number) - i + 1):
            starter = sum([int(number[i]) for i in range(x)])
            grouped = int(number[x: x + i])
            if len(number) / len(target_) > 1:
                nums_left_list = [number[i] for i in range(x + i, len(number))]
                nums_left = sum(map(lambda o: int(o), nums_left_list))
                if starter + grouped + nums_left > int(target_):
                    continue
                else:
                    sums.append(starter + grouped + function(''.join(nums_left_list), str(int(target_) - starter - grouped)))
            elif len(number) / len(target_) == 1:
                sums.append(grouped)
    closest = reduce(lambda j, k: j if int(target_) - j < int(target_) - k else k, sums)
    return closest


# n_of_lines = int(input("Enter # of lines: "))
n_of_lines = 5
# lines = [input("Enter Number, and target number separated by ', ': ").split(", ") for _ in range(n_of_lines)]
lines = [["1234", '127']]

for line in lines:
    print(function(line[0], line[1]))

array = list("1234")
n = len(array)

for partition_index in range(2 ** (n-1)):

    # current partition, e.g., [['a', 'b'], ['c', 'd', 'e']]
    partition = []

    # used to accumulate the subsets, e.g., ['a', 'b']
    subset = []

    for position in range(n):

        subset.append(array[position])

        # check whether to "break off" a new subset
        if 1 << position & partition_index or position == n-1:
            partition.append(subset)
            subset = []

    print(partition)