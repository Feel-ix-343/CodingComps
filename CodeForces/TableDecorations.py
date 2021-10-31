input_ = input().split()
nums = {'r': int(input_[0]), 'g': int(input_[1]), 'b': int(input_[2])}
tables = 0


def count_0():
    return list(nums.values()).count(0)


while sum(nums.values()) >= 3 and count_0() < 2:
    if nums['r'] == nums['g'] == nums['b']:
        tables += nums['r']
        break
    elif count_0() == 1:
        if sum(nums.values()) > 3 and all(i > 2 or i == 0 for i in nums.values()):
            nums_sorted = sorted([(i[1], i[0]) for i in nums.items() if i[1] != 0], reverse=True)
            difference = nums_sorted[0][0] - nums_sorted[1][0]
            if difference <= 2:
                new_table_pairs = nums_sorted[1][0] // 3
                remainder_of_min = nums_sorted[1][0] % 3
                nums[nums_sorted[0][1]] -= new_table_pairs * 3
                nums[nums_sorted[1][1]] = remainder_of_min
                tables += new_table_pairs * 2
            elif difference < nums_sorted[0][0] // 2:
                """y = -2x + max
                   (-)y = (-)-x (-)+ middle
                   0 = -x + max - middle
                   x = max - middle"""
                nums[nums_sorted[0][1]] -= difference * 2
                nums[nums_sorted[1][1]] -= difference
                tables += difference
            else:
                tables += nums_sorted[1][0]
                break

        elif 2 in nums.values():
            values = list(nums.values())
            values.remove(0)
            max_ = max(values)
            min_ = min(values)
            possible_tables = max_ // 2
            if possible_tables >= 2:
                tables += 2
            else:
                tables += 1
            break

        elif 1 in nums.values():
            tables += 1
            break

    else:
        nums_sorted = sorted([(i[1], i[0]) for i in nums.items()], reverse=True)
        potential = nums_sorted[0][0] // 2
        remainder_of_max = nums_sorted[0][0] % 2

        actual = nums_sorted[1][0] + nums_sorted[2][0]

        if potential >= actual:
            nums[nums_sorted[0][1]] -= actual * 2
            nums[nums_sorted[1][1]] = 0
            nums[nums_sorted[2][1]] = 0
            tables += actual
        elif potential < actual // 3 or nums_sorted[0][0] - nums_sorted[1][0] < nums_sorted[1][0] - nums_sorted[2][0]:#
            nums['r'] -= nums_sorted[2][0]
            nums['g'] -= nums_sorted[2][0]
            nums['b'] -= nums_sorted[2][0]
            tables += nums_sorted[2][0]
        else:
            nums[nums_sorted[0][1]] = remainder_of_max
            nums[nums_sorted[1][1]] -= potential // 2
            nums[nums_sorted[2][1]] -= potential // 2 + potential % 2

            if nums[nums_sorted[2][1]] < 0:
                nums[nums_sorted[1][1]] += nums[nums_sorted[2][1]]
                nums[nums_sorted[2][1]] = 0
                #

            tables += potential

print(tables)
