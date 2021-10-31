input_ = input().split()
n_days = int(input_[0])
sumTime = int(input_[1])
hrs_reg = [[int(i) for i in input().split()] for _ in range(int(n_days))]


def check_nums(hrs_reg_, sumTime_):
    return sum([i[0] for i in hrs_reg_]) > sumTime_ or sum([i[1] for i in hrs_reg_]) < sumTime_


if check_nums(hrs_reg, sumTime):
    print("NO")
else:
    print("YES")

    next_day = 1
    nums = []
    for i in range(len(hrs_reg)):
        for x in range(hrs_reg[i][0], hrs_reg[i][1] + 1):
            if not check_nums(hrs_reg[i + 1:], sumTime - x):
                sumTime -= x
                nums.append(str(x))
                break

    print(' '.join(nums))
