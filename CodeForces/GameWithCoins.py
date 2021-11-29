n = int(input())
boxes_ = [int(i) for i in input().split()]
count = 0

def good_func(boxes, x):
    count = 0
    while not all([i == 0 for i in boxes]):
        x_key = []
        for index, i in enumerate(x):
            x_key.append([0, i])
            for box in boxes:
                if i == box or i * 2 == box or i * 2 + 1 == box:
                    x_key[index][0] += 1
        if # make it recursive !! and then check, if it is too slow, go back to drawing board, this should get all good
            #possibilities, if it doesnt then back to the drawing board do tests
        best_x_val = max(x_key)[1]
        for box_index, num in enumerate(boxes):
            if num == best_x_val or num == best_x_val * 2 or num == best_x_val * 2 + 1:
                boxes[box_index] -= 1
        count += 1
    return count

if (max(boxes) - 1) // 2 > (n - 1) // 2 or n < 3:
    count = -1
else:
    x = list(range(1, (n - 1) // 2 + 1))
    count = good_func(boxes_, x)
print(count)
