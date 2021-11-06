from functools import reduce


def f(number, target_):
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
                    sums.append(starter + grouped + f(''.join(nums_left_list), str(int(target_) - starter - grouped)))
            elif len(number) / len(target_) == 1:
                sums.append(grouped)
    closest = reduce(lambda j, k: j if int(target_) - j < int(target_) - k else k, sums)
    return closest


n_of_lines = int(input("Enter # of lines: "))
lines = [input("Enter Number, and target number separated by ', '").split(", ") for _ in range(n_of_lines)]

for line in lines:
    print(f(line[0], line[1]))
